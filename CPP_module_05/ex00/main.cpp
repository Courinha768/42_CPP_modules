#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "-----------------------" << std::endl;
	{
		Bureaucrat	test("Jonny", 120);
		Bureaucrat	test_copy(test);
		Bureaucrat	copy_test("Jim", 42);

		std::cout << "Normal constructor : " << std::endl;
		std::cout << test << std::endl << std::endl;
		std::cout << "Copy constructor   : " << std::endl;
		std::cout << test_copy << std::endl << std::endl;

		std::cout << "Copy operator : " << std::endl;
		std::cout << "Original   : " << copy_test << std::endl;
		copy_test = test;
		std::cout << "After copy : " << copy_test << std::endl;
	}
	std::cout << "-----------------------" << std::endl;
	{
		Bureaucrat	test("Jonny", 120);
		
		std::cout << test << std::endl;
		test.increment_grade();
		std::cout << test << std::endl;
		test.decrement_grade();
		std::cout << test << std::endl;
	}
	std::cout << "-----------------------" << std::endl;
	{
		std::cout << "Exception - Gradre Too Low : " << std::endl;
		try
		{
			Bureaucrat	teste("Joseph", 200);
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
			Bureaucrat	teste("Joseph", -1);
		}
		catch (std::exception	&e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "-----------------------" << std::endl;
}