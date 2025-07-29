
#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed _x;
		Fixed _y;
	
	public:
		Point(void);
		Point(Fixed const x, Fixed const y);
		Point(Point const & right);
		~Point(void);
	
	public:
		Point & operator=(Point const &right);
		Fixed getX(void) const;
		Fixed getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif