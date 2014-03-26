#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include "person.h"

class Employee: public Person
{
	Date hiringDate;
public:
	Employee(const std::string &name, const Date &birthDate, const Date &hiringDate);
	
	const Date& getHiringDate();

	void print();
	virtual void printVirtual();
};

#endif
