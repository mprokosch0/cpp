
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int main(void)
{
	ScavTrap a("tobby");
	ScavTrap b;
	FragTrap c("tom");

	b.setName("bob");
	a.attack(b.getName());
	c.highFivesGuys();
	return 0;
}
