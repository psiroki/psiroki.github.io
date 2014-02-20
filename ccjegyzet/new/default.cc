#include <stdio.h>

void foo(int a, int b=1, int c=2, int d=3, int e=4)
{
	printf("%d %d %d %d %d\n", a, b, c, d, e);
}


int main()
{
	foo(0);
	foo(1, 0);
	foo(2, 1, 0);
	foo(4, 3, 2, 1, 0);
	return 0;
}
