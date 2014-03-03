#pragma once

#include <string.h>

namespace event {

template<class Event> class Slot
{
public:
	typedef void (*EventCallback)(void *obj, const void *method, const Event &event);
private:
	void * obj;
	// the key to this implementation is that it
	// doesn't need any memory allocation, so we
	// have to fit everything statically
	// member function pointers may get as big as
	// 20 bytes (depending on the compiler) with
	// 32 bit addresses, so let's use allocate 32
	// bytes, just to be safe (or double of that
	// with 64 bit addresses)
	char methodPointer[8*sizeof(void*)];
	EventCallback callback;
public:
	/// Null slot
	inline Slot(): obj(0), callback(0)
	{
		memset(methodPointer, 0, sizeof(methodPointer));
	}
	
	inline Slot(void *obj, const void * const *methodPointer, int pointerSize, EventCallback callback):
		obj(obj), callback(callback)
	{
		memcpy(this->methodPointer, methodPointer, pointerSize);
	}

	inline void operator()(const Event &event) const
	{
		if(callback)
		{
			const void *pp = methodPointer;
			callback(obj, methodPointer, event);
		}
	}
};

template<class Event, class T> class Adapter
{
public:
	typedef void (T::*Callback)(const Event &event);
private:
	T* const receiver;
	const Callback callback;
public:
	inline Adapter(T *receiver, Callback callback):
		receiver(receiver), callback(callback)
	{
	}
	
	inline operator Slot<Event>()
	{
		return Slot<Event>(receiver, reinterpret_cast<const void* const *>(&callback),
			sizeof(callback), &handleCallbacks);
	}
	
	inline static void handleCallbacks(void *obj, const void *method, const Event &event)
	{
		T *receiver(reinterpret_cast<T*>(obj));
		Callback callback;
		memcpy(&callback, method, sizeof(callback));
		(receiver->*callback)(event);
	}
};

}
