#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T, int MAX_MARKS=256> class MarkRelease
{
	char *objectBuffer;
	int size;
	int count;
	int marks[MAX_MARKS];
	int numMarks;
public:
	MarkRelease(int arraySize);
	~MarkRelease()
	{
		delete[] objectBuffer;
	}
	
	void mark()
	{
		if(numMarks >= MAX_MARKS)
			throw logic_error("Too many marks");
		marks[numMarks++] = count;
	}
	
	void release()
	{
		if(numMarks <= 0 && count <= 0)
			throw logic_error("No more marks to set back to");
		int newCount;
		if(numMarks > 0)
			newCount = marks[--numMarks];
		else
			newCount = 0;
		T *objects = reinterpret_cast<T*>(objectBuffer);
		// "placement delete" nincs, ilyenkor egyszeruen meghivjuk
		// a destruktort es majd char tombkent felszabaditjuk a teruletet
		// maga az objektum gyakorlatilag megsemmisultnek tekintheto,
		// a memoria alatta majd a ~MarkRelease()-ben fog felszabadulni
		for(int i=count-1; i >= newCount; --i)
			objects[i].~T();
		
		count = newCount;
	}
	
	T* allocate();
};

template<typename T, int MAX_MARKS=256>
MarkRelease<T, MAX_MARKS>::MarkRelease(int arraySize):
	objectBuffer(new char[arraySize*sizeof(T)]),
	size(arraySize),
	count(0),
	numMarks(0)
{
}

template<typename T, int MAX_MARKS=256>
T* MarkRelease<T, MAX_MARKS>::allocate()
{
	if(count >= size)
		throw logic_error("Buffer overflow");
	// ez a placement new, ahol nem allokal uj memoriateruletet
	// egyszeruen az altalunk megadott mutatoval fog visszaterni
	// a konstruktor meghivasa utan
	return new (objectBuffer+sizeof(T)*(count++)) T();
}

class A
{
	static int counter;
	const int number;
public:
	A(): number(counter++)
	{
		cout << "\tA(" << number << ")" << endl;
	}
	
	~A()
	{
		cout << "\t~A(" << number << ")" << endl;
	}
};

int A::counter = 0;

int main()
{
	MarkRelease<A> ml(24);
	ml.allocate();
	cout << "Mark" << endl;
	ml.mark();
	for(int i=0; i<8; ++i)
		ml.allocate();
	cout << "Mark" << endl;
	ml.mark();
	for(int i=0; i<3; ++i)
		ml.allocate();
	cout << "Release" << endl;
	ml.release();
	cout << "Release" << endl;
	ml.release();
	cout << "Release" << endl;
	ml.release();
	return 0;
}
