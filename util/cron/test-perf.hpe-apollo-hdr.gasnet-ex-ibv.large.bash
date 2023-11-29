#!/usr/bin/env bash
#
# Run performance tests on an HPE Apollo

CWD=$(cd $(dirname $0) ; pwd)

export CHPL_TEST_PERF_SUBDIR="hpe-apollo"
export CHPL_TEST_PERF_CONFIG_NAME='16-node-apollo-hdr'

source $CWD/common-perf.bash

export CHPL_NIGHTLY_TEST_CONFIG_NAME="perf.hpe-apollo-hdr.gasnet-ex-ibv.large"

source $CWD/common-hpe-apollo.bash
source $CWD/common-perf-hpe-apollo-hdr.bash
perf_hpe_apollo_args="-performance-configs gn-ibv-large:v,gn-ex-ibv-large:v -perflabel ml- -startdate 08/28/23"

export GASNET_PHYSMEM_MAX="0.90"

# Test GASNet EX
export CHPL_GASNET_VERSION=ex

nightly_args="${nightly_args} -no-buildcheck"
perf_args="-performance-description gn-ex-ibv-large -numtrials 1 -sync-dir-suffix gex"

$CWD/nightly -cron ${perf_args} ${perf_hpe_apollo_args} ${nightly_args}
