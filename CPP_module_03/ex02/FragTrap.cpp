#include "FragTrap.hpp"

#define TRAP_NAME "FragTrap"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap() : ClapTrap(TRAP_NAME)
{
	this->name = TRAP_NAME;
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
	std::cout << TRAP_NAME << ": " << TRAP_NAME << " created through default constructer" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src): ClapTrap(src)
{
	this->name = src.name;
	this->hp = src.hp;
	this->ep = src.ep;
	this->ad = src.ad;
	std::cout << TRAP_NAME << ": " << this->name << " created through copy constructer" << std::endl;
}

FragTrap::FragTrap(std::string const _name): ClapTrap(_name)
{
	this->name = _name;
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
	std::cout << TRAP_NAME << ": " << _name << " created through default constructer" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << TRAP_NAME << ": " << getName() << " has been destructed." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &				FragTrap::operator=(FragTrap const& rhs)
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

std::string	FragTrap::getName()
{
	return (this->name);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	FragTrap::highFivesGuys(void)
{
	std::cout << this->getName() << " has requested to high five! (don't do it)" << std::endl;
}




/* ************************************************************************** */