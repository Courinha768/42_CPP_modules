#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : name("default"), grade_to_sign(150), 
			grade_to_execute(150), signature(false) {}

Form::Form(std::string _name, int _grade_to_sign, int _grade_to_execute)
		: name(_name), grade_to_sign(_grade_to_sign), 
		grade_to_execute(_grade_to_execute), signature(false)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw (Form::GradeTooHighException());
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw (Form::GradeTooLowException());
}

Form::Form(int _grade_to_sign, int _grade_to_execute)
		: name("default"), grade_to_sign(_grade_to_sign), 
		grade_to_execute(_grade_to_execute), signature(false)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw (Form::GradeTooLowException());
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw (Form::GradeTooHighException());
}

Form::Form(const Form & src)
		: name(src.getName()), grade_to_sign(src.getGrade_to_sign()), 
		grade_to_execute(src.getGrade_to_execute()), signature(src.is_signed())
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		(void)rhs;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << "Form : " << i.getName() << std::endl;
	o << "Minimum grade to sign : " << i.getGrade_to_sign() << std::endl;
	o << "Minimum grade to execute : " << i.getGrade_to_execute() << std::endl;
	if (i.is_signed())
		o << "signed" << std::endl;
	else
		o << "not signed" << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string	Form::getName() const {
	return (this->name);
}

bool	Form::is_signed() const {
	return (this->signature);
}

int	Form::getGrade_to_sign() const {
	return (this->grade_to_sign);
}

int	Form::getGrade_to_execute() const {
	return (this->grade_to_execute);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Forms's grande is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Forms's grande is too low");
}

void	Form::beSigned(Bureaucrat a)
{
	if (a.getGrade() >= this->grade_to_sign)
		throw (Form::GradeTooLowException());
	else
		this->signature = true;
}

/* ************************************************************************** */