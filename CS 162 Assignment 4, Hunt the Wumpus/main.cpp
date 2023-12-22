/*********************************************************************
** Program Filename: Hunt the wumpus
** Author: Josiah COllmer
** Date: 11/30/23
** Description: An interactive game with the goal of killin the wumpus
** Input: user inputs
** Output: A fun time
*********************************************************************/





#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;


int main()
{
	//set the random seed
	srand(time(NULL));

	int wid = 5, len = 5;
	bool debug = false;

	game g;

	//get two inputs: size of the cave(wid and len)
	cout << "cave width: ";
	cin >> wid;

	cout << "cave length: ";
	cin >> len;

	//get the 3rd input --> debug mode or not
	cout << "debug mode (1 = yes, 0 = no): ";
	cin >> debug;

	cin.clear();

	//Play game
	g.play_game(wid, len, debug);


	return 0;
}
