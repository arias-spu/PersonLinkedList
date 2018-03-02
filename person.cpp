#include "person.h"

#include <string>
#include <sstream>
#include <iomanip>
using std::string;
using std::stringstream;
using std::setw;
using std::ostream;
using std::istream;
using std::endl;

Person::Person(const string& name, size_t age): _name(name), _age(age){
}
void Person::IncreaseAge(){
	_age++;
}
string Person::ToString()const{
	stringstream retVal;
	retVal << setw(10) << _name << setw(6) << _age;
	return retVal.str();
}
void Person::ReadFromStream(istream& input){
	input >> _name >> _age;
}
void Person::WriteToStream(ostream& output)const{
	output << _name << " " << _age << endl;
}
bool Person::Equals(const Person& rhs){
	return _name == rhs._name && _age == rhs._age;
}
