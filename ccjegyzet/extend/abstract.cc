#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Stringifiable
{
public:
	// absztrakt:
	virtual string stringify() const = 0;
};

class Number: public Stringifiable
{
	const int value;
public:
	inline Number(int value): value(value) { }
	
	virtual string stringify() const;
};

string Number::stringify() const
{
	stringstream s;
	s << value;
	return s.str();
}

class Text: public Stringifiable
{
	const string value;
public:
	inline Text(const string &value): value(value) { }
	
	virtual string stringify() const;
};

string Text::stringify() const
{
	return value;
}

void print(const Stringifiable &s)
{
	cout << s.stringify() << endl;
}

int main()
{
	Number num(5);
	Text txt("foo");
#ifdef FAILCOMPILATION
	// absztrakt osztalyt nem lehet
	// peldanyositani
	
	// ezt a reszt csak a
	// -D FAILCOMPILATION
	// parameter hozzaadasaval
	// veszi figyelembe a fordito
	
	// se igy:
	Stringifiable s;
	// es persze igy sem:
	new Stringifiable();
#endif
	
	print(num);
	print(txt);
	
	return 0;
}
