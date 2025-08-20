#include "../includes/Dog.hpp"
#include "../includes/Brain.hpp"

//Operators-----------------------------------------------------------

Dog & Dog::operator=(Dog const & right)
{
	this->_type = right._type;
	if (this->_ideas)
		*this->_ideas = *right._ideas;
	return (*this);
}

//Constructors/destructors--------------------------------------------

Dog::Dog(void): Animal("Dog")
{
	std::cout << GRAY "WOUF constructor called" RESET << std::endl;
	this->_ideas = new Brain();
	return ;
}

Dog::Dog(Dog const & right)
{
	std::cout << GRAY "Dog copy constructor called" RESET << std::endl;
	this->_ideas = new Brain();
	*this = right;
	return ;
}

Dog::~Dog(void)
{
	std::cout << GRAY "WOUF destructor called" RESET << std::endl;
	if (this->_ideas)
		delete this->_ideas;
	return ;
}

//Member functions----------------------------------------------------

void Dog::GetIdeas()
{
	if (this->_ideas)
		this->_ideas->GetIdeas();
	return ;
}

void Dog::SetIdea(int nb, std::string const & idea)
{
	if (!this->_ideas)
	{
		std::cout << RED "Set Idea error: the dog has no brain" << std::endl;
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

void Dog::makeSound(void) const
{
	std::cout << YELLOW "The Dog says wouuuf." RESET << std::endl;
	return ;
}
