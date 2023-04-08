#include "Cure.hpp"
// #include "ICharacter.hpp"
// #include "IMateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure()
{
	this->type = "cure";
	std::cout << "\e[0;32mCure\e[0m\t\tcreated through default constructer" << std::endl;
}

Cure::Cure( const Cure & src ) : AMateria(src)
{
	this->type = src.getType();
	std::cout << "\e[0;32mCure\e[0m created through copy constructer" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure()
{
	std::cout << "\e[0;32mCure\e[0m\t\tdestructed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cure &				Cure::operator=( Cure const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string const & Cure::getType() const
{
	return (this->type);
}

Cure* Cure::clone() const
{
	Cure *cureNewType = new Cure;
	return(cureNewType);
}

void Cure::use(ICharacter& target)
{
	std::cout << "\e[0;32mCure\e[0m:\t" << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */