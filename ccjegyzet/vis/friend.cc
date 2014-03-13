#include <stdio.h>

// van egy Foo nevu osztaly
// de itt meg nem definialhatjuk
class Foo;

class Quux
{
public:
	inline void modifyFoo(Foo &f);
	
	void action(Foo &f);
};

class Foo
{
	int a;
public:
	
	friend class Bar;
	friend void Quux::modifyFoo(Foo &f);
	friend int a(const Foo &f);
};

class Bar
{
public:
	int something(const Foo &f);
};

int Bar::something(const Foo &f)
{
	// friend nelkul nem fordulna
	return f.a*f.a;
}
inline void Quux::modifyFoo(Foo &f)
{
	f.a = 5;
}

void Quux::action(Foo &f)
{
	// mivel Foo-nak nincsenek
	// publikus elemei, es nem
	// vagyunk baratok, sokat
	// nem tudok itt kezdeni vele
}

int a(const Foo &f)
{
	return f.a;
}

int main()
{
	return 0;
}
