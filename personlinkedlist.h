#pragma once

#include "person.h"

#include <iostream>
#include <string>
using std::ostream;
using std::istream;
using std::string;

class PersonLinkedList{
	struct Node{
		Person* data;
		Node* next;
		Node* prev;
	};
	Node* _head;
	size_t _size;
	PersonLinkedList(const PersonLinkedList&);
	PersonLinkedList& operator=(const PersonLinkedList&);
public:
	PersonLinkedList();
	~PersonLinkedList();
	void LoadFromStream(istream&);
	void SaveToStream(ostream&)const;
	bool Insert(Person*, size_t);
	bool Insert(const string&, size_t);
	Person* Get(size_t)const;
	int IndexOf(const Person&)const;
	bool Remove(size_t);
	bool IsEmpty()const;
	size_t Size()const;
};
