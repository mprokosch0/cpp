
#include "../includes/Fixed.hpp"

//Operators-----------------------------------------------------------------

Fixed &Fixed::operator=(Fixed const &right)
{
	//std::cout << "Fixed operator = called" << std::endl;
	this->_value = right.getRawBits();
	return *this;
}

int Fixed::operator>(Fixed const &right) const
{
	if (this->getRawBits() > right.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator<(Fixed const &right) const
{
	if (this->getRawBits() < right.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator>=(Fixed const &right) const
{
	if (this->getRawBits() >= right.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator<=(Fixed const &right) const
{
	if (this->getRawBits() <= right.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator==(Fixed const &right) const
{
	if (this->getRawBits() == right.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator!=(Fixed const &right) const
{
	if (this->getRawBits() != right.getRawBits())
		return (1);
	return (0);
}

Fixed Fixed::operator+(Fixed const &right) const
{
	Fixed result;
	//std::cout << "Fixed operator + called" << std::endl;
	result.setRawBits(this->getRawBits() + right.getRawBits());
	return (result);
}

Fixed Fixed::operator-(Fixed const &right) const
{
	Fixed result;
	//std::cout << "Fixed operator - called" << std::endl;
	result.setRawBits(this->getRawBits() - right.getRawBits());
	return (result);
}

Fixed Fixed::operator*(Fixed const &right) const
{
	Fixed result;
	//std::cout << "Fixed operator * called" << std::endl;
	result.setRawBits((this->getRawBits() * right.getRawBits()) >> _fracBits);
	return (result);
}

Fixed Fixed::operator/(Fixed const &right) const
{
	Fixed result;
	//std::cout << "Fixed operator / called" << std::endl;
	result.setRawBits((this->getRawBits() >> _fracBits) * right.getRawBits());
	return (result);
}

std::ostream &operator<<(std::ostream &o, Fixed const &obj)
{
	o << obj.toFloat();
	return (o);
}

Fixed &Fixed::operator--(void)
{
	//std::cout << "Fixed operator -- (prefix) called" << std::endl;
	this->_value--;
	return (*this);
}

Fixed &Fixed::operator++(void)
{
	//std::cout << "Fixed operator ++ (prefix) called" << std::endl;
	this->_value++;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed result = *this;
	//std::cout << "Fixed operator -- (postfix) called" << std::endl;
	this->_value--;
	return (result);	
}

Fixed Fixed::operator++(int)
{
	Fixed result = *this;
	//std::cout << "Fixed operator ++ (postfix) called" << std::endl;
	this->_value++;
	return (result);
}


//Constructors / Destructors---------------------------------------------------

Fixed::Fixed(void): _value(0)
{
	//std::cout << "Fixed default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int const nb): _value(nb << _fracBits)
{
	//std::cout << "Fixed int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(float const nb)
{
	this->_value = roundf(nb * (1 << _fracBits));
	//std::cout << "Fixed float constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const &rhs)
{
	//std::cout << "Fixed copy constructor called" << std::endl;
	*this = rhs;
	return ;
}

Fixed::~Fixed(void)
{
	//std::cout << "Fixed destructor called" << std::endl;
	return ;
}

//Member functions------------------------------------------------------------

Fixed Fixed::min(Fixed &nb1, Fixed &nb2)
{
	if (nb1 < nb2)
		return nb1;
	return nb2;
}

Fixed Fixed::max(Fixed &nb1, Fixed &nb2)
{
	if (nb1 > nb2)
		return nb1;
	return nb2;
}

Fixed const & Fixed::min(Fixed const &nb1, Fixed const &nb2)
{
	if (nb1 < nb2)
		return nb1;
	return nb2;
}

Fixed const & Fixed::max(Fixed const &nb1, Fixed const &nb2)
{
	if (nb1 > nb2)
		return nb1;
	return nb2;
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
