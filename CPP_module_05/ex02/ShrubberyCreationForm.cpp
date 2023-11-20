#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm()
		: AForm(145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target)
		: AForm(145, 137), target(_target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target, std::string name)
		: AForm(name, 145, 137), target(_target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & src)
		: AForm(src)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
		return *this;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
	o << "ShrubberyCreationForm : " << i.getName() << "\n" << std::endl;
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

void	ShrubberyCreationForm::execute(Bureaucrat const & executor)const
{
	if (executor.getGrade() > this->getGrade_to_execute())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->is_signed() == false)
		throw (AForm::NotSignedException());
	else
	{

		std::ofstream MyFile(this->getTarget().append("_shrubbery").c_str());

		MyFile << "          &&& &&  & &&" << std::endl;
		MyFile << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
		MyFile << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
		MyFile << "   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
		MyFile << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
		MyFile << "&&   && & &| &| /& & % ()& /&&" << std::endl;
		MyFile << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
		MyFile << "     &&     \\|||" << std::endl;
		MyFile << "             |||" << std::endl;
		MyFile << "             |||" << std::endl;
		MyFile << "             |||" << std::endl;
		MyFile << "       , -=-~  .-^- _" << std::endl;

		MyFile.close();
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	ShrubberyCreationForm::getTarget()const
{
	return (this->target);
}

/* ************************************************************************** */