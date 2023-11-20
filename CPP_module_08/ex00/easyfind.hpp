#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <iterator>
# include <vector>
# include <list>

class Easyfind_exeption: public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Iterator not found");
		}
};

template <typename T>
typename T::iterator	easyfind(T &v, int value)
{
	typename T::iterator	ptr_value;
	ptr_value = find(v.begin(), v.end(), value);
	if (ptr_value == v.end())
	{
		throw (Easyfind_exeption());
	}
	return (ptr_value);
}


#endif