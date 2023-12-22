#ifndef WUMPUS_H
#define WUMPUS_H 

#include "event.h"

//Wumpus Interface

class wumpus : public event {

protected:

	bool killed;

public:

	wumpus();

	void encounter();

	void percept();

	char print();
};

#endif
