#include "person.h"
#include <iostream>

using namespace std;

Person::Person(const string &name, const Date &birthDate):
	name(name), birthDate(birthDate)
{
}

const string& Person::getName()
{
	return name;
}

const Date& Person::getBirthDate()
{
	return birthDate;
}

void Person::print()
{
	cout << name << " (" << birthDate << ")" << endl;
}

void Person::printVirtual()
{
	cout << name << " (" << birthDate << ")" << endl;
}
