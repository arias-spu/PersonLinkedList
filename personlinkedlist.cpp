#include "person.h"
#include "personlinkedlist.h"

#include <iostream>
#include <string>
using std::ostream;
using std::istream;
using std::string;
using std::cerr;

PersonLinkedList::PersonLinkedList(const PersonLinkedList& other){
	cerr << "This method is not implemented" << endl;

}
PersonLinkedList::PersonLinkedList& operator=(const PersonLinkedList& other){
	return *this;
}
PersonLinkedList::PersonLinkedList(){
	_head = nullptr;
	_size = 0;
}
PersonLinkedList::~PersonLinkedList(){
}
size_t PersonLinkedList::LoadFromStream(istream& input){
	int personsRead = 0;

}

size_t PersonLinkedList::SaveToStream(ostream& output)const{
	for (Node* tmp=_head; tmp != nullptr; tmp = tmp->next)
		tmp->data->WriteToStream(output);
	return _size;
}
bool PersonLinkedList::Insert(Person*, size_t){
}
bool PersonLinkedList::Insert(const string&, size_t){
}
Person* PersonLinkedList::Get(size_t)const{
}
int PersonLinkedList::IndexOf(const Person&)const{
}
bool PersonLinkedList::Remove(size_t){
}
bool PersonLinkedList::IsEmpty()const{
}
size_t PersonLinkedList::Size()const{
}
