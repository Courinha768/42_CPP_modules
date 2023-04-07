#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal()
{
	this->type = "Animal";
	std::cout << "\e[1;32mAnimal:\e[0m created through default constructer" << std::endl;
}

Animal::Animal(const Animal& src)
{
	this->type = src.type;
	std::cout << "\e[1;32mAnimal:\e[0m created through copy constructer" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << "\e[1;32mAnimal:\e[0m destructed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal&	Animal::operator=(Animal const& rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return *this;
}

std::ostream&	operator<<(std::ostream& o, Animal const& i)
{
	o << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Animal::makeSound(void) const
{
	std::cout << "Animal Noises" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */