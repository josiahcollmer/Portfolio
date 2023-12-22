#ifndef LINKED_LIST
#define LINKED_LIST

#include "node.h"
#include <iostream>

using namespace std;

class Linked_List {
private:
	int length = 0; // the number of nodes contained in the list
	node* head = nullptr; // a pointer to the first node in the list
	// anything else you need...

	bool ad = 0;

public:

	int get_length();
	// note: there is no set_length(unsigned int) (the reasoning should be intuitive)
   
	void print(); // output a list of all integers contained within the list
	void clear(); // delete the entire list (remove all nodes and reset length to 0)
   
	void push_front(int); // insert a new value at the front of the list 
	void push_back(int); // insert a new value at the back of the list 
	void insert(int val, int index); // insert a new value in the list at the specified index 

	void pop_back(); // remove the node at the back of the list
	void pop_front(); // remove the node at the front of the list
	void remove(int index); // remove the node at index of the list

	void sort_ascending(); // sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm
	// Note: it's okay if sort_ascending() calls a recursive private function to perform the sorting.
	void sort_descending(); // sort the nodes in descending order



/*********************************************************************
** Function: void split(node*, node**, node**);
** Description: Splits a linked list into two halves.
** Parameters:
**    - node* head: Pointer to the head of the linked list to be split.
**    - node** firstHalf: Double pointer to a node pointer for the first half.
**    - node** secondHalf: Double pointer to a node pointer for the second half.
** Pre-Conditions: The linked list specified by 'head' should exist.
** Post-Conditions: 'firstHalf' and 'secondHalf' will point to the heads of the two halves.
*********************************************************************/
	void split(node*, node**, node**);


/*********************************************************************
** Function: void mergesort(node**);
** Description: Sorts a linked list in ascending or descending order using the merge sort algorithm.
** Parameters:
**    - node** headRef: Double pointer to the head of the linked list to be sorted.
** Pre-Conditions: The linked list specified by 'headRef' should exist.
** Post-Conditions: The linked list is sorted in ascending or descending order.
*********************************************************************/
	void mergesort(node**);


/*********************************************************************
** Function: node* merge(node*, node*);
** Description: Merges two sorted linked lists into a single sorted linked list.
** Parameters:
**    - node* list1: Pointer to the head of the first sorted linked list.
**    - node* list2: Pointer to the head of the second sorted linked list.
** Pre-Conditions: Both input lists 'list1' and 'list2' should be sorted.
** Post-Conditions: Returns the head of the merged sorted linked list.
*********************************************************************/
	node* merge(node*, node*);


	// you can add extra member variables or functions as desired

};




#endif
