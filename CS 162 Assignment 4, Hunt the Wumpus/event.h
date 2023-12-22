
#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <string>
using namespace std;

//Event Interface
//Note: this must be an abstract class!

class event
{

protected:

public:

	event();

	virtual void encounter() = 0;

	virtual void percept() = 0;

	virtual char print() = 0;
};
#endif
