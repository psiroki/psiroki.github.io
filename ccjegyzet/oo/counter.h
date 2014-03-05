#ifndef _COUNTER_H_
#define _COUNTER_H_

// struct, class, majdnem teljesen mindegy
// demonstrativ cellal ez most legyen struct
struct Counter
{
	// mivel ez struct es nem class,
	// ezek publikusak - ennyi a kulonbseg
	Counter();
	~Counter();
	
	int getValue();
private:
	const int value;
};

// a vizsgan azert irjatok class-t, mert
// structot ritkan hasznalunk osztalydeklaraciora

#endif
