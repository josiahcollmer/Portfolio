#ifndef BATS_H
#define BATS_H

#include "event.h"

//Bats Interface

class bats : public event {

public:

	bats();

	void encounter();

	void percept();

	char print();
};

#endif
