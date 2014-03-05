#ifndef _STRINGBUFFER_H_
#define _STRINGBUFFER_H_

class StringBuffer
{
	char *buffer;
	int length;
public:
	StringBuffer(int length);
	StringBuffer(const StringBuffer &other);
	~StringBuffer();
	
	inline char& at(int index) { return buffer[index]; }
	// a vegen a const kulcsszo azt jelzi,
	// hogy ezt a fuggvenyt meg lehet hivni
	// const StringBufferen is
	inline const char* whole() const
	{
		// ilyesmi nem ferne itt bele:
		// buffer = "foo";
		// mert itt most minden mezot
		// constnak lat
		return buffer;
	}
	
	inline int getLength() const { return length; }
};

#endif
