#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon)
{
	std::cout << this->_name << " HumanA constructor called" << std::endl;
	return ;
}

HumanA::~HumanA(void)
{
	std::cout << this->_name << " HumanA destructor called" << std::endl;
	return ;
}

void	HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
	return ;
}

