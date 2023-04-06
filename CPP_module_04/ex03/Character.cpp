#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character(std::string _name) : name(_name)
{
	for(int i = 0; i < 4; i++)	{
		this->inventory[i] = 0;
	}
	std::cout << "Character created through default constructer" << std::endl;
}

Character::Character( const Character & src )
{
	for(int i = 0; i < 4; i++)
	{
		if ((src.inventory)[i])
			this->inventory[i] = src.inventory[i]->clone();
	}
	std::cout << "Character created through copy constructer" << std::endl;
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
	std::cout << "Character destructed" << std::endl;
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
	//o << "Value = " << i.getValue();
	(void)i;
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

	if (!m)
	{
		std::cout << this->getName() << " tried to equip nothing" << std::endl;
		return ;
	}
	while ((this->inventory)[i] != 0 && i < 4)
		i++;
	if (i == 4)
		std::cout << this->getName() << " can't equip any more Materia";
	else
	{
		(this->inventory)[i] = m;
		std::cout << this->getName() << " equipped materia " << m->getType() << " in slot " << i << "\n";
	}
}

void	Character::unequip(int i)
{
	if (i < 0 || i > 3 || !(this->getMateriaFromInventory(i)))
		std::cout << this->getName() << " tried to unequip nothing" << std::endl;
	else
	{
		AMateria *temp = (this->getMateriaFromInventory(i));
		std::cout << this->getName() << " unequipped " << temp->getType() << std::endl;
		this->inventory[i] = 0;
	}
}

void	Character::use(int i, ICharacter& target)
{
	if (i < 0 || i >= 4 || !(this->getMateriaFromInventory(i)))
		std::cout << this->getName() << " tried to use nothing " << std::endl;
	else
	{
		std::cout << this->getName();
		(this->getMateriaFromInventory(i))->use(target);
	}
}



/* ************************************************************************** */