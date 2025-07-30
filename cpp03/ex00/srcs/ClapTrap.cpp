
#include "../includes/ClapTrap.hpp"

//Operators-------------------------------------------------------------------

ClapTrap & ClapTrap::operator=(ClapTrap const & right)
{
	std::cout << GRAY "ClapTrap operator = called" RESET << std::endl;
	this->_attackDamage = right._attackDamage;
	this->_energyPoints = right._energyPoints;
	this->_hitPoints = right._hitPoints;
	this->_name = right._name;
	return *this;
}

//Constructors/destructors----------------------------------------------------

ClapTrap::ClapTrap(void): _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << GRAY "Default ClapTrap constructor called" RESET << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const & right)
{
	std::cout << GRAY "Copy ClapTrap constructor called" RESET << std::endl;
	*this = right;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << GRAY "ClapTrap destructor called" RESET << std::endl;
	return ;
}

//Member fuctions--------------------------------------------------------------

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints)
	{
		std::cout << GREEN "ClapTrap " << this->_name << " repairs himself "
			  << amount << " hitPoints !" << RESET << std::endl;
		this->_energyPoints--;
	}
	else
	{
		std::cout << YELLOW "ClapTrap " << this->_name << " can't be repaired, he has no energy left"
				   << RESET << std::endl;
	}
	return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << RED "ClapTrap " << this->_name << " took "
			  << amount << " points of damage !" << RESET << std::endl;
	this->_hitPoints -= amount;
	return ;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints)
	{
		std::cout << BLUE "ClapTrap " << this->_name << " attacks "
			  << target << ", causing " << this->_attackDamage
			  << " points of damage !" << RESET << std::endl;
		this->_energyPoints--;
	}
	else
	{
		std::cout << YELLOW "ClapTrap " << this->_name << " cant't attack, he has no energy left"
				  << RESET << std::endl;
	}
	
	return ;
}