#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << "a   : " << a << std::endl;
	std::cout << "b   : " << b << std::endl;

	std::cout << "++a : " << ++a << std::endl;
	std::cout << "a   : " << a << std::endl;
	std::cout << "a++ : " << a++ << std::endl;
	std::cout << "a   : " <<a << std::endl;

	std::cout << "max : " << Fixed::max(a, b) << std::endl << std::endl;

	std::cout << "a   : " << a << std::endl;
	std::cout << "b   : " << b << std::endl;

	std::cout << a + b << std::endl;

	if (a == b)	{
		std::cout << "true" << std::endl;
	}
	
	return 0;
}