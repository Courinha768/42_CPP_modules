#include "Zombie.hpp"

int	main(void)
{
	Zombie	*_Zombie = newZombie("Foo");
	_Zombie->announce();
	randomChump("Marvin");
	delete(_Zombie);
}