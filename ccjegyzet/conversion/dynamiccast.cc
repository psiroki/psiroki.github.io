#include <iostream>

using namespace std;

struct A
{
	int i;
	
	inline A(int v): i(v) { }
	// a dynamic_cast hasznalatahoz kell,
	// hogy legyen legalabb egy virtualis
	// fuggveny
	virtual ~A();
};

A::~A()
{
}

struct B: public A
{
	float f;
	
	inline B(int i, float f): A(i), f(f) { }
};

int main()
{
	A a(3);
	B *bp = dynamic_cast<B*>(&a);
	A *ap = bp;
	
	// allokalatlan teruletrol olvassa ki az erteket,
	// mert bp helyen csak A van
	cout << bp->f << endl;
	
	return 0;
}
