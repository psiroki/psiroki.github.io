#include <iostream>

using namespace std;

struct A
{
	int i;
	
	inline A(int v): i(v) { }
};

struct B: public A
{
	float f;
	
	inline B(int i, float f): A(i), f(f) { }
};

int main()
{
	B b(3, 5.2f);
	A *ap = &b;
	B *bp = static_cast<B*>(ap);
	
	cout << bp->f << endl;
	
	return 0;
}
