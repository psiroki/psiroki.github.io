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

class Intifiable
{
public:
	virtual int intify() const = 0;
};

class Number: public Stringifiable, public Intifiable
{
	const int value;
public:
	inline Number(int value): value(value) { }
	
	virtual string stringify() const;
	virtual int intify() const;
};

string Number::stringify() const
{
	stringstream s;
	s << value;
	return s.str();
}

int Number::intify() const
{
	return value;
}

void print(const Stringifiable &s)
{
	cout << s.stringify() << endl;
}

int sum(const Intifiable &left, const Intifiable &right)
{
	return left.intify() + right.intify();
}

int main()
{
	Number num(5);
	Number six(6);
	
	print(num);
	print(Number(sum(num, six)));
	
	return 0;
}
