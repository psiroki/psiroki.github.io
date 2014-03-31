#include <iostream>

using namespace std;

int main()
{
	int num = 0x40490fdb;
	float f = *reinterpret_cast<float*>(&num);
	
	cout << f << endl;
	
	return 0;
}
