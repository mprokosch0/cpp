#include "../includes/WrongCat.hpp"

//Operators-----------------------------------------------------------

WrongCat & WrongCat::operator=(WrongCat const & right)
{
	this->_type = right._type;
	return (*this);
}

//Constructors/destructors--------------------------------------------

WrongCat::WrongCat(void): WrongAnimal("Wrongcat")
{
	std::cout << GRAY "MEOOW constructor called" RESET << std::endl;
	return ;
}

WrongCat::WrongCat(WrongCat const & right)
{
	std::cout << GRAY "WrongCat copy constructor called" RESET << std::endl;
	*this = right;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << GRAY "MEOOW destructor called" RESET << std::endl;
	return ;
}

//Member functions----------------------------------------------------

void WrongCat::makeSound(void) const
{
	std::cout << YELLOW "The Wrong cat says Wrongmeeoooww." RESET << std::endl;
	return ;
}
