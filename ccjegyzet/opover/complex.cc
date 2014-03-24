#include <iostream>

class Complex
{
	double re;
	double im;
public:
	inline Complex(): re(0), im(0) { }
	inline Complex(double real, double imaginary): re(real), im(imaginary) { }

	inline double real() const
	{
		return re;
	}
	
	inline double imaginary() const
	{
		return im;
	}
	
	// operatorok fuggveny szignaturajaban kulonosen fontos, hogy ahol csak lehet,
	// hasznaljuk a const kulcsszot
	
	// az operatorok a teljesseg igenye nelkul szerepelnek
	
	Complex operator+(const Complex &other) const
	{
		return Complex(re+other.re, im+other.im);
	}
	
	Complex operator*(const Complex &other) const
	{
		return Complex(re*other.re-im*other.im, re*other.im+im*other.re);
	}
	
	Complex operator*(double other) const
	{
		std::cout << "complex*double" << std::endl;
		return Complex(re*other, im*other);
	}
	
	// az operator=-re van egy implicit alapertelmezett implementacio,
	// ami egyszeruen lemasolja a mezoket
	// ez pontosan ugyanannyit tesz, tehat ilyen szempontbol felesleges
	Complex& operator=(const Complex &other)
	{
		if(this == &other)
			return *this;
		re = other.re;
		im = other.im;
		return *this;
	}
	
};

// barmelyik operatort definialhatjuk kivul is:
// a kulonbseg annyi, hogy az osztalyon belul definialt
// fuggvenyeknel a baloldali operandus mindig a this lesz
Complex operator*(double real, const Complex &complex)
{
	std::cout << "double*complex" << std::endl;
	return Complex(real*complex.real(), real*complex.imaginary());
	// ha hozzaadjuk az alabbi sort az osztalyhoz:
	// friend Complex operator*(double real, const Complex &complex);
	// akkor nezhetne igy is ki:
	// return Complex(real*complex.re, real*complex.im);
}

// itt pedig kulonosen hasznos, hogy nem kell feltetlen tagfuggvenynek lennie:
std::ostream& operator<<(std::ostream &stream, const Complex &complex)
{
	return stream << complex.real() << " + " << complex.imaginary() << "i";
}

int main()
{
	Complex c1(0.866, 0.5);	// e^(pi*i/6) - pi/6 rad = 30 fok
	Complex c2(3, 7);
	Complex c3 = c1 + c2;
	Complex c4 = c3*2;
	Complex c5 = 2*c4;
	Complex c6;
	
	c6 = c5;
	
	std::cout << c1 << std::endl <<
		c2 << std::endl <<
		c3 << std::endl <<
		c4 << std::endl <<
		c5 << std::endl <<
		c6 << std::endl;
	
	return 0;
}
