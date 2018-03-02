#pragma once

#include <string>
#include <iostream>
using std::string;
using std::istream;
using std::ostream;

class Person{
	string _name;
	size_t _age;
public:
	Person(const string&, size_t);
	void IncreaseAge();
	string ToString()const;
	void ReadFromStream(istream&);
	void WriteToStream(ostream&)const;
	bool Equals(const Person&);
};
