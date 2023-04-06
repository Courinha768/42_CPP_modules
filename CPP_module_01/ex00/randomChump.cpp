#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie _newZombie(name);

	_newZombie.announce();
}