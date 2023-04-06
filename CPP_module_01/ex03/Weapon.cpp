#include "Weapon.hpp"

Weapon::Weapon(std::string _initType){
	type = _initType;
}

Weapon::~Weapon(void){}

void	Weapon::setType(std::string _newType) {
	type = _newType;
}

const std::string&	Weapon::getType(void)
{
	return (type);
}

