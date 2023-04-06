#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*_zombieHorde;

	if (N < 1)
		return (NULL);
	_zombieHorde = new Zombie [N];
	for (int i = 0; i < N; i++)
		_zombieHorde[i].setName(name);
	return(_zombieHorde);
}