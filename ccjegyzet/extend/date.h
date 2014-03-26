#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
#include <iomanip>

struct Date
{
	int year, month, day;
};

inline std::ostream& operator<<(std::ostream &stream, const Date &d)
{
	return stream << d.year << "-" << std::setw(2) << std::setfill('0') << d.month <<
		"-" << std::setw(2) << std::setfill('0') << d.day;
}

struct DateTime: public Date
{
	int hour, minute, second;
};

inline std::ostream& operator<<(std::ostream &stream, const DateTime &dt)
{
	const Date &d(dt);
	return stream << d << " " << dt.hour << ":" <<
		std::setw(2) << std::setfill('0') << dt.minute << ":" <<
		std::setw(2) << std::setfill('0') << dt.second;
}

#endif
