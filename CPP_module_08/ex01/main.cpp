#include "Span.hpp"

int	main(void)
{
	std::cout << "==================" << std::endl;
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
		std::cout << "longest  span : " << sp.longestSpan() << std::endl;
	}
	std::cout << "==================" << std::endl;
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		try
		{
			sp.addNumber(6);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "==================" << std::endl;
	{
		Span sp = Span(5);

		sp.addManyNumbers(4, 8);

		for (int i = 0; i < 5; i++)
		{
			try
			{
				std::cout << sp.getValue(i) << std::endl;
			}
			catch (const std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
		}
	}
	std::cout << "==================" << std::endl;

	return 0;
}