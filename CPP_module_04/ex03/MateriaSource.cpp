#include "MateriaSource.hpp"
#include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource()
{
	for(int i = 0; i < 4; i++)	{
		this->inventory[i] = 0;
	}
	std::cout << "MateriaSource created through default constructer" << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource & src )
{
	for (int i = 0; i < 4; i++)	{
		if (src.inventory[i])
			this->inventory[i] = (src.inventory[i])->clone();
	}
	std::cout << "MateriaSource created through default constructer" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
	std::cout << "MateriaSource destructed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
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

std::ostream &			operator<<( std::ostream & o, MateriaSource const & i )
{
	//o << "Value = " << i.getValue();
	(void)i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void MateriaSource::learnMateria(AMateria *m)
{
	int i = 0;

	while ((this->inventory)[i] && i < 4) {
		i++;
	}

	if (i == 4)
	{
		std::cout << "You can't learn more than 4 Materias" << std::endl;
		return ;
	}

	(this->inventory)[i] = m;

	std::cout << "Materia " << m->getType() << " learned\n";
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;

	while ((this->inventory)[i] && ((this->inventory)[i])->getType() != type && i < 4)
		i++;
	if (i >= 4 || !(this->inventory)[i])
	{
		std::cout << type << " materia does not exit\n";
		return (NULL);
	}
	std::cout << "Materia " << type << " created\n";
	return (((this->inventory)[i])->clone());
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */