
#include "../includes/DiamondTrap.hpp"

int main(void)
{
	DiamondTrap c("oui");
	DiamondTrap a;
	DiamondTrap d;

	a = c;
	a.whoAmI();
	a.attack("tom");
	a.beRepaired(20);
	a.highFivesGuys();
	a.takeDamage(99);
	a.takeDamage(1);
	d.whoAmI();
	return 0;
}
