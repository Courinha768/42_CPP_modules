#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat created through default constructer" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src)
{
	this->type = src.type;
	std::cout << "WrongCat created through copy constructer" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat&	WrongCat::operator=(WrongCat const& rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return *this;
}

std::ostream&	operator<<(std::ostream& o, WrongCat const& i)
{
	(void)i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */