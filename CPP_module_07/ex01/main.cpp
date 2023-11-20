#include "Iter.hpp"
#include <iostream>

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template<typename T>
void	print(T &element)
{
	std::cout << element << std::endl;
}

void	printchar(char c)
{
	std::cout << c;
}

int	main(void)
{
	{
		std::string	array1[] = {"Hello ", "World\n", "How ", "are ", "you?"};
		char		array2[] = {'a', 'b', 'c'};

		iter(array1, 4, print<std::string>);
		std::cout << std::endl << "-----------------------------" << std::endl;
		iter(array2, 2, print<char>);
		std::cout << std::endl << "-----------------------------" << std::endl;
		iter(array2, 3, printchar);
		std::cout << std::endl << "-----------------------------" << std::endl;
	}
	{
		int		tab[] = { 0, 1, 2, 3, 4 };
		Awesome	tab2[5];

		iter(tab, 5, print<const int>);
		iter(tab2, 5, print<Awesome>);
	}
}