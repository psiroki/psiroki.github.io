#pragma once

namespace event {

template<class Event> class Slot
{
public:
	typedef void (*EventCallback)(void *obj, const void *method, const Event &event);
private:
	void * obj;
	const void *method;
	EventCallback callback;
public:
	/// Null slot
	inline Slot(): obj(0), method(0), callback(0)
	{
	}
	
	inline Slot(void *obj, const void *method, EventCallback callback):
		obj(obj), method(method), callback(callback)
	{
	}

	inline void operator()(const Event &event) const
	{
		if(method)
			callback(obj, method, event);
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
		return Slot<Event>(receiver, *reinterpret_cast<const void* const *>(&callback),
			&handleCallbacks);
	}
	
	inline static void handleCallbacks(void *obj, const void *method, const Event &event)
	{
		T *receiver(reinterpret_cast<T*>(obj));
		Callback callback = *reinterpret_cast<const Callback*>(&method);
		(receiver->*callback)(event);
	}
};

}
