#include <iostream>

using namespace std;

struct Pair
{
	inline Pair() { }
	inline Pair(int first, int second):
		first(first), second(second)
	{
	}
	
	int first, second;
};

class TwoLetters
{
	char letters[2];
	Pair p;
	
	inline TwoLetters(char first, char second)
	{
		letters[0] = first;
		letters[1] = second;
		buildPair();
	}
	
	void buildPair()
	{
		p = Pair(letters[0], letters[1]);
	}
public:
	inline TwoLetters(const char *s)
	{
		letters[0] = s[0];
		letters[1] = s[1];
		buildPair();
	}
	
	// barmilyen osztallyal vagy strukturaval visszaterhet
	inline const Pair* operator->() const
	{
		return &p;
	}
	
	// minden tagfuggvenynek van egy implicit parametere,
	// aminek az erteke a this
	// a tipusa pedig ennel az osztalynal TwoLetters* vagy
	// const TwoLetters* - ez esetben az elobbi
	
	// ez nem operator overload specifikus dolog, csak azzal
	// illusztraltam
	inline Pair* operator->()
	{
		return &p;
	}
	
	inline TwoLetters operator,(const TwoLetters &other) const
	{
		return TwoLetters(letters[0], other.letters[1]);
	}
	
	inline char get(int index) const
	{
		return letters[index];
	}
};

ostream& operator<<(ostream &stream, const TwoLetters &l)
{
	return stream << l.get(0) << l.get(1);
}

int main()
{
	TwoLetters ab("ab");
	TwoLetters cd("cd");
	
	cout << ab->first << " " << ab->second << endl;
	cout << (ab, cd) << endl;
	
	return 0;
}
