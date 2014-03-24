#include <iostream>

class Poly3
{
	double p[4];
public:
	inline Poly3(double a, double b, double c, double d)
	{
		p[3] = a;
		p[2] = b;
		p[1] = c;
		p[0] = d;
	}
	
	double operator()(double x) const
	{
		return p[3]*x*x*x + p[2]*x*x + p[1]*x + p[0];
	}
	
	double operator[](int index) const
	{
		return p[index];
	}
};

int main()
{
	Poly3 smoothstep(-2, 3, 0, 0);
	
	for(double d = 0; d <= 1.0; d += 0.125)
		std::cout << "smoothstep(" << d <<") = " << smoothstep(d) << std::endl;
	
	std::cout << std::endl;
	
	for(int i=0; i<4; ++i)
	{
		if(i > 0)
			std::cout << " + ";
		std::cout << smoothstep[i] << "*x^" << i;
	}
	
	std::cout << std::endl;
	
	return 0;
}
