#!/bin/bash

#USR=`whoami`
PID=`ps -elf | grep WK_Http | awk '{if(NR>=1 && NR<= 1) print $4}'`
#echo ${PID}
if [ -z $PID ]
then
  echo "WK_Http haven't started"
  exit 1
fi
kill -9 $PID
