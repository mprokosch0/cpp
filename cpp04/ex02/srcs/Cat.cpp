#include "../includes/Cat.hpp"
#include "../includes/Brain.hpp"

//Operators-----------------------------------------------------------

Cat & Cat::operator=(Cat const & right)
{
	this->_type = right._type;
	if (this->_ideas)
		*this->_ideas = *right._ideas;
	return (*this);
}

//Constructors/destructors--------------------------------------------

Cat::Cat(void): Animal("cat")
{
	std::cout << GRAY "MEOOW constructor called" RESET << std::endl;
	this->_ideas = new Brain();
	return ;
}

Cat::Cat(Cat const & right)
{
	std::cout << GRAY "Cat copy constructor called" RESET << std::endl;
	this->_ideas = new Brain();
	*this = right;
	return ;
}

Cat::~Cat(void)
{
	std::cout << GRAY "MEOOW destructor called" RESET << std::endl;
	if (this->_ideas)
		delete this->_ideas;
	return ;
}

//Member functions----------------------------------------------------

void Cat::GetIdeas()
{
	if (this->_ideas)
		this->_ideas->GetIdeas();
	return ;
}

void Cat::SetIdea(int nb, std::string const & idea)
{
	if (!this->_ideas)
	{
		std::cout << RED "Set Idea error: the cat has no brain" << std::endl;
		return ;
	}
	if (nb < 0 || nb >= 100)
	{
		std::cout << RED "Idea number not in range" RESET << std::endl;
		return ;
	}
	std::cout << YELLOW "Idea no " << nb << " is setted as <" << idea << ">" RESET << std::endl;
	this->_ideas->SetIdea(nb, idea);
	return ;
}

void Cat::makeSound(void) const
{
	std::cout << YELLOW "The cat says meeoooww." RESET << std::endl;
	return ;
}
