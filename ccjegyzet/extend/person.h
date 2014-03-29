#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>
#include "date.h"

class Person
{
	std::string name;
	Date birthDate;
public:
	Person(const std::string &name, const Date &birthDate);
	
	void setName(const std::string &name);
	
	const std::string& getName();
	const Date& getBirthDate();
	
	void print();
	virtual void printVirtual();
};

#endif
