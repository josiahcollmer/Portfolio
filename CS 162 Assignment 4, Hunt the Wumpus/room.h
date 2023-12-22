#ifndef ROOM_H
#define ROOM_H

#include "event.h"
#include "player.h"
using namespace std;

//Room Interface
//Note: Each room may be empty or has an event (bat, gold, pit, or wumpus);
//		Use event polymorphically

class room
{
private:

	event* e = nullptr;
	player* p;

public:

/*********************************************************************
** Function: room
** Description: Constructor for the room class, initializes member variables.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Room object created with initialized values.
*********************************************************************/
	room();

/*********************************************************************
** Function: ~room
** Description: Destructor for the room class, cleans up any dynamically allocated memory.
** Parameters: None
** Pre-Conditions: Room object exists
** Post-Conditions: Dynamically allocated resources released.
*********************************************************************/
	~room();

/*********************************************************************
** Function: set_event
** Description: Sets the event in the room.
** Parameters: event* new_event - pointer to the event object to be set.
** Pre-Conditions: Room object created
** Post-Conditions: Event is set in the room.
*********************************************************************/
	void set_event(event* new_event);

/*********************************************************************
** Function: get_event
** Description: Gets the event in the room.
** Parameters: None
** Pre-Conditions: Room object created
** Post-Conditions: Returns the event in the room.
*********************************************************************/
	event* get_event() const;

/*********************************************************************
** Function: set_player
** Description: Sets the player in the room.
** Parameters: player* new_player - pointer to the player object to be set.
** Pre-Conditions: Room object created
** Post-Conditions: Player is set in the room.
*********************************************************************/
	void set_player(player* new_player);

/*********************************************************************
** Function: get_player
** Description: Gets the player in the room.
** Parameters: None
** Pre-Conditions: Room object created
** Post-Conditions: Returns the player in the room.
*********************************************************************/
	player* get_player() const;

/*********************************************************************
** Function: set_wump_null
** Description: Sets the Wumpus event to null.
** Parameters: event* old_wump - pointer to the old Wumpus event.
** Pre-Conditions: Room object created
** Post-Conditions: Wumpus event is set to null and pointer is deleted.
*********************************************************************/
	void set_wump_null(event* old_wump);

/*********************************************************************
** Function: set_null
** Description: Sets the player to null.
** Parameters: player* old_player - pointer to the old player object.
** Pre-Conditions: Room object created
** Post-Conditions: Player is set to null.
*********************************************************************/
	void set_null(player* old_player);


};

#endif

