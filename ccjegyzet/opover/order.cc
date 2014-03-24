#include <iostream>

class Counter
{
	static int current;
	const int value;
public:
	Counter(): value(current++) { }
	
	inline const Counter& operator+(const Counter &other) const
	{
		std::cout << "Counter(" << value << ") + Counter(" << other.value << ")" << std::endl;
		return *this;
	}
	
	inline const Counter& operator=(const Counter &other) const
	{
		std::cout << "Counter(" << value << ") = Counter(" << other.value << ")" << std::endl;
		return *this;
	}
	
	friend std::ostream& operator<<(std::ostream &stream, const Counter &other);
};

int Counter::current = 0;

std::ostream& operator<<(std::ostream &stream, const Counter &other)
{
	return stream << "Counter(" << other.value << ")";
}

int main()
{
	Counter c1, c2, c3, c4, c5;
	std::cout << c1 << ", " << c2 << "... " << c5 << "\n" << std::endl;
	c1 + c2 + c3 + c4 + c5;
	std::cout << std::endl;
	c1 = c2 = c3 = c4 = c5;
	
	return 0;
}
