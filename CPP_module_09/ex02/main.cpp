# include "PmergeMe.hpp"

template <typename T>
void	print(T v)
{
	for (int i = 0; i < (int)v.size(); i++)
	{
		std::cout << v.at(i) << " ";
	}
	std::cout << std::endl;
}

template <typename T>
static bool	isCorrect(T v)
{
	int	last;

	last = v.at(0);
	for (int i = 1; i < (int)v.size(); i++)
	{
		if (last > v.at(i))
			return (false);
		last = v.at(i);
	}
	return (true);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		try
		{
			PmergeMe	original(av);
			PmergeMe	v(original);

			v.SortVector();
			v.SortDeque();

			std::cout << "Before:\t";
			print(original.getVector());
			std::cout << "After:\t";
			print(v.getVector());

			std::cout << std::fixed;
			std::cout << std::setprecision(5);

			std::cout << "Time to process a range of ";
			std::cout << v.getVector().size();
			std::cout << " elements with std::vector : ";
			std::cout << v.getVectorTime();
			std::cout << " us" << std::endl;


			std::cout << "Time to process a range of ";
			std::cout << v.getDeque().size();
			std::cout << " elements with std::deque  : ";
			std::cout << v.getDequeTime();
			std::cout << " us" << std::endl;

			// if (isCorrect(v.getVector()))
			// 	std::cout << "vector is correct" << std::endl;
			// if (isCorrect(v.getDeque()))
			// 	std::cout << "deque is correct" << std::endl;
			
		}
		catch (const std::exception &e)
		{
			std::cout << "Error" << std::endl;
		}
	}
}