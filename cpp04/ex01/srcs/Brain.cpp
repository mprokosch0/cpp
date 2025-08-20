
#include "../includes/Brain.hpp"

//operators-----------------------------------------------------------------------

Brain & Brain::operator=(Brain const & right)
{
	if (this != &right)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = right._ideas[i];
	}
	return *this;
}

//Constructor/destructors---------------------------------------------------------

Brain::Brain(void)
{
	std::cout << GRAY "Brain default constructor called" RESET << std::endl;
	return ; 
}

Brain::Brain(Brain const & right)
{
	std::cout << GRAY "Brain copy constructor called" RESET << std::endl;
	*this = right;
	return ; 
}

Brain::~Brain(void)
{
	std::cout << GRAY "Brain destructor called" RESET << std::endl;
	return ; 
}

//Member functions---------------------------------------------------------------

void Brain::GetIdeas()
{
	for (int i = 0; i < 100; i++)
	{
		if (!this->_ideas[i].empty())
			std::cout << GREEN "Index: " << i << PINK ", Idea: " << this->_ideas[i]
					  << RESET << std::endl;
	}
	return ;
}

void Brain::SetIdea(int nb, std::string const & idea)
{
	if (nb < 0 || nb >= 100)
	{
		std::cout << RED "Idea number not in range" RESET << std::endl;
		return ;
	}
	this->_ideas[nb] = idea;
	return ;
}