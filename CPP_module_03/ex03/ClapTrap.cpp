#include "ClapTrap.hpp"

#define TRAP_NAME "ClapTrap"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap()
{
	this->name = "ClapTrap";
	this->hp = 10;
	this->ep = 10;
	this->ad = 0;
	std::cout << "\e[1;32mClapTrap\e[0m: " << "ClapTrap got created through default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string const _name)
{
	this->name = _name;
	this->hp = 10;
	this->ep = 10;
	this->ad = 0;
	std::cout << "\e[1;32mClapTrap\e[0m: " << name << " got created through standard constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	this->name = src.name;
	this->hp = src.hp;
	this->ep = src.ep;
	this->ad = src.ad;
	std::cout << "\e[1;32mClapTrap\e[0m: " << name << " got created through copy constructor" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "\e[1;32mClapTrap\e[0m: " << name << " has been destructed." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap&	ClapTrap::operator=(ClapTrap const & rhs)
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

int		ClapTrap::getHp() {
	return (this->hp);
}

int		ClapTrap::getEp() {
	return (this->ep);
}

int		ClapTrap::getAd() {
	return (this->ad);
}
std::string	ClapTrap::getName()
{
	return (this->name);
}

void	ClapTrap::change_ad(unsigned int new_amount)	{
	this->ad = new_amount;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->ep <= 0)	{
		std::cout << "\e[1;32mClapTrap\e[0m: " << name << " can't attack because it has no energy" << std::endl;
		return ;
	} 
	else if (this->hp <= 0)	{
		std::cout << "\e[1;32mClapTrap\e[0m: " << name << " can't attack because it is dead" << std::endl;
		return ;
	}
	this->ep--;
	std::cout << "\e[1;32mClapTrap\e[0m: " << name << " has attacked " << target << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->hp)	{
		std::cout << "\e[1;32mClapTrap\e[0m: " << name << " didn't take any damage because it is already dead" << std::endl;
		return ;
	}
	if (this->hp > amount)
		this->hp -= amount;
	else
		this->hp = 0;
	std::cout << "\e[1;32mClapTrap\e[0m: " << name << " took " << amount << " points of damage" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->ep <= 0)	{
		std::cout << "\e[1;32mClapTrap\e[0m: " << name << " can't repair because it has no energy" << std::endl;
		return ;
	}
	else if (this->hp <= 0)	{
		std::cout << "\e[1;32mClapTrap\e[0m: " << name << " can't repair because it is dead" << std::endl;
		return ;
	}
	this->ep--;
	this->hp += amount;
	std::cout << "\e[1;32mClapTrap\e[0m: " << name << " got repaired for " << amount << " of hp" << std::endl;
}


/* ************************************************************************** */