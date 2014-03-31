#include <iostream>
#include <cstdlib>

using namespace std;

class Number
{
	int value;
public:
	inline Number(int value): value(value)
	{
		cout << "\tNumber(int value = " << value << ")" << endl;
	}
	
	explicit inline Number(const char *num): value(atoi(num))
	{
		cout << "\tNumber(const char* value = \"" << value << "\")" << endl;
	}
	
	inline operator int() const
	{
		cout << "\tNumber(" << value << ")::operator int() const" << endl;
		return value;
	}
	
	inline int operator=(int other)
	{
		cout << "\tint Number(" << value << ")::operator=(int other = " << other << ")" << endl;
		value = other;
		return value;
	}
};

void print(Number n)
{
	int i = n;
	cout << "print(" << i << ")" << endl;
}

void printRef(const Number &n)
{
	int i = n;
	cout << "printRef(" << i << ")" << endl;
}

int main()
{
	// az alabbi ketto ekvivalens
	cout << "Constructor calls:" << endl;
	Number n1 = 1;
	Number n2(2);
	
	// az explicit kulcsszo miatt ez nem:
//	Number n3 = "3";
	// de ez igen:
	Number n4("4");
	
	// szinten explicit miatt ezek nem:
//	print("5");
//	printRef("5");
	// de ez igen:
	print(Number("5"));
	printRef(Number("5"));
	
	print(6);
	print(Number(6));
	// ha a referencia nem lenne konstans, ezt nem engedne:
	printRef(7);
	printRef(Number(7));
	
	cout << "Assignment operator calls:" << endl;
	n1 = n2 = n4 = 8;
	
	cout << "Cast operator call:" << endl;
	cout << n1 << endl;

	return 0;
}
