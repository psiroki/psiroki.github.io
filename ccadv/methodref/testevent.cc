#include "event.h"
#include <iostream>

class SomeEvent
{
	const int value;
public:
	SomeEvent(int value): value(value) { }
	inline int getValue() const { return value; }
};

void registerEvent(const event::Slot<SomeEvent> &adapter);

class AnyClass
{
	void respondToSomeEvent(const SomeEvent &event);
public:
	AnyClass();
};

AnyClass::AnyClass()
{
	registerEvent(event::Adapter<SomeEvent, AnyClass>(this, &AnyClass::respondToSomeEvent));
}

void AnyClass::respondToSomeEvent(const SomeEvent &event)
{
	std::cout << "AnyClass::respondToSomeEvent(SomeEvent(" << event.getValue() << "))" << std::endl;
}

event::Slot<SomeEvent> slot;

void registerEvent(const event::Slot<SomeEvent> &adapter)
{
	slot = adapter;
}

int main()
{
	AnyClass obj;
	slot(SomeEvent(3));
}

