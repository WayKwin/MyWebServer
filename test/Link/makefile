.PHONEY:clean
link:main.o List.o ListNode.o
	g++  main.o List.o ListNode.o -o link
.o:.c
	g++ -c $^ -o $@
clean:
	rm -rf *.o link

