#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <list>

# define ADDITION '+'
# define SUBTRACTION '-'
# define MULTIPLICATION '*'
# define DIVISION '/'

class RPN
{
	public:
		RPN();
		RPN(std::string input);
		~RPN();
		
		RPN & operator=(const RPN &assign);

		void	solveEquation();
		double	getResult();
		
	private:
		RPN(const RPN &copy);

		std::list<char>	_list;
		double			_result;
		
};

#endif