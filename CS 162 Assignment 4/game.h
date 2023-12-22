#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream> 
#include "room.h"
#include "player.h"

using namespace std;

//Game interface
class game
{
private:

	//declare a 2D vector of Room objects:

	//other member variables:
	int rows; 			//length of the board
	int columns;  			//width of the board
	int num_arrows; 		//keep track of number of arrows remaining
	bool debug_view;		//debug mode or not

	vector<vector<room>> grid;

	int player_x;
	int player_y;

	int conf_move = 0;
	bool dead = false;
	bool has_gold = false;
	bool killed_wumpus = false;
	bool confused = false;


	int og_x;
	int og_y;


	//feel free to add more variables...

public:

	//suggested functions:

/*********************************************************************
** Function: game
** Description: Constructor for the game class, initializes member variables.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Game object created with initialized values.
*********************************************************************/
	game();

//not necessary, but gave error when removed
	~game();

/*********************************************************************
** Function: encounter_event
** Description: Handles events encountered by the player in the game.
** Parameters: None
** Pre-Conditions: PLayer enters room with event in it
** Post-Conditions: Player state and game state may be updated based on events.
*********************************************************************/
	void encounter_event();

/*********************************************************************
** Function: insert_player
** Description: Inserts a player into the game.
** Parameters: player* p - pointer to the player object to be inserted.
** Pre-Conditions: Game is set up.
** Post-Conditions: Player is inserted into the game.
*********************************************************************/
	void insert_player(player* p);

/*********************************************************************
** Function: insert_event
** Description: Inserts an event into the game.
** Parameters: event* e - pointer to the event object to be inserted.
** Pre-Conditions: Game is set up.
** Post-Conditions: Event is inserted into the game.
*********************************************************************/
	void insert_event(event* e);

/*********************************************************************
** Function: set_up
** Description: Sets up the initial state of the game grid.
** Parameters: int rows - length of the board, int columns - width of the board
** Pre-Conditions: Game object created
** Post-Conditions: Game grid is initialized.
*********************************************************************/
	void set_up(int rows, int columns);

/*********************************************************************
** Function: display_game
** Description: Displays the current state of the game grid.
** Parameters: None
** Pre-Conditions: Game is in progress
** Post-Conditions: Game grid is displayed.
*********************************************************************/
	void display_game() const;

/*********************************************************************
** Function: check_win
** Description: Checks if the player has won the game.
** Parameters: None
** Pre-Conditions: Game is in progress
** Post-Conditions: Returns true if the player has won, false otherwise.
*********************************************************************/
	bool check_win();

/*********************************************************************
** Function: get_dir
** Description: Gets the direction input from the player.
** Parameters: None
** Pre-Conditions: Game is in progress
** Post-Conditions: Returns the direction input by the player.
*********************************************************************/
	char get_dir();

/*********************************************************************
** Function: wumpus_move
** Description: Moves the Wumpus in the game.
** Parameters: None
** Pre-Conditions: Player fires and misses arrow
** Post-Conditions: Wumpus is moved to a new location.
*********************************************************************/
	void wumpus_move();

/*********************************************************************
** Function: fire_arrow
** Description: Fires an arrow in the game.
** Parameters: None
** Pre-Conditions: Num_arrows is greater than 0
** Post-Conditions: Arrow is fired, and game state may be updated.
*********************************************************************/
	void fire_arrow();

/*********************************************************************
** Function: move_up, move_down, move_left, move_right, move
** Description: Moves the player in the specified direction.
** Parameters: None (for individual move functions), char (for move function)
** Pre-Conditions: Game is in progress
** Post-Conditions: Player is moved to a new location.
*********************************************************************/
	void move_up();
	void move_down();
	void move_left();
	void move_right();
	void move(char);

/*********************************************************************
** Function: print_percept
** Description: Prints the percept message for the current player location.
** Parameters: None
** Pre-Conditions: Player is adjacent to a room with an event
** Post-Conditions: Percept message is displayed.
*********************************************************************/
	void print_percept();

/*********************************************************************
** Function: confused_move
** Description: Moves the player in a confused state.
** Parameters: char - direction to move
** Pre-Conditions: Player is confused from super bat
** Post-Conditions: Player is moved in the specified direction for 5 moves.
*********************************************************************/
	void confused_move(char);

/*********************************************************************
** Function: get_input
** Description: Gets input from the player.
** Parameters: None
** Pre-Conditions: Game is in progress
** Post-Conditions: Returns the input provided by the player.
*********************************************************************/
	char get_input();

/*********************************************************************
** Function: play_game
** Description: Main function to play the game.
** Parameters: int, int, bool - game parameters
** Pre-Conditions: Game object created
** Post-Conditions: Game is played according to the specified parameters.
*********************************************************************/
	void play_game(int, int, bool);





};
#endif
