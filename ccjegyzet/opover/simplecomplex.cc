#include <iostream>

struct SimpleComplex
{
	double re, im;

	// ez sunyi modon adatveszteshez vezet,
	// nem ajanlott ilyen formaban implementalni
	// tessek egy real() fuggvenyt hasznalni,
	// ahol egyertelmu, hogy az imaginarius
	// reszt elvesztettuk
	
	// illusztracionak viszont megfelelt :)
	operator double() const
	{
		return re;
	}
};

std::ostream& operator<<(std::ostream &stream, const SimpleComplex &c)
{
	return stream << c.re << " + " << c.im << "i";
}

int main()
{
	SimpleComplex c = { 7, 5 };
	
	double d = c;
	
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	
	return 0;
}
