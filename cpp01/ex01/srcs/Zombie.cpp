#include "../includes/Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Zombie constructor called" << std::endl;
	return ;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " destructor called" << std::endl;
	return ;
}

void	Zombie::annouce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
