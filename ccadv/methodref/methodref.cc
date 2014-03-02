#include <iostream>

class SomeEvent
{
	const int value;
public:
	SomeEvent(int value): value(value) { }
	inline int getValue() const { return value; }
};

typedef void (*SomeEventCallback)(void *obj, const void *method, const SomeEvent &event);

class SomeSlot
{
	void * obj;
	const void *method;
	SomeEventCallback callback;
public:
	/// Null slot
	SomeSlot(): obj(0), method(0), callback(0)
	{
	}
	
	SomeSlot(void *obj, const void *method, SomeEventCallback callback):
		obj(obj), method(method), callback(callback)
	{
	}

	inline void operator()(const SomeEvent &event) const
	{
		if(method)
			callback(obj, method, event);
	}
};

template<class T> class SomeAdapter
{
	typedef void (T::*Callback)(const SomeEvent &event);
	T* const receiver;
	const Callback callback;
public:
	inline SomeAdapter(T *receiver, void (T::*callback)(const SomeEvent &event)):
		receiver(receiver), callback(callback)
	{
	}
	
	inline operator SomeSlot()
	{
		return SomeSlot(receiver, *reinterpret_cast<const void* const *>(&callback),
			&handleCallbacks);
	}
	
	inline static void handleCallbacks(void *obj, const void *method, const SomeEvent &event)
	{
		T *receiver(reinterpret_cast<T*>(obj));
		Callback callback = *reinterpret_cast<const Callback*>(&method);
		(receiver->*callback)(event);
	}
};

void registerEvent(const SomeSlot &adapter);

class AnyClass
{
	void respondToSomeEvent(const SomeEvent &event);
public:
	AnyClass();
};

AnyClass::AnyClass()
{
	registerEvent(SomeAdapter<AnyClass>(this, &AnyClass::respondToSomeEvent));
}

void AnyClass::respondToSomeEvent(const SomeEvent &event)
{
	std::cout << "AnyClass::respondToSomeEvent(SomeEvent(" << event.getValue() << "))" << std::endl;
}

SomeSlot slot;

void registerEvent(const SomeSlot &adapter)
{
	slot = adapter;
}

int main()
{
	AnyClass obj;
	slot(SomeEvent(3));
}
