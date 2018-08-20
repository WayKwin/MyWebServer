.PHONY:clean
WORKDIR=.
VPATH= ./src
CC=g++ 
F= -Wall -g -I$(WORKDIR)/incl/ -std=c++11 -D__DEBUG__
#LIBFLAG=.

BIN=WK_Http Stress_Clinet

all:$(BIN)


WK_Http:locker.o http_conn.o threadpool.o main.o log.o
	$(CC) -lpthread $^ -o $@
Stress_Clinet:stress_clint.o
	$(CC) -lpthread $^ -o $@

%.o:%.cpp
	$(CC) -c $(F)   $^  -o $@	 
clean:
	rm -rf *.o $(BIN) 
