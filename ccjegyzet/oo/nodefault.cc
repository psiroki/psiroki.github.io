#include "point.h"

int main()
{
	// az alabbi ket deklaracio ugyanazt a konstruktort
	// hivna meg, ha letezne
	Point p1;
	Point p2 = Point();
	// jegyezzuk azt is meg, hogy a default konstruktort
	// nem lehet Point p(); formaban meghivni
	return 0;
}
