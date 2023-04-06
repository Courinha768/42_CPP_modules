#include "DiamondTrap.hpp"

#define TRAP_NAME "DiamondTrap"

std::string clapName = "_clap_name";
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap() : ClapTrap(TRAP_NAME + clapName)
{
	this->name = TRAP_NAME;
	this->hp = 100;
	this->ep = 50;
	this->ad = 30;
	std::cout << TRAP_NAME << ": " << TRAP_NAME << " created through default constructer" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src): ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	this->name = src.name;
	this->hp = src.hp;
	this->ep = src.ep;
	this->ad = src.ad;
	std::cout << TRAP_NAME << ": " << this->name << " created through copy constructer" << std::endl;
}

DiamondTrap::DiamondTrap(std::string const _name): ClapTrap(_name + clapName), ScavTrap(_name), FragTrap(_name)
{
	this->name = _name;
	this->hp = 100;
	this->ep = 50;
	this->ad = 30;
	std::cout << TRAP_NAME << ": " << _name << " created through default constructer" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap()
{
	std::cout << TRAP_NAME << ": " << getName() << " has been destructed." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap &				DiamondTrap::operator=(DiamondTrap const& rhs)
{
	this->name = rhs.name;
	this->hp = rhs.hp;
	this->ep = rhs.ep;
	this->ad = rhs.ad;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string	DiamondTrap::getName()
{
	return (this->name);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name's : " << this->name << std::endl;
	std::cout << "ClapTrap name's    : " << this->name + clapName << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/



/* ************************************************************************** */