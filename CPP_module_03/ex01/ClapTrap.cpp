#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap()
{
	this->name = "ClapTrap";
	this->hp = 10;
	this->ep = 10;
	this->ad = 0;
	std::cout << "ClapTrap got created through default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string const _name)
{
	this->name = _name;
	this->hp = 10;
	this->ep = 10;
	this->ad = 0;
	std::cout << name << " got created through standard constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	this->name = src.name;
	this->hp = src.hp;
	this->ep = src.ep;
	this->ad = src.ad;
	std::cout << name << " got created through copy constructor" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << name << " has been destructed." << std::endl;
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

void	ClapTrap::change_ad(unsigned int new_amount)	{
	this->ad = new_amount;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->ep <= 0)	{
		std::cout << name << " can't attack because it has no energy" << std::endl;
		return ;
	} 
	else if (this->hp <= 0)	{
		std::cout << name << " can't attack because it is dead" << std::endl;
		return ;
	}
	this->ep--;
	std::cout << name << " has attacked " << target << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->hp)	{
		std::cout << name << " didn't take any damage because it is already dead" << std::endl;
		return ;
	}
	if (this->hp > amount)
		this->hp -= amount;
	else
		this->hp = 0;
	std::cout << name << " took " << amount << " points of damage" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->ep <= 0)	{
		std::cout << name << " can't repair because it has no energy" << std::endl;
		return ;
	}
	else if (this->hp <= 0)	{
		std::cout << name << " can't repair because it is dead" << std::endl;
		return ;
	}
	this->ep--;
	this->hp += amount;
	std::cout << name << " got repaired for " << amount << " of hp" << std::endl;
}


/* ************************************************************************** */