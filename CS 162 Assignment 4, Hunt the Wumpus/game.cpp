#include "game.h"
#include "gold.h"
#include "stalactites.h"
#include "bats.h"
#include "wumpus.h"
#include "room.h"
#include "player.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Game Implementation
game::~game(){}

game::game(){

	rows = 0;
	columns = 0;
	num_arrows = 0;
	debug_view = 0;
	//Game constructor
}


void game::set_up(int r, int c){
	//set up the game
	this->rows = r;
	this->columns = c;

	this->num_arrows = 3; 	//start with 3 arrows

	// Create the game board: 2D vector of Room objects

	this->grid.resize(rows);

	for (int i = 0; i < rows; i++) {
		grid.at(i).resize(columns);


	}

	this->insert_event(new bats);
	this->insert_event(new bats);

	this->insert_event(new stalactites);
	this->insert_event(new stalactites);

	this->insert_event(new gold);
	this->insert_event(new wumpus);

	this->insert_player(new player);

	// randomly insert events (2 bats, 2 stalactites, 1 wumpus, 1 gold)
	// into the board



}

void game::insert_player(player* p) {


	int row_indx;
	int col_indx;

	do{

	row_indx = rand() % grid.size();

	col_indx = rand() % (grid.at(0).size());

	} while(grid.at(row_indx).at(col_indx).get_event() != nullptr);


	grid.at(row_indx).at(col_indx).set_player(p);

	this->player_x = col_indx;
	this->player_y = row_indx;

	this->og_x = col_indx;
	this->og_y = row_indx;
}


void game::insert_event(event* e) {

	int row_indx;
	int col_indx;

	do{

	row_indx = rand() % grid.size();

	col_indx = rand() % (grid.at(0).size());

	} while(grid.at(row_indx).at(col_indx).get_event() != nullptr);


	grid.at(row_indx).at(col_indx).set_event(e);
}

void game::display_game() const{
	cout << endl << endl;
	cout << "Arrows remaining: " << this->num_arrows << endl;

	string line = "";
	for (int i = 0; i < this->columns; ++i)
		line += "-----";

	for (int i = 0; i < this->rows; ++i)
	{
		cout << line << endl;
		for (int j = 0; j < this->columns; ++j)
		{
			//The first char indicates whether there is a player in that room or not
			//if the room does not have the player, print space " "

		//else, print "*"
			if (grid[i][j].get_player() == nullptr && grid[i][j].get_event() == nullptr) {

				cout << " ";

			} if (grid[i][j].get_player() != nullptr) {


				cout << "*";

			} if (this->debug_view == 1 && grid[i][j].get_event() != nullptr) {

				event* e = grid[i][j].get_event();

				cout << e->print();

			} if (this->debug_view == 0 && grid[i][j].get_event() != nullptr) {

				cout << " ";

			}

			//The next two chars indicate the event in the room
			//if the room does not have an event, print "  ||" (2 spaces + ||)

			//else
				//if debug_view is true
					//print the corresponding char of the event
				//else
					//print " " (1 space)
				// print " ||" (1 space + ||)

			cout << "  ||";
		}
		cout << endl;
	}
	cout << line << endl;

	//example output (when finished): 
	// --------------------
	//  B || G || B ||   ||
	// --------------------
	//    || W ||   || S ||
	// --------------------   
	//    ||   ||   || S ||
	// --------------------   
	// *  ||   ||   ||   ||
	// --------------------
}


void game::encounter_event(){

	char event_type;

	if(grid[player_y][player_x].get_event() != nullptr){

		event_type = grid[player_y][player_x].get_event()->print();

		if(event_type == 'G'){

			has_gold = true;

			grid[player_y][player_x].get_event()->encounter();
		}

		else if(event_type == 'W'){

			grid[player_y][player_x].get_event()->encounter();

			dead = true;
		}

		else if(event_type == 'B'){

			confused = true;

			conf_move = 5;

			grid[player_y][player_x].get_event()->encounter();
		}

		else if(event_type == 'S'){

			bool fiftyfifty = (rand() % 2) != 0;

			grid[player_y][player_x].get_event()->encounter();

			if(fiftyfifty == true){

				cout << "the stalatctite breaks and crushes you! Game Over" << endl;

				dead = true;
			}else{

				cout << "the stalactite holds fast and does not fall" << endl;
			}
		}
	}
}
bool game::check_win(){
	//check if game over/win

	bool win = false;


	if(killed_wumpus == true){

		cout << "congratulations! you win!" << endl;

		win = true;
	}

	if(has_gold == true && player_y == og_y && player_x == og_x){

		cout << "congratulations! you win!" << endl;

		win = true;

	}

	return win;
}

void game::move_up() {
	//move player up

	if (player_y - 1 >= 0) {



		player* p = grid[player_y][player_x].get_player();

		grid[player_y][player_x].set_null(p);

		this->player_y --;

		grid[player_y][player_x].set_player(p);

	} else {

		cout << "out of bounds" << endl;
	}


	return;

}

void game::move_down() {
	//move player down

	if (player_y + 2 <= rows) {



		player* p = grid[player_y][player_x].get_player();

		grid[player_y][player_x].set_null(p);

		this->player_y ++;

		grid[player_y][player_x].set_player(p);

	} else {

		cout << "out of bounds" << endl;
	}

	return;
}

void game::move_left() {
	//move player left

	if (player_x - 1 >= 0) {



		player* p = grid[player_y][player_x].get_player();

		grid[player_y][player_x].set_null(p);

		this->player_x --;

		grid[player_y][player_x].set_player(p);

	} else {

		cout << "out of bounds" << endl;
	}
	return;

}

void game::move_right() {
	//move player right

	if (player_x + 2 <= columns) {



		player* p = grid[player_y][player_x].get_player();

		grid[player_y][player_x].set_null(p);

		this->player_x ++;

		grid[player_y][player_x].set_player(p);

	} else {

		cout << "out of bounds" << endl;
	}
	return;
}

char game::get_dir(){
	//get direction of arrow:
	char dir;
	cout << "Fire an arrow...." << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;

	cout << "Enter direction: " << endl;
	cin >> dir;
	cin.ignore(256, '\n');

	return dir;
}

void game::wumpus_move(){

	int wump_move = (rand() % 3);


	if(wump_move != 0){

		cout << "the wumpus was startled and ran to a new cave" << endl;

		for(int i = 0; i < this->rows; i++){

			for(int j = 0; j < this->columns; j++){

				if(grid[i][j].get_event() != nullptr){

					if(grid[i][j].get_event()->print() == 'W') {

					event* w = grid[j][i].get_event();

					grid[i][j].set_wump_null(w);

					this->insert_event(new wumpus);
					}
				}
			}
		}
	}
	//after a missed arrow, 75% chance that the wumpus is moved to a different room

	//How to get 75%? 
	//Hint: generate a random number from 0-3, if the number is not 0, then mov

	return;
}

void game::fire_arrow(){
	// The player may fire arrow...
	char dir = get_dir();

	switch(dir){
		case 'w':
			cout << "you shoot north" << endl;
			for(int i = 0; i < 4; i++){

				if(player_y - i >= 0){

					if(grid[player_y - i][player_x].get_event() != nullptr){

						if(grid[player_y - i][player_x].get_event()->print() == 'W'){

							cout << "you killed the wumpus!" << endl;
							killed_wumpus = true;
						}
					}
				}
			}
			break;
		case 'a':
			cout << "you shoot west" << endl;
			for(int i = 0; i < 4; i++){

				if(player_x - i >= 0){

					if(grid[player_y][player_x - i].get_event() != nullptr){

						if(grid[player_y][player_x - i].get_event()->print() == 'W'){

							cout << "you killed the wumpus!" << endl;
							killed_wumpus = true;
						}
					}
				}
			}

			break;
		case 's':
			cout << "you shoot south" << endl;
			for(int i = 0; i < 3; i++){

				if(player_y + i + 1 <= rows){

					if(grid[player_y + i][player_x].get_event() != nullptr){

						if(grid[player_y + i][player_x].get_event()->print() == 'W'){

							cout << "you killed the wumpus!" << endl;
							killed_wumpus = true;
						}
					}
				}
			}

			break;
		case 'd':
			cout << "you shoot east" << endl;
			for(int i = 0; i < 4; i++){

				if(player_x + i + 1 <= columns){

					if(grid[player_y][player_x + i].get_event() != nullptr){

						if(grid[player_y][player_x + i].get_event()->print() == 'W'){

							cout << "you killed the wumpus!" << endl;
							killed_wumpus = true;
						}
					}
				}
			}

			break;
	}

	if(killed_wumpus == false){

		cout << "your arrow missed" << endl;
		num_arrows --;

		wumpus_move();
	}
}


void game::move(char c) {
	// Handle player's action: move or fire an arrow
	if (c == 'f'){

		if(num_arrows < 1){

			cout << "your quiver is empty" << endl;
		}else{
			game::fire_arrow();
		}

		return;
	}
	switch(c){
		case 'w':
			game::move_up();
			break;
		case 'a':
			game::move_left();
			break;
		case 's':
			game::move_down();
			break;
		case 'd':
			game::move_right();
			break;
	}
}

void game::confused_move(char c) {
	// Handle player's action: move or fire an arrow
	if (c == 'f'){
		if(num_arrows < 1){

			cout << "your quiver is empty" << endl;
		}else{
			game::fire_arrow();
		}

		return;
	}
	switch(c){
		case 'w':
			game::move_down();

			if(conf_move > 0){
				conf_move --;
			}

			break;
		case 'a':
			game::move_right();

			if(conf_move > 0){
				conf_move --;
			}
			break;
		case 's':
			game::move_up();

			if(conf_move > 0){
				conf_move --;
			}
			break;
		case 'd':
			game::move_left();

			if(conf_move > 0){
				conf_move --;
			}
			break;
	}
}

void game::print_percept(){

	if(player_y - 1 >= 0){

		if(grid[player_y - 1][player_x].get_event() != nullptr){

			grid[player_y - 1][player_x].get_event()->percept();
		}
	}


	if(player_y + 2 <= rows){

		if(grid[player_y + 1][player_x].get_event() != nullptr){

			grid[player_y + 1][player_x].get_event()->percept();
		}
	}


	if(player_x - 1 >= 0){

		if(grid[player_y][player_x - 1].get_event() != nullptr){

			grid[player_y][player_x - 1].get_event()->percept();
		}
	}


	if(player_y + 2 <= columns){

		if(grid[player_y][player_x + 1].get_event() != nullptr){

			grid[player_y][player_x + 1].get_event()->percept();
		}
	}
}

char game::get_input(){
	//get action, move direction or firing an arrow

	//Note: error checking is needed!!
	//Your code here:
	char c;

	cout << endl << endl << "Player move..." << endl << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	cout << "f-fire an arrow" << endl;

	cout << "Enter input: " << endl;

	cin >> c;
	cin.ignore(256, '\n');

	return c;
}

void game::play_game(int w, int l, bool d){


	game::set_up(l, w);
	this->debug_view = d;

	char input, arrow_input;

	while (game::check_win() == false && dead == false){
		//print game board
		game::display_game();

		//display percerts around player's location
		//Your code here:
		game::print_percept();
		//Player move...
		//1. get input


		input = game::get_input();

		//2. move player
		if(confused == true && conf_move > 0){

			game::confused_move(input);

		}else {
			game::move(input);
		}
		//3. may or may not encounter events
		//Your code here:
		game::encounter_event();
	}

	return;

}

