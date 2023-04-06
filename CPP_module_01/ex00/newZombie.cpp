#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie *_newZombie;

	_newZombie = new Zombie(name);
	return (_newZombie);
}