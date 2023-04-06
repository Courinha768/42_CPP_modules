#include "Zombie.hpp"

#define NBR_OF_ZOMBIES	5
#define NAME_OF_HORDE	"Marvin"

int	main(void)
{
	Zombie	*_zombieHorde = zombieHorde(NBR_OF_ZOMBIES, NAME_OF_HORDE);

	for (int i = 0; i < NBR_OF_ZOMBIES; i++)
		_zombieHorde[i].announce();
	delete[](_zombieHorde);
}