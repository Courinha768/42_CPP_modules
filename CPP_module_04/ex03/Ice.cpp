#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice()
{
	this->type = "ice";
	std::cout << "Ice created through default constructer" << std::endl;
}

Ice::Ice( const Ice & src ) : AMateria(src)
{
	this->type = src.getType();
	std::cout << "Ice created through copy constructer" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ice::~Ice()
{
	std::cout << "Ice destructed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Ice &				Ice::operator=( Ice const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Ice const & i )
{
	(void)i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string const & Ice::getType() const
{
	return (this->type);
}

Ice*	Ice::clone() const
{
	Ice *cureNewType = new Ice;
	return(cureNewType);
}

void Ice::use(ICharacter& target)
{
	std::cout << " shoots an ice bolt at " << target.getName() << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */