#include <stdio.h>
#include "point.h"

int main()
{
	// egyik konstruktorhivasi forma
	Point p1(1, 2);
	Point p2 = p1.offset(3, 4);
	
	// 1 2
	printf("%d %d\n", p1.getX(), p1.getY());
	// 4 6
	printf("%d %d\n", p2.getX(), p2.getY());
	
	{
		// masik konstruktorhivasi forma
		Point p3 = Point(5, 6);
		Point p4 = p3.offset(7, 8);
		printf("1..\n");
	}
	
	printf("2..\n");
	
	return 0;
}
