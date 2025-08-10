
#include "../includes/DiamondTrap.hpp"

//Operators---------------------------------------------------------------

DiamondTrap &DiamondTrap::operator=(DiamondTrap const & right)
{
	std::cout << GRAY "DiamondTrap operator = called" RESET << std::endl;
	this->_attackDamage = right._attackDamage;
	this->_energyPoints = right._energyPoints;
	this->_hitPoints = right._hitPoints;
	this->_name = right._name;
	ClapTrap::_name = this->_name + "_Clap_name";
	return *this;
}

//Constructor/destructors-------------------------------------------------

DiamondTrap::DiamondTrap(void): ClapTrap()
{
	std::cout << GRAY "Default DiamondTrap constructor called" RESET << std::endl;
	this->_name = "default";
	ClapTrap::_name = "default_clap_name";
	this->_attackDamage = FragTrap::_attackDamage;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	return ;
}

DiamondTrap::DiamondTrap(std::string const & name): ClapTrap()
{
	std::cout << GRAY "Named DiamondTrap constructor called" RESET << std::endl;
	this->_attackDamage = FragTrap::_attackDamage;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	ClapTrap::_name = name + "_clap_name";
	this->_name = name;
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const & right): ClapTrap(right), ScavTrap(right), FragTrap(right)
{
	std::cout << GRAY "Copy DiamondTrap constructor called" RESET << std::endl;
	*this = right;
	return ;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << GRAY "DiamondTrap destructor called" RESET << std::endl;
	return ;
}

//Member functions

void DiamondTrap::whoAmI(void)
{
	std::cout << PINK "My name is " << this->_name
			  << " and my ClapTrap name is " << ClapTrap::_name
			  << RESET << std::endl;
}