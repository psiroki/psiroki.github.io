#include <stdio.h>

class Counter
{
	static int nextValue;
	const int value;
public:
	inline Counter(): value(nextValue++)
	{
		printf("Counter::Counter() x %d\n", value);
	}
	~Counter();
	
	static int getNextValue();
};

int Counter::nextValue = 1;

int Counter::getNextValue()
{
	return nextValue;
}

Counter::~Counter()
{
	printf("Counter::~Counter() x %d\n", value);
}

int main()
{
	Counter c[3];
	
	printf("Next value: %d\n", Counter::getNextValue());
	
	return 0;
}
