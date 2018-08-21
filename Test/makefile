LIBPATH = $(HOME)/third_part
INCLPATH = $(LIBPATH)/include
SRCPATH = $(LIBPATH)/lib
logtest:testlog.cpp
	g++  -I$(INCLPATH) -L$(SRCPATH)   $^ -o $@  -lglog -lpthread
