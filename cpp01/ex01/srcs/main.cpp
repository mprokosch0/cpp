#include "../includes/Zombie.hpp"
 
int	main(void)
{
	Zombie	*zomb = zombieHorde(10, "victor");
	zomb->annouce();
	for (int i = 0; i < 10; i++)
	{
		std::cout << "index " << i << ": ";
		zomb[i].annouce();
	}
	delete[] zomb;
	return (0);
}
