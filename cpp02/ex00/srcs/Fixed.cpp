
#include "../includes/Fixed.hpp"

Fixed::Fixed(void): _value(0)
{
	std::cout << "Fixed default constructor called" << std::endl;
	return ;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Fixed operator = called" << std::endl;
	this->_value = rhs.getRawBits();
	return *this;
}

Fixed::Fixed(Fixed const &rhs)
{
	std::cout << "Fixed copy constructor called" << std::endl;
	*this = rhs;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Fixed destructor called" << std::endl;
	return ;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
	return ;
}