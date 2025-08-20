#include "../includes/Animal.hpp"

//Operators-----------------------------------------------------------

Animal & Animal::operator=(Animal const & right)
{
	this->_type = right._type;
	return (*this);
}

//Constructors/destructors--------------------------------------------

Animal::Animal(void): _type("Animal")
{
	std::cout << GRAY "Animal constructor called" RESET << std::endl;
	return ;
}

Animal::Animal(std::string const & name): _type(name)
{
	std::cout << GRAY "Animal named constructor called" RESET << std::endl;
	return ;
}

Animal::Animal(Animal const & right)
{
	std::cout << GRAY "Animal copy constructor called" RESET << std::endl;
	*this = right;
	return ;
}

Animal::~Animal(void)
{
	std::cout << GRAY "Animal destructor called" RESET << std::endl;
	return ;
}

//Member functions----------------------------------------------------

void Animal::makeSound(void) const
{
	std::cout << YELLOW "The animal don't know what sound to make." RESET << std::endl;
	return ;
}

std::string const & Animal::getType(void) const
{
	return this->_type;
}

