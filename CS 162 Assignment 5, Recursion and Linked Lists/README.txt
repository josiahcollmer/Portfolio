If this is Jacob Evans, tell em to bring me my money :)


Name: Josiah Collmer
ONID: 934442046
Section: CS 162-050
Assignment 5, due 12/10/2023

Recursion Description:

This recursive program takes an input of "n" number
of steps on a set of stairs.A person has the option 
to take a small (1 step), medium (2 steps), or large 
(3 steps) step up the set of stairs. By testing every 
possible combination, this program can determine the total 
number of combinations, including different permutations of 
the same combination of steps.

Linked_List Description:

This linked list program has a variety of different 
functionalities. Given hard coded inputs, this program
can manipulate a linked list and the nodes it contains. 
Meaning, given a chain of values, it can add, remove,
insert into, and organize those values.


Instructions:

 Compile and run both programs  with the commands

cd desiredfilename(linked_list or recursion)

make

run 

valgrind run

when running the linked_list program, simply press enter to see 
each test case until it reaches the end.

Limitations:

All test cases are hard coded, so there is no user input.


Sort_Ascending algorithm:

I used the merge sort alogrithm which splits the original linked 
list in half, then those halves are split
in half again, and so on and so forth, utnil there are only 
individual nodes left. These node are then 
compared with eacther and sorted. The time complexity for this 
is logrithmic, denoted as O(log n) in big O notation.
This is because the runtime is halved every iteration. This correlates 
with the linked list getting halved every iteration
and therefore every input being half the size.

Sort_Descending Algorithm:

I used merge sort for this as well, and just made a new case for if it is 
to be sorted in descending order. Same algorithmand same time complexity.
