/*********************************************************************
** Program Filename:linked_list
** Author:Josiah Collmer
** Date:12/10/23
** Description:manipulate a linked list.
** Input:values and indexes for given manipulations
** Output:values inserted, removed, and sorted in linked list
*********************************************************************/


#include "linked_list.h"

int Linked_List::get_length() {
	// note: there is no set_length(unsigned int) (the reasoning should be intuitive)
	// Your code goes here:
	length = 0;

	node* my_node_ptr = head;

	while(my_node_ptr != nullptr){

		my_node_ptr = my_node_ptr->next;	//iterate through adding 1 to length until end

		length++;
	}

	return length;
}

void Linked_List::print(){
	// output a list of all integers contained within the list
	// Your code goes here:

	node* my_node_ptr = head;

	while(my_node_ptr != nullptr){

		cout << my_node_ptr->val << " ";

		my_node_ptr = my_node_ptr->next;

	}

	cout << "\n";
	return;
}

void Linked_List::clear(){
	// delete the entire list (remove all nodes and reset length to 0)
	// Your code goes here:

	while(length > 0){

		pop_front();	//call pop_front() for all nodes

		length--;
	}

	return;
}

void Linked_List::push_front(int val){
	// insert a new value at the front of the list 
	// Your code goes here:
	node* new_node = new node;

	new_node->val = val;

	new_node->next = head;

	head = new_node;

	return;
}

void Linked_List::push_back(int val){
	// insert a new value at the back of the list 
	// Your code goes here:
	node* new_node = new node;

	new_node->val = val;

	new_node->next = nullptr;

	if(head == nullptr){

		head = new_node;		//if no nodes in list

	} else {

		node* my_node_ptr = head;

		while(my_node_ptr->next != nullptr) {

			my_node_ptr = my_node_ptr->next;
		}

		my_node_ptr->next = new_node;
	}
	return;
}

void Linked_List::insert(int val, int index){
	// insert a new value in the list at the specified index 
	// Your code goes here:

	if(index < 0 || index > length) { return; }

	if(index == get_length()){

		push_back(val);

	} else if(index == 0){

		push_front(val);

	} else {

		node* new_node = new node;

		new_node->val  = val;

		node* my_node_ptr = head;

		for(int i = 0; i < index - 1; i++){

			my_node_ptr = my_node_ptr->next;
		}

		new_node->next = my_node_ptr->next;		//new node points to what my was pointing to

		my_node_ptr->next = new_node;		//my points to new node
	}

	return;
}

void Linked_List::pop_back(){
	// remove the node at the back of the list
	// Your code goes here:

	if(head == nullptr) { return; }

	if(head->next == nullptr){

		pop_front();
	} else {

		node* my_node_ptr = head;

		node* my_node_ptr2 = nullptr;

		while(my_node_ptr->next != nullptr){

			my_node_ptr2 = my_node_ptr;

			my_node_ptr = my_node_ptr->next;
		}

		my_node_ptr2->next = nullptr;

		delete my_node_ptr;
	}

	return;
}

void Linked_List::pop_front(){
	// remove the node at the front of the list
	// Your code goes here:

	if(head == nullptr){ return; }

	else {

		node* temp = head->next;

		delete head;

		head = temp;
	}

	return;
}

void Linked_List::remove(int index){
	// remove the node at index of the list
	// Your code goes here:

	if(index < 0 || index > length) { return; }

	if(index == get_length()){

		pop_back();

	} else if(index == 0){

		pop_front();

	} else {

		node* my_node_ptr = head;

		node* my_node_ptr2 = nullptr;

		for(int i = 0; i < index; i++){		//arrive at the value before index

			my_node_ptr2 = my_node_ptr;

			my_node_ptr = my_node_ptr->next;
		}

		my_node_ptr2->next = my_node_ptr2->next->next;		//ptr before points to ptr after index

		delete my_node_ptr;		//delete ptr to index
	}
	return;
}

void Linked_List::split(node* my_node_ptr, node** half1, node** half2){

	if(my_node_ptr == nullptr || my_node_ptr->next == nullptr) {

		*half1 = my_node_ptr;

		*half2 = nullptr;

	} else {

		node* front = my_node_ptr->next;

		node* back = my_node_ptr;

		while(front != nullptr) {

			front = front->next;

			if(front != nullptr) {

				front = front->next;

				back = back->next;
			}
		}

		*half1 = my_node_ptr;	//split the two halfs, so they are actually two separate lists

		*half2 = back->next;

		back->next = nullptr;	//no connection between them
	}
}

void Linked_List::mergesort(node** oldhead){

	node* half1 = nullptr;

	node* half2 = nullptr;

	node* my_node_ptr = *oldhead;

	if(my_node_ptr == nullptr || my_node_ptr->next == nullptr) { return; }

	else {

		split(my_node_ptr,&half1, &half2);

		mergesort(&half1);		//recursive calls on first and second half

		mergesort(&half2);

		*oldhead = merge(half1, half2);
	}
}

node* Linked_List::merge(node* half1, node* half2){

	node* combo = nullptr;

	if(half1 == nullptr){ return half2; }

	else if(half2 == nullptr){ return half1; }



	if(ad == false){			//if false sort ascending else sort descending

		if(half1->val <= half2->val) {

			combo = half1;

			combo->next = merge(half1->next, half2);	//recursive call setting next value in
									//linked list = to the greater of the two

		}else {

			combo = half2;

			combo->next = merge(half1, half2->next);
		}

	}else {

		if(half1->val >= half2->val) {

			combo = half1;

			combo->next = merge(half1->next, half2);

		}else {

			combo = half2;

			combo->next = merge(half1, half2->next);
		}
	}

	return combo;
}

void Linked_List::sort_ascending(){
	// sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm
	// Note: it's okay if sort_ascending() calls a recursive private function to perform the sorting.
	// Your code goes here:

	mergesort(&head); //pass by refrence so mergesort() can actually change the values

	return;
}

void Linked_List::sort_descending(){
	// sort the nodes in descending order
	// Your code goes here:

	ad = 1;		//ascending/descending boolean

	mergesort(&head);

	return;
}

