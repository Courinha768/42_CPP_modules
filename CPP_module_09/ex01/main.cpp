#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		std::string	input(av[1]);
		try
		{
			RPN equation(input);
			equation.solveEquation();
			std::cout << equation.getResult() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error" << std::endl;
		}
	}
	else 
		std::cerr << "Error" << std::endl;
}