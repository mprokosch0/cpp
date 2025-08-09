#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL)
{
	std::cout << GRAY << this->_name << " HumanB constructor called" RESET << std::endl;
	return ;
}

HumanB::~HumanB(void)
{
	std::cout << GRAY << this->_name << " HumanB destctructor called" RESET << std::endl;
	return ;
}

void	HumanB::attack(void) const
{
	std::cout << PINK << this->_name << GREEN " attacks with their " RED
			  << this->_weapon->getType() << RESET << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	return ;
}
