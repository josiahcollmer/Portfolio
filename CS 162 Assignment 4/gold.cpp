#include "gold.h"

#include <iostream>

using namespace std;

gold::gold() {

	found = false;
}

void gold::encounter(){

	cout << "you found the gold! return to the exit" << endl;
}

void gold::percept(){

	cout << "You see a glimmer nearby" << endl;
}

char gold::print() {

	return 'G';
}

//Gold Implementation
