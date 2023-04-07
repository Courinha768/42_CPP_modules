#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "\e[1;31mCat   :\e[0m created through default constructer" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat& src) : Animal(src)
{
	this->type = src.type;
	std::cout << "\e[1;31mCat   :\e[0m created through copy constructer" << std::endl;
	this->brain = new Brain(*src.brain);
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	delete this->brain;
	std::cout << "\e[1;31mCat   :\e[0m destructed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat&	Cat::operator=(Cat const& rhs)
{
	if (this != &rhs)
	{
		this->brain = new Brain(*rhs.brain);
		this->type = rhs.type;
	}
	return *this;
}

std::ostream&	operator<<(std::ostream& o, Cat const& i)
{
	(void)i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */