#include <iostream>

int main()
{
	std::istream &in = std::cin;
	std::ostream &out = std::cout;
	
	char c;
	
	// 1 karakter
	in.get(c);
	out.put(c).put(c);
	
	out << std::endl;
	
	// binaris kimenet
	int word;
	in.read((char*)&word, sizeof(word));
	out.write((char*)&word, sizeof(word));
	
	out << std::endl;
	
	char line[256];
	in.getline(line, sizeof(line));
	out << line << std::endl;
	
	return 0;
}
