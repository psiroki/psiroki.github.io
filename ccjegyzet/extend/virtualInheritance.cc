#include <iostream>
#include "virtualInheritance.h"

using namespace std;

void Member::setName(const std::string &newName)
{
	name = newName;
}

std::string Member::getName() const
{
	return name;
}

int main()
{
	MiddleTeamLeader mtl("Jane Doe", 9);
	TeamLeader &tl(mtl);
	TeamMember &tm(mtl);
	
	tl.setName("Summer Smith");
	cout << tl.getName() << endl;
	cout << mtl.getName() << endl;
	
	tm.setName("Beth Sanchez");
	cout << tm.getName() << endl;
	cout << mtl.getName() << endl;

	return 0;
}
