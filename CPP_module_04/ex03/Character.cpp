#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character(std::string _name) : name(_name)
{
	for(int i = 0; i < 4; i++)	{
		this->inventory[i] = 0;
	}
	std::cout << "\e[0;33mCharacter\e[0m\tcreated through default constructer" << std::endl;
}

Character::Character( const Character & src )
{
	for(int i = 0; i < 4; i++)
	{
		if ((src.inventory)[i])
			this->inventory[i] = src.inventory[i]->clone();
	}
	std::cout << "\e[0;33mCharacter\e[0m created through copy constructer" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	for (int i = 0; i < 4; i++)	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
	std::cout << "\e[0;33mCharacter\e[0m\tdestructed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	for(int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
		if (rhs.inventory[i])
			this->inventory[i] = (rhs.inventory[i])->clone();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Character const & i )
{
	o << i.getName();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string const & Character::getName() const
{
	return (this->name);
}

AMateria	*Character::getMateriaFromInventory(int i)
{
	return (this->inventory)[i];
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	Character::equip(AMateria* m)
{
	int i = 0;
	int j = 0;

	if (!m)
	{
		std::cout << "\e[0;33mCharacter\e[0m:\t" << this->getName() << " tried to equip nothing" << std::endl;
		return ;
	}
	while ((this->inventory)[i] && i < 4)
	{
		if ((this->inventory)[i] == m)
		{
			std::cout << "\e[0;33mCharacter\e[0m:\t" << this->getName() << " already equiped this materia" << std::endl;
			return ;
		}
		i++;
	}
	while ((this->inventory)[i] && i < 4)
		i++;
	if (i == 4)
		std::cout << "\e[0;33mCharacter\e[0m:\t" << this->getName() << " can't equip any more Materia" << std::endl;
	else
	{
		while ((this->inventory)[j] && j < 4)
		{
			if ((this->inventory)[j] == m)
			{
				std::cout << "\e[0;33mCharacter\e[0m:\t" << this->getName() << " already equiped this materia" << std::endl;
				return ;
			}
			j++;
		}
		(this->inventory)[i] = m;
		std::cout << "\e[0;33mCharacter\e[0m:\t" << this->getName() << " equipped materia " << m->getType() << " in slot " << i << "\n";
	}
}

void	Character::unequip(int i)
{
	if (i < 0 || i > 3 || !(this->getMateriaFromInventory(i)))
		std::cout << "\e[0;33mCharacter\e[0m:\t" << this->getName() << " tried to unequip nothing" << std::endl;
	else
	{
		AMateria *temp = (this->getMateriaFromInventory(i));
		std::cout << "\e[0;33mCharacter\e[0m:\t" << this->getName() << " unequipped " << temp->getType() << std::endl;
		this->inventory[i] = 0;
	}
}

void	Character::use(int i, ICharacter& target)
{
	if (i < 0 || i >= 4 || !(this->getMateriaFromInventory(i)))
		std::cout << "\e[0;33mCharacter\e[0m:\t" << this->getName() << " tried to use nothing " << std::endl;
	else
	{
		std::cout << "\e[0;33mCharacter\e[0m:\t" << this->getName() << " ";
		(this->getMateriaFromInventory(i))->use(target);
	}
}



/* ************************************************************************** */