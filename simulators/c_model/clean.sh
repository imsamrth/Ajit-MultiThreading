#!/usr/bin/env bash

# must run this script from its absolute position

_CWD="`pwd`";
_OUT_BUILD_FILE="$_CWD/build.log";
_OUT_CLEANUP_FILE="$_CWD/cleanup.log";

function AND() {
  # Executes the given command. Exits on error.
  # Takes three arguments
  #  $1 Quoted Command
  #  $2 Error msg (optional)
  #  $3 Exit Code (optional)
  echo -e "\nAND: START:" "$1" "\n";
  bash -c "$1";
  local _EXITCODE=$?;
  if [[ $_EXITCODE != "0" ]]; then
    echo -e "AND: ERROR:($_EXITCODE): '$1'\n$2";
    exit $3;
  else
    echo -e "AND:  DONE: $1";
  fi
}

{
  echo -e "Log file: $_OUT_CLEANUP_FILE \n"; sleep 1;

  # invariant check: check if the the script is run from its location
  DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )";
  if [[ $DIR != "`pwd`" ]]; then
    echo "AD: Must run this script from its directory as './...'";
    exit;  # if not then exit
  fi

  if [[ -z $AHIR_RELEASE ]]; then
    echo "ERROR: Please set the env variable \$AHIR_RELEASE";
    echo "Find the file 'ahir_bashrc' and source it from its dir.";
    exit 1;
  fi

  # cd $AHIR_RELEASE;
  # source ./ahir_bashrc;

  # echo -e "\nCleaning AJIT_C_REF_MODEL.\n";   sleep 1;
  # pushd ./code;
  # export AJIT_C_REF_MODEL="$(pwd)";
  # popd;

  echo -e "\nCleaning antlr3Cruntime\n";     sleep 1;
  pushd ./code/debugger/doval/antlr3Cruntime;
  AND "scons -c";
  popd;

  echo -e "\nCleaning doval\n";              sleep 1;
  pushd ./code/debugger/doval;
  AND "scons -c";
  popd;

  echo -e "\nCleaning console\n";            sleep 1;
  pushd ./code/console;
  echo -e "\ncwd: `pwd`\n";
  AND "scons -c";
  popd;

  echo -e "\nCleaning char_client_server\n"; sleep 1;
  pushd ./code/char_client_server;
  AND "scons -c";
  popd;

  echo -e "\nCleaning main c_model code\n";  sleep 1;
  pushd ./code;
  AND "scons -c";
  popd;

  rm $_OUT_BUILD_FILE;
} |& tee $_OUT_CLEANUP_FILE;

