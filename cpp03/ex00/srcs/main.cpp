
#include "../includes/ClapTrap.hpp"

int main(void)
{
	ClapTrap a;
	ClapTrap b(a);

	a.attack("bonjour");
	a.beRepaired(10);
	a.takeDamage(10);
	a.attack("bonjour");
	a.attack("bonjour");
	a.attack("bonjour");
	a.attack("bonjour");
	a.attack("bonjour");
	a.attack("bonjour");
	a.attack("bonjour");
	a.attack("bonjour");
	a.attack("bonjour");
	return 0;
}
