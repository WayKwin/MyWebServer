.PHONEY:clean
tree:tree.o
	gcc $< -o $@
.o:.c
	gcc -c $< -o $@
clean:
	rm -rf *.o tree
