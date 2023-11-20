#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(): name("default"), grade(150)	{}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.name)
{
	this->grade = src.grade;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if ( this != &rhs )
	{
		this->grade = rhs.grade;
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string	Bureaucrat::getName()	const{
	return (this->name);
}

int	Bureaucrat::getGrade()	const{
	return (this->grade);
}

void	Bureaucrat::increment_grade()
{
	if (this->grade > 1)
		grade -= 1;
	else
		throw (Bureaucrat::GradeTooHighException());
}

void	Bureaucrat::decrement_grade()
{
	if (this->grade < 150)
		grade += 1;
	else
		throw (Bureaucrat::GradeTooLowException());
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat's grande is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat's grande is too low");
}

void	Bureaucrat::signForm(AForm &f)
{
	if (this->grade > f.getGrade_to_sign())
		std::cout << this->name << " couldn't sign " << f.getName() << " because their grade is not high enough" << std::endl;  
	else if (f.is_signed())
		std::cout << this->name << " couldn't sign " << f.getName() << " because this form is already signed" << std::endl;
	else
	{
		f.beSigned(*this);
		std::cout << this->name << " signed " << f.getName() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception	&e)
	{
		std::cout << e.what() << std::endl;
	}
}


/* ************************************************************************** */