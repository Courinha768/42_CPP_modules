#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern		Intern;
	Bureaucrat	Bureaucrat("Bureaucrat", 1);
	AForm		*Form;

	Form = Intern.makeForm("RobotomyRequestForm", "Robot");
	Bureaucrat.signForm(*Form);
	Bureaucrat.executeForm(*Form);
}