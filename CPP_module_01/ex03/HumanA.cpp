#include "HumanA.hpp"

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << _Weapon.getType();
	std::cout << std::endl;
}

HumanA::HumanA(std::string _newName, Weapon& _newWeapon)
	: name(_newName), _Weapon(_newWeapon)
{
}

HumanA::~HumanA(void){}