
#include "../includes/Point.hpp"

static Fixed sign(Point const &p1, Point const &p2, Point const &p3)
{
	Point vect1((p1.getX().toFloat() - p3.getX().toFloat()), p1.getY().toFloat() - p3.getY().toFloat());
	Point vect2(p2.getX().toFloat() - p3.getX().toFloat(), p2.getY().toFloat() - p3.getY().toFloat());
	
	return (vect1.getX() * vect2.getY() - vect1.getY() * vect2.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1 = sign(point, a, b);
	Fixed d2 = sign(point, b, c);
	Fixed d3 = sign(point, c, a);

	bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);
}
