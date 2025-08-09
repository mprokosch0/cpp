#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << GRAY "Zombie constructor called" RESET << std::endl;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << GRAY << this->_name << " destructor called" RESET << std::endl;
	return ;
}

void	Zombie::annouce(void) const
{
	std::cout << PINK << this->_name << ": " GREEN "BraiiiiiiinnnzzzZ..." RESET << std::endl;
	return ;
}
