#include "ScavTrap.hpp"

#define TRAP_NAME "ScavTrap"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap() : ClapTrap(TRAP_NAME)
{
	this->name = TRAP_NAME;
	this->hp = 100;
	this->ep = 50;
	this->ad = 20;
	this->isGuardingGate = false;
	std::cout << "\e[1;31mScavTrap\e[0m: " << TRAP_NAME << " created through default constructer" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src): ClapTrap(src)
{
	this->name = src.name;
	this->hp = src.hp;
	this->ep = src.ep;
	this->ad = src.ad;
	this->isGuardingGate = src.isGuardingGate;
	std::cout << "\e[1;31mScavTrap\e[0m: " << this->name << " created through copy constructer" << std::endl;
}

ScavTrap::ScavTrap(std::string const _name): ClapTrap(_name)
{
	//this->name = _name;
	this->hp = 100;
	this->ep = 50;
	this->ad = 20;
	this->isGuardingGate = false;
	std::cout << "\e[1;31mScavTrap\e[0m: " << _name << " created through default constructer" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << "\e[1;31mScavTrap\e[0m: " << getName() << " has been destructed." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &				ScavTrap::operator=(ScavTrap const& rhs)
{
	this->name = rhs.name;
	this->hp = rhs.hp;
	this->ep = rhs.ep;
	this->ad = rhs.ad;
	this->isGuardingGate = rhs.isGuardingGate;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string	ScavTrap::getName()
{
	return (this->name);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	ScavTrap::guardGate()
{
	this->isGuardingGate = true;
	std::cout << "\e[1;31mScavTrap\e[0m: " << this->getName() << " is now guarding the gate" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->ep <= 0)	{
		std::cout << "\e[1;31mScavTrap\e[0m: " << name << " can't attack because it has no energy" << std::endl;
		return ;
	} 
	else if (this->hp <= 0)	{
		std::cout << "\e[1;31mScavTrap\e[0m: " << name << " can't attack because it is dead" << std::endl;
		return ;
	}
	this->ep--;
	std::cout << "\e[1;31mScavTrap\e[0m: " << name << " has attacked " << target << std::endl;
}

/* ************************************************************************** */