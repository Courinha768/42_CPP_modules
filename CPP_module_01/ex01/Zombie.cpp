#include "Zombie.hpp"

void	Zombie::announce(void){
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setName(std::string _newName)
{
	name = _newName;
}

Zombie::Zombie(void)
{
}

Zombie::~Zombie(void)
{
	std::cout << name << ": destroyed\n";
}