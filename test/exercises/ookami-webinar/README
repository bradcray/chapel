Pointers to other places
========================
If you're looking for...
...codes or benchmarks from the slides, see:   slideExamples/README.md
...hands-on exercises, see:                    handsOn/README.md

For general tips, read on!


Chapel Documentation
====================
* Online documentation is here: https://chapel-lang.org/docs/ 

* The primers can be particularly valuable for learning a concept:
    https://chapel-lang.org/docs/primers/index.html 
  o These are also available from a Chapel release
    - in ‘$CHPL_HOME/examples/primers/’
    - or ‘$CHPL_HOME/test/release/examples/primers/’ if you clone from GitHub


Debugging via writeln()s
========================
* When debugging, almost anything in Chapel can be printed out with
  ‘writeln(expr1, expr2, expr3);’

* Types can be printed after being cast to strings
  e.g. ‘writeln(”Type of “, expr, “ is “, expr.type:string);’

* A quick way to print a bunch of values out clearly is to print a
  tuple made up of them ‘writeln((x, y, z));’


Performance Runs?
=================
* There's no need to do performance runs or timings today, but if you do...
  o Once your code is correct, before doing any performance timings,
    be sure to re-compile with ‘--fast’
    - Turns on optimizations, turns off safety checks, slows down
      compilation, speeds up execution significantly

  o Then, when you go back to making modifications, be sure to stop
    using `--fast` in order to turn checks back on


Syntax Highlighting
===================
* For vim / emacs users, syntax highlighters are in $CHPL_HOME/highlight
  o these are imperfect, but typically better than nothing
  o Emacs MELPA users may want to use the chapel-mode available there
    (better in most respects, weird in a few others)


Using Chapel on Ookami
======================
* Chapel is pre-installed on Ookami, thanks to Eva Siegmann and Tony Curtis
  o Installed at /etc/modulefiles/aarch64/chapel/1.25.1
  o Available via normal module commands:
    'module load chapel'

* Sample programs available in:
  o $CHPL_HOME/examples/hello*.chpl
  o $CHPL_HOME/examples/primers/
  o $CHPL_HOME/examples/benchmarks/
  o (and others, though these are probably most useful)

* Compile and run as shown in previous examples:
  o 'chpl myProgram.chpl'
  o 'myProgram -nl 4'


Installing Chapel on Your Own System
====================================
* Often, getting started with Chapel on a supercomputer can be annoying
  o Environment not as set up to your liking as your primary machine
  o Shared resource, queueing times, etc.

* You’re welcome to install Chapel on your laptop or favorite system if allowed
  o Mac homebrew (Catalina or later) / Linuxbrew:
    ‘brew install chapel’  (supports single-locale runs only)
  o Docker: See https://chapel-lang.org/install-docker.html 
  o Linux / *nix: Install and build from source
    see https://chapel-lang.org/download.html 
  o Windows: Use Linux bash shell / Windows Subsystem for Linux
    (and see previous entry)

* Developing a Chapel program on a laptop and then running it on a
  supercomputer is a common practice
  o And Chapel’s global-view tends to make it easy:
    - almost always runs correctly
    - typically not too difficult to get using multiple locales,
      particularly for data-parallel codes
    - optimizing it can take more effort...


Need Help?
==========
* We’ll be handling Q&A today both live and via #chapel-webinar on the
  IACS Slack channel
  - Members of the Chapel team besides myself will be on Slack to
    answer questions, screen share, etc.

* After today, help is available via:
  o Stack Overflow: for questions that will likely be valuable to others
    (tag your question with ‘chapel’)
  o Discourse: our community web forum / mailing list technology
  o Gitter: our community real-time chat technology
  o GitHub issues: for filing bug reports, feature requests, etc.


