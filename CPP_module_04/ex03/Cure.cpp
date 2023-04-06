#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure()
{
	this->type = "cure";
	std::cout << "Cure created through default constructer" << std::endl;
}

Cure::Cure( const Cure & src ) : AMateria(src)
{
	this->type = src.getType();
	std::cout << "Cure created through copy constructer" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure()
{
	std::cout << "Cure destructed" << std::endl;
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

std::ostream &			operator<<( std::ostream & o, Cure const & i )
{
	//o << "Value = " << i.getValue();
	(void)i;
	return o;
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
	std::cout << "Heals " << target.getName() << "\'s wounds" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */