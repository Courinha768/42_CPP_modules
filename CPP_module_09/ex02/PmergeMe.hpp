#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <cmath>
# include <algorithm>
# include <sys/time.h>
# include <deque>
# include <iomanip>

# define REMOVED -1

typedef struct	vectors_s
{
	std::vector<int>	a;
	std::vector<int>	b;
}	vectors_t;

typedef struct	deques_s
{
	std::deque<int>	a;
	std::deque<int>	b;
}	deques_t;

typedef struct	costs_s
{
	int	targetChainLenght;
	std::vector<int>	b;
}	costs_s;

class PmergeMe
{
	public:
		PmergeMe(char **input);
		PmergeMe(const PmergeMe &copy);
		~PmergeMe();
		
		PmergeMe & operator=(const PmergeMe &assign);

		void				SortVector();
		void				SortDeque();

		std::vector<int>	getVector();
		double				getVectorTime();
		std::deque<int>		getDeque();
		double				getDequeTime();
	
	private:
		std::vector<int>	_vector;
		double				_vectorTime;
		std::deque<int>		_deque;
		double				_dequeTime;

		vectors_t	CreateVectors();
		deques_t	CreateDeques();


		PmergeMe();
		
};

#endif