#!/usr/bin/env bash
# execute or source this file

_IMG_NAME="ajit_build";
_AJIT_HOME="/home/ajit/ajit-toolchain";

docker exec -w $_AJIT_HOME -it $_IMG_NAME  /bin/bash;
