
#include "../includes/Fixed.hpp"

Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Fixed operator = called" << std::endl;
	this->_value = rhs.getRawBits();
	return *this;
}

Fixed::Fixed(void): _value(0)
{
	std::cout << "Fixed default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int const nb): _value(nb << _fracBits)
{
	std::cout << "Fixed int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(float const nb)
{
	this->_value = roundf(nb * (1 << _fracBits));
	std::cout << "Fixed float constructor called" << std::endl;
	return ;
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