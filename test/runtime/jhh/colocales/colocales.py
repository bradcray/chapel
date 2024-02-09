#!/usr/bin/env python3

"""
Co-locale tests
Usage: ./colocales.py [options] compiler
The -v flag prints verbose output, the -f flag will cause testing to stop when
the first test fails.
"""

import unittest
import subprocess
import os
import sys
import time
import shutil

if not 'CHPL_HOME' in os.environ:
    print('CHPL_HOME is not set')
    sys.exit(1)

import sub_test
import printchplenv


verbose = False
skipReason = None

def runCmd(cmd, env=None, check=True):
    if type(cmd) is str:
        cmd = cmd.split()
    if env is None:
        proc = subprocess.run(cmd, text=True, check=check,
            stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    else:
        # Make sure environment variables are strings, otherwise you get
        # an exception deep in the callstack.
        for (key, value) in env.items():
            if type(value) != str:
                raise Exception('Environment variable "%s" is not a string.' %
                                key)
        proc = subprocess.run(cmd, text=True, check=check, env=env,
            stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    return proc.stdout

def skipif():
    global skipReason
    global launcher, comm

    # Get the Chapel configuration
    printchplenv.compute_all_values()
    # strip the padding printchplenv puts on some of the keys
    env = {k.strip():v for k,v in printchplenv.ENV_VALS.items()}

    # Verify Chapel configuration

    # Tests requires hwloc
    if env.get('CHPL_HWLOC', 'none') == 'none':
        skipReason = "CHPL_HWLOC == none"
        return

    # Don't test in multi-locale configurations
    if env.get('CHPL_COMM', 'none') != 'none':
        skipReason = "CHPL_COMM != none"
        return

def stringify(lst):
    return " ".join([str(i) for i in lst])

class TestCases(object):
    """
    This outer class prevents the unittest framework from running the
    test cases in TestCase.
    """
    class TestCase(unittest.TestCase):
        """
        This class defines utility functions and the test cases (which start
        with 'test_'). The tests in this class are not run directly, but
        instead are run from subclasses that use different machine
        topologies.
        """
        def setUp(self):
            if skipReason is not None:
                self.skipTest(skipReason)
            self.env = os.environ.copy()

        def runCmd(self, cmd, env=None):
            if env is None:
                env = self.env
            output = runCmd(cmd, env=env, check=False);
            return output

        # Returns a list of cores in the specified partition
        def getCores(self,  index, partitions):
            if index == "all":
                return sorted([x for lst in [self.getCores(i, partitions)
                              for i in range(0,partitions)] for x in lst])
            else:
                coresPerPartition = int((self.cores * self.sockets) /
                                        partitions)
                return [i + (index * coresPerPartition)
                                for i in range(0,coresPerPartition)]

        # Returns a list of cores in the specified socket.
        def getSocketCores(self, socket):
            return self.getCores(socket, self.sockets)

        # Returns a list of cores in the specified NUMA domain
        def getNumaCores(self, numa):
            return self.getCores(numa, self.sockets * self.numas)

        # Returns a list of threads (PUs) in the specified partition
        def getThreads(self, index, partitions):
            if index == "all":
                return sorted([x for lst in [self.getThreads(i, partitions)
                            for i in range(0,partitions)] for x in lst])
            cores = self.getCores(index, partitions)
            threads = []
            for t in range(0, self.threads):
                threads += [cores[i] + (t * self.sockets * self.cores)
                            for i in range(0, len(cores))]
            return threads

        # Returns a list of threads in the specified socket
        def getSocketThreads(self, socket):
            return self.getThreads(socket, self.sockets)

        # Returns a list of threads in the specified NUMA domain
        def getNumaThreads(self, numa):
            return self.getThreads(numa, self.sockets * self.numas)

        def test_00_base(self):
            """
            One locale, should have access to all cores and threads and use
            the suggested NIC.
            """
            output = self.runCmd("./colocales -N %s" % self.nics[0])
            cpus = stringify(self.getSocketCores("all"))
            self.assertIn("Physical CPUs: %s\n" % cpus, output)
            cpus = stringify(self.getSocketThreads("all"))
            self.assertIn("Logical CPUs: %s\n" % cpus, output)
            self.assertIn("NIC: " + self.nics[0], output)

        def test_01_use_another_NIC(self):
            """
            One locale, should have access to all cores and threads and use
            another NIC when it is suggested.
            """
            if (len(self.nics) == 1):
                self.skipTest("only one NIC")
            output = self.runCmd("./colocales -N %s" % self.nics[1])
            self.assertIn("NIC: " + self.nics[1], output)

        def in_socket_test(self, socket, nic):
            """
            Locale in socket should use cores and threads in that socket and
            the closest NIC, no matter which NIC is suggested.
            """
            output = self.runCmd("./colocales -r %d -n %d -N %s" %
                             (socket, self.sockets, nic))
            cpus = stringify(self.getSocketCores(socket))
            self.assertIn("Physical CPUs: %s\n" % cpus, output)
            cpus = stringify(self.getSocketThreads(socket))
            self.assertIn("Logical CPUs: %s\n" % cpus, output)
            self.assertIn("NIC: " + self.nicForSocket[socket], output)

        def test_02_suggest_nic_in_socket(self):
            """
            Locale should use NIC in its socket when that is suggested.
            """
            if not hasattr(self, 'nicForSocket'):
                self.skipTest("NICs are not in sockets")
            for i in range(0, self.sockets):
                with self.subTest(i=i):
                    self.in_socket_test(i, self.nicForSocket[i])

        def test_03_suggest_nic_in_other_socket(self):
            """
            Locale should use NIC in its socket when a different NIC is
            suggested.
            """
            if not hasattr(self, 'nicForSocket'):
                self.skipTest("NICs are not in sockets")
            if (len(self.nics) == 1):
                self.skipTest("only one NIC")
            for i in range(0, self.sockets):
                with self.subTest(i=i):
                    self.in_socket_test(i,
                                   self.nicForSocket[(i+1)%self.sockets])

        def in_numa_test(self, numa, nic):
            """
            Locale in NUMA should use cores and threads in that NUMA and
            the closest NIC, no matter which NIC is suggested.
            """
            numas = self.numas * self.sockets
            output = self.runCmd("./colocales -r %d -n %d -N %s" %
                             (numa, numas, nic))
            cpus = stringify(self.getNumaCores(numa))
            self.assertIn("Physical CPUs: %s\n" % cpus, output)
            cpus = stringify(self.getNumaThreads(numa))
            self.assertIn("Logical CPUs: %s\n" % cpus, output)
            self.assertIn("NIC: " + self.nicForNuma[numa], output)

        def test_04_suggest_nic_in_numa(self):
            """
            Locale should use NIC in its NUMA when that is suggested.
            """
            if not hasattr(self, 'nicForNuma'):
                self.skipTest("NICs are not in NUMAs")
            for i in range(0, self.numas * self.sockets):
                with self.subTest(i=i):
                    self.in_numa_test(i, self.nicForNuma[i])

        def test_05_suggest_nic_in_other_numa(self):
            """
            Locale should use NIC in its NUMA when a different NIC is
            suggested.
            """
            if not hasattr(self, 'nicForNuma'):
                self.skipTest("NICs are not in NUMAs")
            if (len(self.nics) == 1):
                self.skipTest("only one NIC")
            numas = self.numas * self.sockets
            for i in range(0, numas):
                with self.subTest(i=i):
                    self.in_numa_test(i, self.nicForNuma[(i+1)%numas])

"""
These classes represent different machine topologies based on real machines.
The topologies are stored in the XML files. We could extract the number of
sockets, cores, etc., from those files, but for now we just hard-code that
information because there are only a few configurations.
"""

class Ex2Tests(TestCases.TestCase):
    """
    HPE Cray EX. Two sockets, four NUMA domains per socket, 64 cores per
    socket, two threads per core, and one NIC per socket.
    """
    def setUp(self):
        super().setUp()
        self.env['HWLOC_XMLFILE'] = 'ex2.xml'
        self.sockets = 2
        self.numas = 4
        self.cores = 64
        self.threads = 2
        self.nics= ['0000:21:00.0', '0000:a1:00.0']
        self.nicForSocket = ['0000:21:00.0', '0000:a1:00.0']
        self.nicForNuma = ['0000:21:00.0', '0000:21:00.0', '0000:21:00.0',
                           '0000:21:00.0', '0000:a1:00.0', '0000:a1:00.0',
                           '0000:a1:00.0', '0000:a1:00.0']

    def test_10_generalized(self):
        """
        16 co-locales should each have 8 cores
        """
        for i in range(0, 16):
            with self.subTest(i=i):
                output = self.runCmd("./colocales -r %d -n %d -N %s" %
                                     (i, 16, self.nics[0]))
                cpus = stringify([i*8+j for j in range(0, 8)])
                self.assertIn("Physical CPUs: %s\n" % cpus, output)

    def test_11_not_enough_cores(self):
        """
        Must have at least one core per locale
        """
        output = self.runCmd("./colocales -r 0 -n 129")
        self.assertIn("error: Cannot run 129 co-locales on 128 cores.\n",
                      output)

    def test_12_leftover_cores(self):
        """
        Warn about unused cores
        """
        output = self.runCmd("./colocales -r 0 -n 17")
        self.assertIn("warning: 9 cores are unused\n", output);

class Hpc6aTests(TestCases.TestCase):
    """
    AWS hpc6a.48xlarge instance. Two sockets, two NUMA domains per socket, 48
    cores per socket, one thread per core, and one NIC not in a socket.
    domains.
    """
    def setUp(self):
        super().setUp()
        self.env['HWLOC_XMLFILE'] = 'hpc6a.48xlarge.xml'
        self.sockets = 2
        self.numas = 2
        self.cores = 48
        self.threads = 1
        self.nics= ['0000:00:06.0']
        self.nicForSocket = ['0000:00:06.0', '0000:00:06.0']
        self.nicForNuma = ['0000:00:06.0', '0000:00:06.0', '0000:00:06.0',
                           '0000:00:06.0']

class M6inTests(TestCases.TestCase):
    """
    AWS m6in-dy-m6in32xlarge instance. Two sockets, one NUMA domain per
    socket, 32 cores per socket, one thread per core, and two NICs not in
    sockets.
    """
    def setUp(self):
        super().setUp()
        self.env['HWLOC_XMLFILE'] = 'm6in-dy-m6in32xlarge.xml'
        self.sockets = 2
        self.numas = 1
        self.cores = 32
        self.threads = 2
        self.nics= ['0000:00:06.0', '0000:00:08.0']

    def test_10_socket_unique_nics(self):
        """
        In this topology the NICs are not in sockets. Test that each locale
        gets a unique NIC.
        """
        nics = []
        for i in range(0, self.sockets):
            with self.subTest(i=i):
                output = self.runCmd("./colocales -r %d -n %d -N %s" %
                                     (i, self.sockets, self.nics[0]))
                for line in output.split('\n'):
                    if line.startswith("NIC:"):
                        nic = line.split()[1]
                        self.assertIn(nic, self.nics)
                        self.assertNotIn(nic, nics)
                        nics.append(nic)
                        break

    def test_11_numa_unique_nics(self):
        """
        In this topology the NICs are not in NUMAs. Test that each locale
        gets a unique NIC.
        """
        numas = self.numas * self.sockets
        nics = []
        for i in range(0, numas):
            output = self.runCmd("./colocales -r %d -n %d -N %s" %
                                 (i, numas, self.nics[0]))
            for line in output.split('\n'):
                if line.startswith("NIC:"):
                    nic = line.split()[1]
                    self.assertIn(nic, self.nics)
                    self.assertNotIn(nic, nics)
                    nics.append(nic)
                    break

def main(argv):
    global verbose

    startTime=time.time()
    failfast = False
    if "-f" in argv or "--force" in argv:
        failfast = True
        try:
            argv.remove("-f")
            argv.remove("--force")
        except:
            pass
    if "-v" in argv or "--verbose" in argv:
        verbose = True

    skipif()

    if len(argv) < 2:
        print('usage: %s COMPILER [options]' % argv[0])
        sys.exit(0)

    compiler = argv[1]
    os.environ['CHPL_COMPILER'] = compiler
    del argv[1]
    baseDir = sub_test.get_chpl_base(compiler)
    homeDir = sub_test.get_chpl_home(baseDir)
    testDir = sub_test.get_test_dir(homeDir)
    localDir = sub_test.get_local_dir(testDir)
    name = os.path.join(localDir, argv[0])
    base = os.path.splitext(os.path.basename(argv[0]))[0]

    sub_test.printStartOfTestMsg(time.localtime())
    sub_test.printTestName(name)

    if skipReason is None:
        if verbose:
            print("Building test harness")
        runCmd("make clean")
        runCmd("make")
    if verbose:
        print("Running tests")
        verbosity=2
    else:
        verbosity=1
    prog = unittest.main(argv=argv, failfast=failfast, exit=False,
                         verbosity=verbosity)


    """
    Produce output that start_test can parse. To start_test this is a single
    test. Report report success if all tests succeeded, an error if any test
    failed, and nothing if all tests were skipped.
    """

    elapsedTime = time.time() - startTime

    if len(prog.result.skipped) > 0:
        sub_test.printSkipping(name, skipReason)
        print("Skipped %d tests in %s" % (len(prog.result.skipped), name))
    if len(prog.result.skipped) != prog.result.testsRun:
        if len(prog.result.errors) > 0 or len(prog.result.failures) > 0:
            print("[Error running tests in %s]" % name)
        else:
            print("[Success matching tests in %s]" % name)
    sub_test.printEndOfTestMsg(name, elapsedTime)
    sub_test.cleanup(base, False)
    runCmd("make clean")
    sub_test.print_elapsed_sub_test_time(name, elapsedTime)

if __name__ == '__main__':
    main(sys.argv)

