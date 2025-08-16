#include "../includes/WrongAnimal.hpp"

//Operators-----------------------------------------------------------

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & right)
{
	this->_type = right._type;
	return (*this);
}

//Constructors/destructors--------------------------------------------

WrongAnimal::WrongAnimal(void): _type("WrongAnimal")
{
	std::cout << GRAY "WrongAnimal constructor called" RESET << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(std::string const & name): _type(name)
{
	std::cout << GRAY "WrongAnimal named constructor called" RESET << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const & right)
{
	std::cout << GRAY "WrongAnimal copy constructor called" RESET << std::endl;
	*this = right;
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << GRAY "WrongAnimal destructor called" RESET << std::endl;
	return ;
}

//Member functions----------------------------------------------------

void WrongAnimal::makeSound(void) const
{
	std::cout << YELLOW "The Wrong animal don't know what sound to make." RESET << std::endl;
	return ;
}

std::string const & WrongAnimal::getType(void) const
{
	return this->_type;
}

