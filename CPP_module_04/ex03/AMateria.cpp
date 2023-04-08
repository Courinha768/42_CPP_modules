#include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria()
{
	std::cout << "\e[0;31mAMateria\e[0m\tcreated through default constructer" << std::endl;
}


AMateria::AMateria(std::string const& _type) : type(_type)
{
	std::cout << "\e[0;31mAMateria\e[0m created through default constructer" << std::endl;
}

AMateria::AMateria(const AMateria& src) : type(src.getType())
{
	std::cout << "\e[0;31mAMateria\e[0m created through copy constructer" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria()
{
		std::cout << "\e[0;31mAMateria\e[0m\tdestructed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string const & AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "\e[0;31mAMateria\e[0m abstractly used on " << target.getName() << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */