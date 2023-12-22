#include "stalactites.h"

#include <iostream>

using namespace std;

stalactites::stalactites(){}

void stalactites::encounter(){

	cout << "you look up and see a loose stalactite above you!" << endl;

}

void stalactites::percept(){

	cout << "You hear water dripping" << endl;
}

char stalactites::print(){

	return 'S';
}

//Stalactites Implementation
