#include "Harl.hpp"

#define NOTHING_TO_COMPLAIN "nothing"

void	Harl::filter(char* _clevel)
{
	size_t	i = 0;
	std::string	level(_clevel);
	std::string	levels[4] = {DEBUG, INFO, WARNING, ERROR};

	for (i = 0; i < 4; i++)
		if (level == levels[i])
			break ;

	switch (i)
	{
		case (0):
			this->complain(DEBUG);
			this->complain(INFO);
			this->complain(WARNING);
			this->complain(ERROR);
			break ;
		case (1):
			this->complain(INFO);
			this->complain(WARNING);
			this->complain(ERROR);
			break ;
		case (2):
			this->complain(WARNING);
			this->complain(ERROR);
			break ;
		case (3):
			this->complain(ERROR);
			break ;
		case (4):
			this->complain(NOTHING_TO_COMPLAIN);
			break ;
	}
}

int	main(int ac, char **av)
{
	Harl	_harl;
	
	(void)ac;
	_harl.filter(av[1]);
}