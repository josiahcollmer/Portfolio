#ifndef STALACTITES_H
#define STALACTITES_H

#include "event.h"

//Stalactites Interface

class stalactites : public event{

public:

	stalactites();

	void encounter();

	void percept();

	char print();

};

#endif
