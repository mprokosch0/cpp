
#include "../includes/ScavTrap.hpp"

//Operators---------------------------------------------------------------

ScavTrap &ScavTrap::operator=(ScavTrap const & right)
{
	std::cout << GRAY "ScavTrap operator = called" RESET << std::endl;
	this->_attackDamage = right._attackDamage;
	this->_energyPoints = right._energyPoints;
	this->_hitPoints = right._hitPoints;
	this->_name = right._name;
	return *this;
}

//Constructor/destructors-------------------------------------------------

ScavTrap::ScavTrap(void)
{
	std::cout << GRAY "Default ScavTrap constructor called" RESET << std::endl;
	this->_attackDamage = 20;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	return ;
}

ScavTrap::ScavTrap(std::string const & name)
{
	std::cout << GRAY "Named ScavTrap constructor called" RESET << std::endl;
	this->_attackDamage = 20;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_name = name;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & right)
{
	std::cout << GRAY "Copy ClapTrap constructor called" RESET << std::endl;
	*this = right;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << GRAY "ScavTrap destructor called" RESET << std::endl;
	return ;
}

//Member functions

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap: " << this->_name << " is now in Gate keeper mode" << std::endl;
	return ;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints)
	{
		std::cout << BLUE "ScavTrap " << this->_name << " attacks "
			  << target << ", causing " << this->_attackDamage
			  << " points of damage !" RESET << std::endl;
		this->_energyPoints--;
	}
	else
	{
		std::cout << YELLOW "ScavTrap " << this->_name << " cant't attack, he has no energy left" RESET
				  << std::endl;
	}
	
	return ;
}
