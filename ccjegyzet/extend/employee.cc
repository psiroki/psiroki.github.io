#include "employee.h"

#include <iostream>

using namespace std;

Employee::Employee(const std::string &name, const Date &birthDate, const Date &hiringDate):
	Person(name, birthDate),
	hiringDate(hiringDate)
{
}

const Date& Employee::getHiringDate()
{
	return hiringDate;
}

void Employee::print()
{
	Person::print();
	cout << "[" << hiringDate << "]" << endl;
}

void Employee::printVirtual()
{
	Person::print();
	cout << "[" << hiringDate << "]" << endl;
}
