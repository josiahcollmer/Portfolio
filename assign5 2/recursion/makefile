CC=g++ -std=c++11 -g
exe=asm5

run: recurse.o stairs.o
	$(CC) recurse.o stairs.o -o run

recurse.o: recurse.cpp
	$(CC) -c recurse.cpp

stairs.o: stairs.cpp stairs.h
	$(CC) -c stairs.cpp

clean:
	rm -f *.o $(exe)
