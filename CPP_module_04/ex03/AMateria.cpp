#include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria()
{
	std::cout << "AMateria created through default constructer" << std::endl;
}


AMateria::AMateria(std::string const& _type) : type(_type)
{
	std::cout << "AMateria created through default constructer" << std::endl;
}

AMateria::AMateria(const AMateria& src) : type(src.getType())
{
	std::cout << "AMateria created through copy constructer" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria()
{
		std::cout << "AMateria destructed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string const & AMateria::getType() const
{
	return (this->getType());
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria abstractly used on " << target.getName() << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */