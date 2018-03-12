demo : test.o
	gcc -o demo test.o -I. -L. -lagorasdk
test.o : test.c
	gcc -c test.c -I.
clean :
	rm -f demo test.o
