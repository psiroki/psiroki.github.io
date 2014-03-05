#include "point.h"

int main()
{
	Point p1(1, 2);
	// copy konstruktort hivja meg:
	Point p2(p1);
	// ez is:
	Point p3 = p1;
	// ez nem:
	p3 = p2;
	
	return 0;
};
