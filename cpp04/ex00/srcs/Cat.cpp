#include "../includes/Cat.hpp"

//Operators-----------------------------------------------------------

Cat & Cat::operator=(Cat const & right)
{
	this->_type = right._type;
	return (*this);
}

//Constructors/destructors--------------------------------------------

Cat::Cat(void): Animal("cat")
{
	std::cout << GRAY "MEOOW constructor called" RESET << std::endl;
	return ;
}

Cat::Cat(Cat const & right)
{
	std::cout << GRAY "Cat copy constructor called" RESET << std::endl;
	*this = right;
	return ;
}

Cat::~Cat(void)
{
	std::cout << GRAY "MEOOW destructor called" RESET << std::endl;
	return ;
}

//Member functions----------------------------------------------------

void Cat::makeSound(void) const
{
	std::cout << YELLOW "The cat says meeoooww." RESET << std::endl;
	return ;
}
