.PHONY:clean
WORKDIR=.
VPATH= ./src
CC=g++ 
THIRD_PART=$(HOME)/third_part
F= -Wall -g -I$(WORKDIR)/incl/ -I$(THIRD_PART)/include -std=c++11 -D__DEBUG__#-D__DAEMON__  

BIN=WK_Http Stress_Client

all:$(BIN)


WK_Http:locker.o http_conn.o threadpool.o main.o 
	$(CC) -lpthread  $^ -o $@ -L$(THIRD_PART)/lib -lglog
Stress_Client:stress_clint.o
	$(CC) -lpthread $^ -o $@

%.o:%.cpp
	$(CC) -c $(F)   $^  -o $@	 
clean:
	rm -rf *.o $(BIN) 
