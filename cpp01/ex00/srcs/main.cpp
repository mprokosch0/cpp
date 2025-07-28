#include "../includes/Zombie.hpp"
 
int	main(void)
{
	Zombie	*zomb = newZombie("victor");
	randomChunp("George");
	zomb->annouce();
	delete zomb;
	return (0);
}
