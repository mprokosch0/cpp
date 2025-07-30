
#include "../includes/DiamondTrap.hpp"

int main(void)
{
	DiamondTrap c("oui");
	DiamondTrap a;

	a = c;
	a.whoAmI();
	a.attack("tom");
	a.beRepaired(20);
	a.highFivesGuys();
	a.takeDamage(30);
	return 0;
}
