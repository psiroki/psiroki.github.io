#ifndef _UTIL_SAFE_H_
#define _UTIL_SAFE_H_

struct Record
{
	int a, b;
};

typedef const char *STR;
void foo(int x);
extern STR bar;

#endif
