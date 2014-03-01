#ifndef _POINT_H_
#define _POINT_H_

// a class ugyanaz, mint a struct, csak az alapertelmezett
// lathatosag private
class Point
{
	int x, y;
public:
	// konstruktor
	Point(int initX, int initY);
	// destruktor
	~Point();
	
	// inline fuggvenyek a headerbe kerulnek
	inline int getX() { return x; }
	// deklaralhatjuk a fuggvenyen kivul is,
	// ajanlott, az attekintheto fuggvenylistahoz
	inline int getY();
	
	// nem inline fuggveny ne keruljon a headerbe
	Point offset(int offsetX, int offetY);
};

// igy jeloljuk, hogy a Point getY fuggvenyenek az
// implementacioja kovetkezik
inline int Point::getY() { return y; }

#endif
