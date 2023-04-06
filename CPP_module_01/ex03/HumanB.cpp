#include "HumanB.hpp"

void	HumanB::attack(void)
{
	if (_Weapon == NULL)
		std::cout << name << " attacks with their fist" << std::endl;
	else
	{
		std::cout << name << " attacks with their " << (*_Weapon).getType();
		std::cout << std::endl;
	}
}	

HumanB::HumanB(std::string _newName)
	: name(_newName), _Weapon(NULL)
{
}

HumanB::~HumanB(void){}

void	HumanB::setWeapon(Weapon& _newWeapon){
	_Weapon = &_newWeapon;
}

