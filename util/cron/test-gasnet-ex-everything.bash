#!/usr/bin/env bash
#
# Test gasnet EX (segment everything) against full suite on linux64.

CWD=$(cd $(dirname $0) ; pwd)
source $CWD/common-gasnet.bash
source $CWD/common-localnode-paratest.bash

export CHPL_NIGHTLY_TEST_CONFIG_NAME="gasnet-ex-everything"

export GASNET_QUIET=Y

# Test a GASNet compile using the default segment (everything for linux64)
export CHPL_GASNET_SEGMENT=everything

# Test GASNet EX
export CHPL_GASNET_VERSION=ex

$CWD/nightly -cron $(get_nightly_paratest_args 8)
