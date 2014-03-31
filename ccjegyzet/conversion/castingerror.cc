#include <iostream>

using namespace std;

struct A
{
	int value;
	
	inline A(int v): value(v) { }
};

struct B
{
	float value;
};

int main()
{
	A a(3);
	B *b = static_cast<B*>(&a);
	
	cout << b->value << endl;
	
	return 0;
}
