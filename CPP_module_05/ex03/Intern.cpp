#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern(const Intern & src)
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	if ( this != &rhs )
		return *this;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Intern const & i )
{
	(void)i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

AForm* newPPF(std::string target, std::string name)
{
	return (new PresidentialPardonForm(target, name));
}

AForm* newRRF(std::string target, std::string name)
{
	return (new RobotomyRequestForm(target, name));
}

AForm* newSCF(std::string target, std::string name)
{
	return (new ShrubberyCreationForm(target, name));
}


AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string Forms[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	AForm		*(*Forms_functions[3])(std::string target, std::string name) =
			{&newPPF, &newRRF, &newSCF};
	int	i = 0;

	while (i < 3 && name != Forms[i])
		i++;
	if (i == 3)
		std::cout << "Form given to intern doesn't exist" << std::endl;
	else
	{
		return (Forms_functions[i](target, name));
	}
	return (NULL);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */