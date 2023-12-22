#include "room.h"

using namespace std;

room::room(){}

room::~room(){

	delete p;

	p = nullptr;

	delete e;

	e = nullptr;
}

void room::set_event(event* new_event) {

	if(this->e != nullptr){
		delete this->e;
	}

	this->e = new_event;
}

event* room::get_event() const{ return this->e;}

void room::set_player(player* new_player){


	if(this->p != nullptr){
		delete this->p;

	}
	this->p = new_player;
}

void room::set_null(player* old_player){

//	delete this->p;

	old_player = nullptr;

	this->p = old_player;
}

player* room::get_player() const{ return this->p;}


void room::set_wump_null(event* old_wump){

	delete this->e;

	old_wump = nullptr;

	this->e = old_wump;
}

//Room Implementation

