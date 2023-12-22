#ifndef GOLD_H
#define GOLD_H 

#include "event.h"
//Gold Interface

class gold : public event {

protected:

	bool found;

public:

	gold();

	void encounter();

	void percept();

	char print();
};

#endif
