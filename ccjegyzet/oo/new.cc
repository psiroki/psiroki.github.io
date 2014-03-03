#include <stdio.h>
#include "point.h"

char* repeat(char c, int count)
{
	// figyeljuk meg, hogy a tomb meretenek nem csak konstanst, hanem
	// akarmilyen erteket megadhatunk
	char *buf = new char[count+1];
	memset(buf, c, count);
	buf[count] = 0;
	return buf;
}
int main()
{
	char *sleep = repeat('z', 10);
	printf("%s\n", sleep);
	// ne felejtsuk el felszabaditani!
	// ha tombot allokaltunk, akkor a delete[] operatort hasznaljuk
	delete[] sleep;
	
	Point *p = new Point(2, 2);
	// ha nem tomb, akkor siman delete
	delete p;
	
	return 0;
}
