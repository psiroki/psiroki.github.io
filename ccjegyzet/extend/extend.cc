#include "employee.h"
#include <iostream>

using namespace std;

Date makeDate(int year, int month, int day)
{
	Date result;
	result.year = year;
	result.month = month;
	result.day = day;
	
	return result;
}

void fooPerson(Person p)
{
}

void fooPersonAt(Person &p)
{
}

void fooPersonPtr(Person *p)
{
}

void fooEmployee(Employee e)
{
}

void fooEmployeeAt(Employee &e)
{
}

void fooEmployeePtr(Employee *e)
{
}

int main()
{
	Employee e("John Doe", makeDate(1987, 8, 7), makeDate(2011, 7, 15));
	Person p("Jane Doe", makeDate(1991, 2, 3));
	
	cout << "Employee:" << endl;
	e.print();
	cout << "----" << endl;
	e.printVirtual();
	cout << "====" << endl;
	
	// p Peson tipusu referencia e-re
	Person &pe(e);
	
	cout << "Person&:" << endl;
	pe.print();
	cout << "----" << endl;
	pe.printVirtual();
	cout << "====" << endl;
	
	// copy konstruktort hiv,
	// a copy konstruktor const Person& tipusu parametert var,
	// vagyis nem lesz problemaja az Employee tipusu ertekkel
	fooPerson(e);
	// nem hiv copy konstruktort, es "e" Person "reszet" latja
	fooPersonAt(e);
	// nem hiv copy konstruktort, a mutato mogott ugyanazt latja,
	// mint az elozo a referenciaval
	fooPersonPtr(&e);
	
	// nyilvan nem megy:
	// fooEmployee(p);
	// fooEmployeeAt(p);
	// fooEmployeePtr(&p);
	
	return 0;
}
