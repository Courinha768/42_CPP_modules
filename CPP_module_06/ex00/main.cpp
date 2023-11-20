#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	if (ac < 2)
		return (0);
	std::cout << "----------------" << std::endl;
	for (int i = 1; i < ac; i++)
	{
		ScalarConverter::convert(av[i]);
		std::cout << "----------------" << std::endl;
	}
}