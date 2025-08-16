#include "../includes/Dog.hpp"

//Operators-----------------------------------------------------------

Dog & Dog::operator=(Dog const & right)
{
	this->_type = right._type;
	return (*this);
}

//Constructors/destructors--------------------------------------------

Dog::Dog(void): Animal("Dog")
{
	std::cout << GRAY "WOUF constructor called" RESET << std::endl;
	return ;
}

Dog::Dog(Dog const & right)
{
	std::cout << GRAY "Dog copy constructor called" RESET << std::endl;
	*this = right;
	return ;
}

Dog::~Dog(void)
{
	std::cout << GRAY "WOUF destructor called" RESET << std::endl;
	return ;
}

//Member functions----------------------------------------------------

void Dog::makeSound(void) const
{
	std::cout << YELLOW "The Dog says wouuuf." RESET << std::endl;
	return ;
}
