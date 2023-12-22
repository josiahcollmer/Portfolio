#include "bats.h"
#include "event.h"
#include <iostream>

using namespace std;


bats::bats(){}

void bats::encounter(){

	cout << "it's a super bat! the venomous bite makes you delirious" << endl;
}

void bats::percept(){

	cout << "You hear wings flapping" << endl;
}

char bats::print(){

	return 'B';
}

//Bats Implementation
