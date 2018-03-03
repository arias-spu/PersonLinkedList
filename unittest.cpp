#include "person.h"
#include "personlinkedlist.h"

#include <iostream>
#include <cassert>
using std::cout;
using std::endl;

int main(int argc, char* argv[]){
	PersonLinkedList list;
	assert(list.Size() == 0);
	assert(list.IsEmpty() == true);
//	assert(list.Remove(0) == false);
	assert(list.Insert("JOHN", 18, 1) == false);
	assert(list.Insert("JENNY", 19, 0) == true);
	assert(list.Get(0)->ToString() == Person("JENNY", 19).ToString());
	assert(list.Size() == 1);
	assert(list.IsEmpty() == false);
	assert(list.Insert("JULES", 21, 0) == true);
	assert(list.Get(0)->ToString() == Person("JULES", 21).ToString());
	assert(list.Get(1)->ToString() == Person("JENNY", 19).ToString());
	assert(list.Size() == 2);
	assert(list.IndexOf(Person("JULES", 21)) == 0);
	assert(list.IndexOf(Person("ANNE", 23)) == -1);
	assert(list.Insert("CLAUDE", 25, 2) == true);
//	assert(list.Remove(3) == false);
//	assert(list.Remove(1) == true);
	assert(list.Size() == 3); // Change 3 to 2 when Remove is functioning
	assert(list.Get(2)->ToString() == Person("CLAUDE", 25).ToString());  // Change 2 to 1 when Remove is functioning
	assert(list.Insert("FELIX", 17, 0) == true);
	assert(list.Insert("CLARA", 16, list.Size()) == true);
	assert(list.Insert("CHRIS", 27, 2) == true);
	assert(list.Insert("FULL", 90, 2) == true); // No longer a problem, linked list does not have capacity
	assert(list.Size() == 7); // Change 7 to 6 when Remove is functioning

	cout << "Program passed all unit tests!" << endl << endl;


	return 0;
}
