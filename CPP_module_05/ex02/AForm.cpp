#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm() : name("default"), grade_to_sign(150), 
			grade_to_execute(150), signature(false) {}

AForm::AForm(std::string _name, int _grade_to_sign, int _grade_to_execute)
		: name(_name), grade_to_sign(_grade_to_sign), 
		grade_to_execute(_grade_to_execute), signature(false)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw (AForm::GradeTooHighException());
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(int _grade_to_sign, int _grade_to_execute)
		: name("default"), grade_to_sign(_grade_to_sign), 
		grade_to_execute(_grade_to_execute), signature(false)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw (AForm::GradeTooLowException());
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw (AForm::GradeTooHighException());
}

AForm::AForm(const AForm & src)
		: name(src.getName()), grade_to_sign(src.getGrade_to_sign()), 
		grade_to_execute(src.getGrade_to_execute()), signature(src.is_signed())
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
{
	if ( this != &rhs )
	{
		(void)rhs;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AForm const & i )
{
	o << "AForm : " << i.getName() << std::endl;
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

std::string	AForm::getName() const {
	return (this->name);
}

bool	AForm::is_signed() const {
	return (this->signature);
}

int	AForm::getGrade_to_sign() const {
	return (this->grade_to_sign);
}

int	AForm::getGrade_to_execute() const {
	return (this->grade_to_execute);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Forms's grande is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Forms's grande is too low");
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("This form is not signed");
}

void	AForm::beSigned(Bureaucrat a)
{
	if (a.getGrade() >= this->grade_to_sign)
		throw (AForm::GradeTooLowException());
	else
		this->signature = true;
}

/* ************************************************************************** */