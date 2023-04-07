#include "AAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AAnimal::AAnimal()
{
	this->type = "AAnimal";
	std::cout << "\e[1;32mAAnimal:\e[0m created through default constructer" << std::endl;
}

AAnimal::AAnimal(const AAnimal& src)
{
	this->type = src.type;
	std::cout << "\e[1;32mAAnimal:\e[0m created through copy constructer" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AAnimal::~AAnimal()
{
	std::cout << "\e[1;32mAAnimal:\e[0m destructed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AAnimal&	AAnimal::operator=(AAnimal const& rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return *this;
}

std::ostream&	operator<<(std::ostream& o, AAnimal const& i)
{
	o << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	AAnimal::makeSound(void) const
{
	std::cout << "AAnimal Noises" << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (this->type);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */