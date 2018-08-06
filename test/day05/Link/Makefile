main:LinkNode.o Link.o main.o
	g++ Linknode.o Link.o main.o
LinkNode.o:LinkNode.cpp
	g++ -c LinkNode.cpp -o LinkNode.o -l ./LinkNode.h
Link.o:Link.cpp
	g++ -c Link.cpp -o Link.o -l ./Link.h
main.o:main.cpp
	g++ -c main.cpp -o main.o -l ./Link.h
