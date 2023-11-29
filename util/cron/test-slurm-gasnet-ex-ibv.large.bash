#!/usr/bin/env bash
#
# Multi-node, multi-locale testing on a cray-cs cluster with slurm-gasnetrun_ibv
# launcher:
# test gasnet-ex (segment large) against "examples"

CWD=$(cd $(dirname ${BASH_SOURCE[0]}) ; pwd)
source $CWD/common-slurm-gasnet-cray-cs.bash

export CHPL_NIGHTLY_TEST_CONFIG_NAME="slurm-gasnet-ex-ibv.large"

export CHPL_COMM_SUBSTRATE=ibv

# Test a GASNet compile using the large segment
export CHPL_GASNET_SEGMENT=large

# Test GASNet EX
export CHPL_GASNET_VERSION=ex

$CWD/nightly -cron -examples ${nightly_args} < /dev/null
