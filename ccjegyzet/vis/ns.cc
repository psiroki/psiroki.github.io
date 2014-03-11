#include <stdio.h>

int bar = 3;

namespace foo
{
	int bar = 4;
	
	void show(const char *s)
	{
		printf("(%d/%d) %s\n", ::bar, ++bar, s);
	}
};

int main()
{
	foo::bar = 5;
	for(int i=0; i<3; ++i)
		foo::show("Hello World!");
	
	return 0;
}
