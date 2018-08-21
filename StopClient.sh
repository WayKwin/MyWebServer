PID=`ps -elf | grep Stress_Client | awk '{if(NR>=1 && NR<= 1) print $4}'`
if [ -z $PID ]
then
  echo "Stress_Client haven't started"
  exit 1
fi
kill -9 $PID
