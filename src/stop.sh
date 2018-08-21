#!/bin/bash
USR=`whoami`
PID=`ps -u $USR | grep Wk_Http | awk '{print $1}'`
if [ -z $pid ]
then
  echo "WK_Http haven't started"
  exit 1
fi
kill -9 $PID
