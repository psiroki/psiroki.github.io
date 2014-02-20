#include <stdio.h>

void print(int n)
{
	printf("Szam: %d\n", n);
}

void print(const char *str)
{
	printf("Szoveg: %s\n", str);
}

struct Point
{
	int x, y;
};

void print(const struct Point *p)
{
	printf("Pont: %d, %d\n", p->x, p->y);
}

int main()
{
	print(5);
	print("foo");
	
	struct Point p;
	p.x = 3;
	p.y = 7;
	print(&p);

	return 0;
}
