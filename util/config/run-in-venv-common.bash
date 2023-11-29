#!/usr/bin/env bash
# Common support code to run a command in the Python virtual environment.
# Some scripts can use this as-is, others might want to perform other checks.

if [ -z "$CHPL_HOME" ]; then
  # compute the chpl home directory
  export CHPL_HOME=$(cd $(dirname $0) ; cd ..; cd ..; pwd)
fi

python=$($CHPL_HOME/util/config/find-python.sh)
chpldeps=$("$python" "$CHPL_HOME/util/chplenv/chpl_home_utils.py" --chpldeps)

if [ ! -e "$chpldeps" ]; then
  echo "chpl dependencies are missing - try make test-venv or make chapel-py-venv" 1>&2
  exit 1
fi

# include the dependencies
export PYTHONPATH="$chpldeps":$PYTHONPATH
