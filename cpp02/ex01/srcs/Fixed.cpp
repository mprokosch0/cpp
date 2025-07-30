
#include "../includes/Fixed.hpp"

Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << GRAY "Fixed operator = called" RESET << std::endl;
	this->_value = rhs.getRawBits();
	return *this;
}

Fixed::Fixed(void): _value(0)
{
	std::cout << GRAY "Fixed default constructor called" RESET << std::endl;
	return ;
}

Fixed::Fixed(int const nb): _value(nb << _fracBits)
{
	std::cout << GRAY "Fixed int constructor called" RESET << std::endl;
	return ;
}

Fixed::Fixed(float const nb)
{
	this->_value = roundf(nb * (1 << _fracBits));
	std::cout << GRAY "Fixed float constructor called" RESET << std::endl;
	return ;
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
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
	return ;
}

int	Fixed::toInt(void) const
{
	return (this->getRawBits() >> _fracBits);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->getRawBits() / (1 << _fracBits));
}

std::ostream &operator<<(std::ostream &o, Fixed const &obj)
{
	o << obj.toFloat();
	return (o);
}