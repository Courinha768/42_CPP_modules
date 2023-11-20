#include "ScalarConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter( const ScalarConverter & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScalarConverter::~ScalarConverter()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScalarConverter &				ScalarConverter::operator=( ScalarConverter const & rhs )
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

std::ostream &	operator<<( std::ostream & o, ScalarConverter const & i )
{
	(void)i;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	printChar(const std::string& s)
{
	try
	{
		int	c = std::atoi(s.c_str());
		if (c > 32 && c < 127)
		{
			std::cout << "char: " << "'" << '\0' + c << "'" << std::endl;
		}
		else
			std::cout << "char: " << "Non displayable" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "char: impossible" << std::endl;
	}
}

void	printInt(const std::string s)
{
	try
	{
		if (!s.compare("+inf") || !s.compare("+inff")
		|| !s.compare("-inf") || !s.compare("-inff")
		|| !s.compare("nan") || !s.compare("nanf"))
			throw std::exception();
		std::cout << "int: " << std::atoi(s.c_str()) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "int: impossible" << std::endl;
	}
}

void	printFloat(const std::string& s)
{
	try
	{
		double	num = std::atof(s.c_str());

		std::cout << std::fixed;
		if (num == round(num))
			std::cout << std::setprecision(1);
		std::cout << "float: " << num << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "float: " << "impossible" << std::endl;
	}
}

void	printDouble(const std::string& s)
{
	try
	{
		double	num = std::atof(s.c_str());

		std::cout << std::fixed;
		if (num == round(num))
			std::cout << std::setprecision(1);
		std::cout << "double: " << num << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "double: impossible" << std::endl;
	}
}

void	ScalarConverter::convert(const std::string s)
{
	printChar(s);
	printInt(s);
	printFloat(s);
	printDouble(s);
}

/* ************************************************************************** */