#include "Zombie.hpp"

void	Zombie::announce(void){
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(std::string _newName)
{
	name = _newName;
}

Zombie::~Zombie(void)
{
	std::cout << name << ": destroyed\n";
}