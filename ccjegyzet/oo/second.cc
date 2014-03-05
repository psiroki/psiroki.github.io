#include "counter.h"
#include <stdio.h>

int main()
{
	printf("c = new Counter[4]:\n");
	// ezt akkor tehetjuk meg, ha az osztalnyak
	// van default (parameter nelkuli) konstruktora
	// a Point osztalyunkra nem mukodne
	Counter *c = new Counter[4];
	
	printf("delete[] c:\n");
	delete[] c;

	return 0;
}
