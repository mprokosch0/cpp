
#include "../includes/Fixed.hpp"

Fixed::Fixed(void): _value(0)
{
	std::cout << GRAY "Fixed default constructor called" RESET << std::endl;
	return ;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << GRAY "Fixed operator = called" RESET << std::endl;
	this->_value = rhs.getRawBits();
	return *this;
}

Fixed::Fixed(Fixed const &rhs)
{
	std::cout << GRAY "Fixed copy constructor called" RESET << std::endl;
	*this = rhs;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << GRAY "Fixed destructor called" RESET << std::endl;
	return ;
}

int Fixed::getRawBits(void) const
{
	std::cout << GRAY "getRawBits member function called" RESET << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << GRAY "setRawBits member function called" RESET << std::endl;
	this->_value = raw;
	return ;
}