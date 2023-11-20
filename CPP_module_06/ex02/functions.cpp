#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>

Base*	generate(void)
{
	int		rnum = rand() % 3;
	Base*	base;

	try	{
	switch (rnum)
	{
		case 0:
			base = new A;
			break ;
		case 1:
			base = new B;
			break ;
		case 2:
			base = new C;
			break ;
	}	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (NULL);
	}
	return (base);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Its of type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Its of type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Its of type C" << std::endl;
	else
		std::cout << "It has no type" << std::endl;
}

void	identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Its of type A" << std::endl;
		return ;
	}
	catch (std::exception &e) {
		std::cout << "A exception" << std::endl;
	}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Its of type B" << std::endl;
		return ;
	}
	catch (std::exception &e) {
		std::cout << "B exception" << std::endl;
	}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Its of type C" << std::endl;
		return ;
	}
	catch (std::exception &e) {
		std::cout << "C exception" << std::endl;
	}
}
