#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private	:
		std::string		name;
		Weapon&			_Weapon;
	public	:
		HumanA(std::string _newName, Weapon& _newWeapon);
		~HumanA();	
		void	attack(void);
};

#endif