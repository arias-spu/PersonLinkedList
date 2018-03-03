#include "person.h"
#include "personlinkedlist.h"

#include <iostream>
#include <string>
using std::ostream;
using std::istream;
using std::string;
using std::cerr;
using std::endl;

PersonLinkedList::PersonLinkedList(const PersonLinkedList& other){
	_head = nullptr;
	_size = 0;
	for (Node* tmp = other._head; tmp != nullptr; tmp = tmp->next)
		if (tmp->data)
			Insert(new Person(*tmp->data), _size);
}
PersonLinkedList& PersonLinkedList::operator=(const PersonLinkedList& other){
	return *this;
}
PersonLinkedList::PersonLinkedList(){
	_head = nullptr;
	_size = 0;
}
PersonLinkedList::~PersonLinkedList(){
	Node* next;
	Node* tmp = _head;
	while (tmp != nullptr){
		next = tmp->next;
		if (tmp->data)
			delete tmp->data; // Is this going to call a destructor? Which one?
		delete tmp; // Is this going to call a destructor? Which one?
		tmp = next;
		
	}
}
size_t PersonLinkedList::LoadFromStream(istream& input){
	int personsRead = 0;
	Person temporal("", 0);
	while (temporal.ReadFromStream(input)){
		Insert(new Person(temporal), _size);
		personsRead++;
	}
	return personsRead;

}

size_t PersonLinkedList::SaveToStream(ostream& output)const{
	for (Node* tmp=_head; tmp != nullptr; tmp = tmp->next)
		tmp->data->WriteToStream(output);
	return _size;
}
bool PersonLinkedList::Insert(Person* person, size_t position){
	if (position > _size)
		return false;
	Node* neo = new Node;
	neo->data = person;
	neo->next = nullptr;
	if (_size == 0)
		_head = neo;
	else if (position == 0){
		neo->next = _head;
		_head = neo;
	}else{
		Node* tmp = _head;
		for (size_t i=0; i<position-1; i++)
			tmp = tmp->next;
		neo->next = tmp->next;
		tmp->next = neo;
	}
	_size++;
	return true;
}
bool PersonLinkedList::Insert(const string& name, size_t age, size_t position){
	if (position > _size)
		return false;
	return Insert(new Person(name, age), position);
}
Person* PersonLinkedList::Get(size_t position)const{
	if (position >= _size)
		return nullptr;
	Node* tmp = _head;
	for (size_t i=0; i<position; i++)
		tmp = tmp->next;
	return tmp->data;
}
int PersonLinkedList::IndexOf(const Person& person)const{
	Node* tmp = _head;
	for (size_t i=0; i<_size; i++)
		if (tmp->data->Equals(person))
			return i;
	return -1;
}
bool PersonLinkedList::Remove(size_t position){
	if (position > _size)
		return false;

	// Do by yourselves
	cerr << "TO BE IMPLEMENTED" << endl;

	return true;
}
bool PersonLinkedList::IsEmpty()const{
	return _head == nullptr;
}
size_t PersonLinkedList::Size()const{
	return _size;
}
