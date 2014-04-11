#include <iostream>

template<typename T> T min(const T &a, const T &b)
{
	return a < b ? a : b;
}

// a template kulcsszo parameterenel a class szo
// ugyanazt jelenti, mint a typename, T tetszoleges
// tipus lehet, nem csak class
template<class T> T max(const T &a, const T &b)
{
	return a < b ? b : a;
}

int main()
{
	std::cout << min(5, 3)/2 << std::endl;
	std::cout << max(5, 3)/2 << std::endl;
	std::cout << max<float>(5, 3)/2 << std::endl;

	return 0;
}
