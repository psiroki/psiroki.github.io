#include "point.h"
#include <stdio.h>

Point::Point(int initX, int initY)
{
	x = initX;
	y = initY;
	// azert, hoy kovetni tudjuk, mikor hivodik meg
	printf("Konstruktor: %d %d\n", x, y);
}

Point::~Point()
{
	// eleg hulye dolog, de a demonstracioert
	// mindent
	printf("Destruktor: %d %d\n", x, y);
}

Point Point::offset(int offsetX, int offsetY)
{
	return Point(x+offsetX, y+offsetY);
}
