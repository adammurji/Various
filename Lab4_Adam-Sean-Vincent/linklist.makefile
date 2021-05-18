lists: main.o linklist.o
	gcc main.o linklist.o -o menu

main.o: main.c linklist.h
	gcc -c main.c

linklist.o: linklist.c linklist.h
	gcc -c linklist.c

clean:
	rm *.o *~
