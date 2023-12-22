
CC=g++ -std=c++11 -g
exe=asm5

run: linked_list.o test_linked_list.o
	$(CC) linked_list.o test_linked_list.o -o run

linked_list.o: linked_list.cpp linked_list.h
	$(CC) -c linked_list.cpp

test_linked_list.o: test_linked_list.cpp
	$(CC) -c test_linked_list.cpp

clean:
	rm -f *.o $(exe)
