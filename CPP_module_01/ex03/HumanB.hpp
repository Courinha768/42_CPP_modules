#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private	:
		std::string	name;
		Weapon*		_Weapon;
	public	:
		HumanB(std::string _newName);
		~HumanB();
		void	attack(void);
		void	setWeapon(Weapon& _newWeapon);
};

#endif