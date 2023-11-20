#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm()
		: AForm(72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target)
		: AForm(72, 45), target(_target)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target, std::string name)
		: AForm(name, 72, 45), target(_target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & src)
		: AForm(src)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if ( this != &rhs )
		return *this;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
{
	o << "RobotomyRequestForm : " << i.getName() << "\n" << std::endl;
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

void	RobotomyRequestForm::execute(Bureaucrat const & executor)const
{
	if (executor.getGrade() > this->getGrade_to_execute())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->is_signed() == false)
		throw (AForm::NotSignedException());
	else
	{
		std::cout << "*drill noises*" << std::endl;
		if (rand() % 2)
			std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
		else
			std::cout << "robotomy failed" << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	RobotomyRequestForm::getTarget()const
{
	return (this->target);
}

/* ************************************************************************** */