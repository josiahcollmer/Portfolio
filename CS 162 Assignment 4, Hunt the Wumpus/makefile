

CC=g++ -std=c++11 -g
exe=asm4

# Complete the makefile
# Your code here: 

run: main.o game.o room.o event.o bats.o gold.o stalactites.o wumpus.o player.o
	$(CC) main.o game.o room.o event.o bats.o gold.o stalactites.o wumpus.o player.o -o run

main.o: main.cpp
	$(CC) -c main.cpp

game.o: game.cpp game.h
	$(CC) -c game.cpp

room.o: room.cpp room.h
	$(CC) -c room.cpp

event.o: event.cpp event.h
	$(CC) -c event.cpp

bats.o: bats.cpp bats.h
	$(CC) -c bats.cpp

gold.o: gold.cpp gold.h
	$(CC) -c gold.cpp

stalactites.o: stalactites.cpp stalactites.h
	$(CC) -c stalactites.cpp

wumpus.o: wumpus.cpp wumpus.h
	$(CC) -c wumpus.cpp

player.o: player.cpp player.h
	$(CC) -c player.cpp

clean:
	rm -f *.o $(exe)
