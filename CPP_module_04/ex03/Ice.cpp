#include "Ice.hpp"
// #include "ICharacter.hpp"
// #include "IMateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice()
{
	this->type = "ice";
	std::cout << "\e[0;34mIce\e[0m\t\tcreated through default constructer" << std::endl;
}

Ice::Ice( const Ice & src ) : AMateria(src)
{
	this->type = src.getType();
	std::cout << "\e[0;34mIce\e[0m created through copy constructer" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ice::~Ice()
{
	std::cout << "\e[0;34mIce\e[0m\t\tdestructed" << std::endl;
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
	std::cout << "\e[0;34mIce\e[0m:\t" << "* shoots an ice bolt at " << target.getName() << '*' << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */