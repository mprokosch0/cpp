
#include "../includes/ScavTrap.hpp"

int main(void)
{
	ScavTrap a("tobby");
	ScavTrap b;

	b.setName("bob");
	a.attack(b.getName());
	return 0;
}
