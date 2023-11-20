#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm()
		: AForm(25, 5), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string _target)
		: AForm(25, 5), target(_target)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target, std::string name)
		: AForm(name, 25, 5), target(_target)
{
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src )
		: AForm(src)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	if ( this != &rhs )
		return *this;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i )
{
	o << "PresidentialPardonForm : " << i.getName() << "\n" << std::endl;
	o << "Target : " << i.getTarget() << "\n" << std::endl;
	o << "Minimum grade to sign : " << i.getGrade_to_sign() << std::endl;
	o << "Minimum grade to execute : " << i.getGrade_to_execute() << "\n" << std::endl;
	if (i.is_signed())
		o << "signed" << std::endl;
	else
		o << "not signed" << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	PresidentialPardonForm::execute(Bureaucrat const & executor)const
{
	if (executor.getGrade() > this->getGrade_to_execute())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->is_signed() == false)
		throw (AForm::NotSignedException());
	else
	{
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	PresidentialPardonForm::getTarget()const
{
	return (this->target);
}


/* ************************************************************************** */