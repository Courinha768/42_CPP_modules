#include <string>
#include <iostream>

int	main(void)
{
	std::string		_string		=	"HI THIS IS BRAIN";
	std::string*	stringPTR	=	&_string;
	std::string&	stringREF	=	_string;

	std::cout	<<	"string    address: "	<<	&_string	<< std::endl;
	std::cout	<<	"stringPTR address: "	<<	&stringPTR	<< std::endl;
	std::cout	<<	"stringREF address: "	<<	&stringREF	<< std::endl;

	std::cout	<<	"string    value: "		<<	_string		<< std::endl;
	std::cout	<<	"stringPTR value: "		<<	*stringPTR	<< std::endl;
	std::cout	<<	"stringREF value: "		<<	stringREF	<< std::endl;
}