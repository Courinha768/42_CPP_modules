#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <locale>
#include <sstream>
#include <ctime>

class Zombie
{
	private	:
		std::string name;
	public	:
		Zombie(std::string _newName);
		Zombie(void);
		~Zombie(void);
		void	announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif