
#include "../includes/Point.hpp"

//overload operators---------------------------------------------------

Point &Point::operator=(Point const &right)
{
	std::cout << GRAY "Point operator = called" RESET << std::endl;
	this->_x = right._x;
	this->_y = right._y;
	return (*this);
}

//constructors/destructors---------------------------------------------

Point::Point(void): _x(0), _y(0)
{
	std::cout << GRAY "Default point constructor called" RESET << std::endl;
	return ;
}

Point::Point(Fixed const x, Fixed const y): _x(x), _y(y)
{
	std::cout << GRAY "2-const point constructor called" RESET << std::endl;
	return ;
}

Point::Point(Point const & right)
{
	std::cout << GRAY "Copy point constructor called" RESET << std::endl;
	*this = right;
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