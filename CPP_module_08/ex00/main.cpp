#include "easyfind.hpp"


int	main(void)
{
	std::cout << "-----------------------" << std::endl;
	{
		std::vector<int>	vector;

		vector.push_back(1);
		vector.push_back(2);
		vector.push_back(3);
		vector.push_back(4);
		
		try
		{
			std::cout << *easyfind(vector, 3) << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "-----------------------" << std::endl;
	{
		std::list<int>	list;

		list.push_back(42);
		list.push_back(24);
		list.push_back(100);
		list.push_back(42);
		
		try
		{
			std::cout << *easyfind(list, 24) << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "-----------------------" << std::endl;
	{
		std::vector<int>	vector;
		
		vector.push_back(1);
		vector.push_back(2);
		vector.push_back(3);
		vector.push_back(4);

		try
		{
			std::cout << *(easyfind(vector, 2) + 1) << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "-----------------------" << std::endl;
	{
		std::vector<int>	vector;
		
		vector.push_back(1);
		vector.push_back(2);
		vector.push_back(3);
		vector.push_back(4);

		try
		{
			std::cout << *easyfind(vector, 5) << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "-----------------------" << std::endl;
}