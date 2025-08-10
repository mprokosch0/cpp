
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int main(void)
{
	ScavTrap a("tobby");
	FragTrap b;
	FragTrap c("tom");

	b = c;
	a.attack(b.getName());
	c.highFivesGuys();
	return 0;
}
