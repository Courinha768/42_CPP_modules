#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << "-----------------------" << std::endl;
	{
		Form 		DOI("declaration of independence", 50, 50);
		Bureaucrat	b1("Kate", 60);
		Bureaucrat	b2("Kim", 40);

		std::cout << DOI << std::endl;
		b1.signForm(DOI);
		std::cout << std::endl << DOI << std::endl;
		b2.signForm(DOI);
		std::cout << std::endl << DOI << std::endl;
		b2.signForm(DOI);
	}
	std::cout << "-----------------------" << std::endl;
	{
		std::cout << "Exception - Gradre Too Low : " << std::endl;
		try
		{
			Form	NDA("non-disclosure agreement", 200, 200);
		}
		catch (std::exception	&e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "-----------------------" << std::endl;
	{
		std::cout << "Exception - Gradre Too High : " << std::endl;
		try
		{
			Form	NDA("non-disclosure agreement", 0, 0);
		}
		catch (std::exception	&e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "-----------------------" << std::endl;
}