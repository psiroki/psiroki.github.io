// az alabbi define kell a Visual C++-hoz kapott C/C++ implementaciohoz,
// hogy legyen M_PI-nk
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

int main()
{
	double radius;
	std::cout << "Radius:" << std::endl;
	std::cin >> radius;
	std::cout << "Circumference: " << radius*2.0*M_PI << std::endl;
	return 0;
}
