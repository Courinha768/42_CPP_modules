#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "\e[1;34mDog   :\e[0m created through default constructer" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src)
{
	this->type = src.type;
	std::cout << "\e[1;34mDog   :\e[0m created through copy constructer" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	std::cout << "\e[1;34mDog   :\e[0m destructed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog&	Dog::operator=(Dog const& rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return *this;
}

std::ostream&	operator<<(std::ostream& o, Dog const& i)
{
	(void)i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */