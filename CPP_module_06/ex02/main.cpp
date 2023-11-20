#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>
#include <time.h>

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

int	main(void)
{
	srand(time(NULL));

	Base*	base1 = generate();
	Base*	base2 = generate();
	Base*	base3 = generate();

	std::cout << "===================" << std::endl;
	identify(base1);
	std::cout << "===================" << std::endl;
	identify(*base2);
	std::cout << "===================" << std::endl;
	identify(base3);
	std::cout << "===================" << std::endl;

	delete base1;
	delete base2;
	delete base3;
}