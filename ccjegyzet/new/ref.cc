#include <stdio.h>

void add1(int &dest, int a, int b)
{
	dest = a+b;
}

void add2(int &dest, const int &a, const int &b)
{
	dest = a+b;
}

void add3(int &dest, int &a, int &b)
{
	dest = a+b;
}

int main()
{
	int v;
	
	// OK:
	add1(v, 1, 2);
	// OK, mondhatjuk, hogy letrehoz egy ideiglenes valtozot,
	// es annak veszi a cimet:
	add2(v, 3, 4);
	// Hiba:
	add3(v, 5, 6);
}
