#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL)
{
	std::cout << this->_name << " HumanB constructor called" << std::endl;
	return ;
}

HumanB::~HumanB(void)
{
	std::cout << this->_name << " HumanB destctructor called" << std::endl;
	return ;
}

void	HumanB::attack(void) const
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	return ;
}
