#include "wumpus.h"

#include <iostream>

using namespace std;


wumpus::wumpus(){

	killed = false;
}

void wumpus::encounter(){

	cout << "it's the WUMPUS! you have been eaten, Game Over" << endl;
}

void wumpus::percept(){

	cout << "You smell a terrible stench" << endl;
}

char wumpus::print(){

	return 'W';
}

//Wumpus Implementation
