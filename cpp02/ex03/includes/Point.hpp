
#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	
	public:
		Point(void);
		Point(float const x, float const y);
		Point(Point const & right);
		~Point(void);
	
	public:
		Point & operator=(Point const &right);
		Fixed getX(void) const;
		Fixed getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif