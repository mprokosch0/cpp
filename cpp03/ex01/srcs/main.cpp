
#include "../includes/ScavTrap.hpp"

int main(void)
{
	ScavTrap a("tobby");
	ScavTrap b;

	b.setName("bob");
	a.attack(b.getName());
	b.takeDamage(20);
	b.takeDamage(80);
	b.guardGate();
	b.beRepaired(30);
	a.beRepaired(20);
	a.takeDamage(20);
	return 0;
}
