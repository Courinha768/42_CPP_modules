#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <iterator>

template <class T>
class MutantStack : public std::stack<T>
{
	public:
		
		MutantStack() : std::stack<T>()	{
		}
		MutantStack(const MutantStack &copy) : std::stack<T>(copy)	{
		}
		
		~MutantStack()	{
		}
		
		MutantStack & operator=(const MutantStack &assign)	{
			if (*this != assign)
				*this = assign;
			return (*this);
		}


		typename std::stack<T>::container_type::iterator	begin()
		{
			return (std::stack<T>::c.begin());
		}

		typename std::stack<T>::container_type::iterator	end()
		{
			return (std::stack<T>::c.end());
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		
	private:
		
};

#endif