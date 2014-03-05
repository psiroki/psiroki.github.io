#include "stringbuffer.h"
#include <string.h>

StringBuffer::StringBuffer(int length)
{
	buffer = new char[length];
	// length = length-et nem irhatok...
	// az elso a tagvaltozora, a masodik
	// a lokalis valtozora hivatkozik
	this->length = length;
}

StringBuffer::~StringBuffer()
{
	delete[] buffer;
}

StringBuffer::StringBuffer(const StringBuffer &other)
{
	length = other.getLength();
	buffer = new char[length];
	memcpy(buffer, other.whole(), length);
}
