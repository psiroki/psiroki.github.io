#include "counter.h"
#include <stdio.h>

static int count = 0;

Counter::Counter():
	// ez az inicializalo lista
	// bizonyos tipusokat, pl. const
	// mezoket csak ilyennel lehet
	value(++count)
{
	// ez nem mukodne:
	// value = ++count;
	printf("Counter::Counter() x %d\n", value);
}

Counter::~Counter()
{
	printf("Counter::~Counter() x %d\n", value);
}

int Counter::getValue()
{
	return value;
}
