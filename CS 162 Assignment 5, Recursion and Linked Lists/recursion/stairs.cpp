/*********************************************************************
** Program Filename:recursion
** Author:Josiah Collmer
** Date:12/10/23
** Description:recursively compute the number of combinations of 1, 2,
and 3 steps possible to get exactly to the top of a set of stairs with
n number of steps.

** Input:n stairs
** Output:number of combinations
*********************************************************************/


#include <iostream>

using namespace std;

int ways_to_top(int n) {
	// YOUR CODE GOES HERE

	int num_ways = 0;

	if (n == 0)

		{ return 1; }		//base cases

	if (n < 0)

		{ return 0; }

	num_ways = ways_to_top(n - 1);		//take small step


	if (n >= 2) {

		num_ways += ways_to_top(n - 2);		//take medium step
	}

	if (n >= 3) {

		num_ways += ways_to_top(n - 3);		//take large step
	}

    return num_ways;
}
