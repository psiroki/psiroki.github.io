#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <cmath>

const double R_EARTH = 6371.009; // km

class GeoPoint
{
	const double latitude;
	const double longitude;
public:
	inline GeoPoint(double latitude, double longitude):
		latitude(latitude),
		longitude(longitude)
	{
	}
	
	GeoPoint diff(const GeoPoint &other) const;
	
	inline double getLatitude() const { return latitude; }
	inline double getLongitude() const { return longitude; }
};

GeoPoint GeoPoint::diff(const GeoPoint &other) const
{
	return GeoPoint(latitude-other.latitude, longitude-other.longitude);
}

const double TO_RAD = M_PI/180.0;

double toRad(double degrees)
{
	return degrees * TO_RAD;
}

GeoPoint readGeoPoint(std::ifstream &s)
{
	double lt, ln;
	s >> lt >> ln;
	return GeoPoint(toRad(lt), toRad(ln));
}

double distanceInKm(const GeoPoint &p1, const GeoPoint &p2)
{
	GeoPoint dp = p2.diff(p1);
	double a =
		std::sin(dp.getLatitude()*0.5) * std::sin(dp.getLatitude()/2) +
			std::sin(dp.getLongitude()*0.5) * std::sin(dp.getLongitude()*0.5) *
			std::cos(p1.getLatitude()) * std::cos(p2.getLatitude()); 
	double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1-a)); 
	return R_EARTH * c;
}

int main()
{
	std::ifstream in("coords.txt");
	// ha nem szoveges, akkor: in("coords.bin", std::ios::in | std::ios::binary);
	std::ofstream out("distances.txt", std::ios::out | std::ios::trunc);
	// ios::trunc: lenullazzuk a file hosszat
	if(!in)
	{
		std::cerr << "missing coords.txt" << std::endl;
		return -1;
	}
	
	if(!out)
	{
		std::cerr << "can't write distances.txt" << std::endl;
		return -1;
	}
	
	int line = 0;
	do {
		GeoPoint p1 = readGeoPoint(in);
		
		if(in.eof())
			break;
		
		GeoPoint p2 = readGeoPoint(in);
		
		out << "Distance for line " << ++line << ": " << distanceInKm(p1, p2) << " km" << std::endl;
	} while(!in.eof());
	
	in.close();
	out.close();
	
	return 0;
}
