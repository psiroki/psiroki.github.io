#include <iostream>

using namespace std;

struct A
{
	int i;
	
	inline A(int v): i(v) { }
};

struct B: public A
{
	double f;
	
	inline B(int i, double f): A(i), f(f) { }
};

int main()
{
	A a(3);
	B *bp = static_cast<B*>(&a);
	
	// allokalatlan teruletrol olvassa ki az erteket,
	// mert bp helyen csak A van
	cout << bp->f << endl;
	
	return 0;
}
