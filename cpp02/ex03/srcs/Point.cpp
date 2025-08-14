
#include "../includes/Point.hpp"

//overload operators---------------------------------------------------

Point &Point::operator=(Point const &right)
{
	std::cout << GRAY "Point operator = called" RESET << std::endl;
	(void)right;
	return (*this);
}

//constructors/destructors---------------------------------------------

Point::Point(void): _x(0), _y(0)
{
	std::cout << GRAY "Default point constructor called" RESET << std::endl;
	return ;
}

Point::Point(float const x, float const y): _x(x), _y(y)
{
	std::cout << GRAY "2-const point constructor called" RESET << std::endl;
	return ;
}

Point::Point(Point const & right): _x(right.getX()), _y(right.getY())
{
	std::cout << GRAY "Copy point constructor called" RESET << std::endl;
	return ;
}

Point::~Point(void)
{
	std::cout << GRAY "Point destructor called" RESET << std::endl;
	return ;
}

//member functions--------------------------------------------------

Fixed Point::getX(void) const
{
	return (this->_x);
}

Fixed Point::getY(void) const
{
	return (this->_y);
}