#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		const std::string	filename(av[1]);
		try
		{
			BitcoinExchange	data(filename);

			for (int i = 0; i < data.getSize(); i++)
			{
				data.findNewValue(data.getInput());
				data.printData(*data.getInput());
				data.popInput();
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: input file" << std::endl;
		}
	}
	else
		std::cerr << "Error: Incorrect number of arguments" << std::endl;
	
}