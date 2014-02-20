#include <stdio.h>

void add1(int &dest, int a, int b)
{
	dest = a+b;
}

void add2(int &dest, const int &a, const int &b)
{
	dest = a+b;
}

void add3(int &dest, int &a, int &b)
{
	dest = a+b;
}

int foo = 0;

// OK, a foo akkor is letezik, amikor a fv mar kilepett
int& good()
{
	return foo;
}

// Nem OK, a val mar nem letezik, amikor a fuggveny erteket felhasznalna
// A fordito nem fog hibat jelezni (de figyelmeztethet).
// Meg jol is mukodhet, de kellemetlen meglepeteseket okozhat
int& bad()
{
	int val = 1;
	return val;
}

// Erre is figyelmeztet, de lefordul. Ugyanaz vonatkozik
// ra, mint az elozore. A const kulcsszo nelkul le se fordulna,
// mert a const kulcsszonal a fordito uj valtozot hoz letre,
// es annak a cimet veszi. Viszont a fuggveny visszatertekor
// a fuggveny osszes valtozoja ervenyet veszti, igy ez az
// ideiglenes valtozo is.
const int& lit()
{
	return 5;
}

int main()
{
	int v;
	
	// OK:
	add1(v, 1, 2);
	// OK, mondhatjuk, hogy letrehoz egy ideiglenes valtozot,
	// es annak veszi a cimet:
	add2(v, 3, 4);
	// Hiba:
	add3(v, 5, 6);
	
	// A good a foo valtozora ad referenciat, tehat
	// lenyegeben foo = 3
	good() = 3;
	
	return 0;
}
