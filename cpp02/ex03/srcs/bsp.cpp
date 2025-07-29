
#include "../includes/Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed as_x(point.getX() - a.getY());
	Fixed as_y(point.getX() - a.getY());

	bool s_ab = (b.getX() - a.getX()) * as_y - (b.getY() - a.getY() * as_x) > 0;

	if ((c.getX() - a.getX()) * as_y - (c.getY() - a.getY()) * as_x > 0 == s_ab)
		return false;
	if ((c.getX() - b.getX()) * (point.getY() - b.getY())
			- (c.getY() - b.getY()) * (point.getX() - b.getX()) > 0 != s_ab)
		return false;
	return true;
}
