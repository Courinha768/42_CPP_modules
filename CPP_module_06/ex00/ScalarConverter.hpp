#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <stdlib.h>
# include <cmath>
# include <iomanip>

class ScalarConverter
{

	public:
		static void	convert(const std::string s);


	private:
		ScalarConverter();
		ScalarConverter( ScalarConverter const & src );
		~ScalarConverter();
		
		ScalarConverter &		operator=( ScalarConverter const & rhs );

};

std::ostream &			operator<<( std::ostream & o, ScalarConverter const & i );

#endif /* ************************************************* SCALARCONVERTER_H */