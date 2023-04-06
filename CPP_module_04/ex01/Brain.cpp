#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
	std::cout << "Brain created through default constructer" << std::endl;
}

Brain::Brain( const Brain & src )
{
	for (int i = 0; i < 100; i++){
		this->ideas[i] = src.ideas[i];
	}
	std::cout << "Brain created through copy constructer" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
	std::cout << "Brain destructed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &				Brain::operator=( Brain const & rhs )
{
	for (int i = 0; i < 100; i++){
		this->ideas[i] = rhs.ideas[i];
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Brain const & i )
{
	(void)i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */