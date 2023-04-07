#include "DiamondTrap.hpp"

#define TRAP_NAME "DiamondTrap"

std::string clapName = "_clap_name";
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap() : ClapTrap(TRAP_NAME + clapName)
{
	ClapTrap::name = TRAP_NAME + clapName;
	this->name = TRAP_NAME;
	this->hp = 100;
	this->ep = 50;
	this->ad = 30;
	std::cout << "\e[1;36mDiamondTrap\e[0m: " << TRAP_NAME << " created through default constructer" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src): ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	this->name = src.name;
	this->hp = src.hp;
	this->ep = src.ep;
	this->ad = src.ad;
	std::cout << "\e[1;36mDiamondTrap\e[0m: " << this->name << " created through copy constructer" << std::endl;
}

DiamondTrap::DiamondTrap(std::string const _name): ClapTrap(_name + clapName)
{
	ClapTrap::name = _name + clapName;
	this->name = _name;
	this->hp = 100;
	this->ep = 50;
	this->ad = 30;
	std::cout << "\e[1;36mDiamondTrap\e[0m: " << _name << " created through default constructer" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap()
{
	std::cout << "\e[1;36mDiamondTrap\e[0m: " << getName() << " has been destructed." << std::endl;
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
	std::cout << "\e[1;36mwhoAmI\e[0m  : ";
	std::cout << "DiamondTrap name's : " << this->getName() << std::endl;
	std::cout << "\t  ClapTrap name's    : " << ClapTrap::name << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/



/* ************************************************************************** */