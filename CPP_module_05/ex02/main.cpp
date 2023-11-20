#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::cout << "-----------------------" << std::endl;
	{
		ShrubberyCreationForm	Form("Berrys", "Berrys");
		Bureaucrat				Bureaucrat("Bureaucrat", 1);

		std::cout << Form << std::endl;
		Bureaucrat.signForm(Form);
		std::cout << Form << std::endl;
		Bureaucrat.executeForm(Form);
	}
	std::cout << "-----------------------" << std::endl;
	{
		RobotomyRequestForm		Form("Robot", "Robotomy");
		Bureaucrat				Bureaucrat("Bureaucrat", 1);

		std::cout << Form << std::endl;
		Bureaucrat.signForm(Form);
		Bureaucrat.executeForm(Form);
	}
	std::cout << "-----------------------" << std::endl;
	{
		PresidentialPardonForm	Form("Joe", "PresidentialPardon");
		Bureaucrat				Bureaucrat("Bureaucrat", 1);

		std::cout << Form << std::endl;
		Bureaucrat.signForm(Form);
		Bureaucrat.executeForm(Form);
	}
	std::cout << "-----------------------" << std::endl;
	{
		RobotomyRequestForm		Form("Robotomy", "Robot");
		Bureaucrat				Bureaucrat("Bureaucrat", 150);

		std::cout << Form << std::endl;
		Bureaucrat.signForm(Form);
		Bureaucrat.executeForm(Form);
	}
	std::cout << "-----------------------" << std::endl;
	{
		RobotomyRequestForm		Form("Robotomy", "Robot");
		Bureaucrat				Bureaucrat("Bureaucrat", 1);

		std::cout << Form << std::endl;
		Bureaucrat.executeForm(Form);
	}
	std::cout << "-----------------------" << std::endl;
}