#include "RPN.hpp"

RPN::RPN()
{
}

static bool	isOperation(char c)
{
	return (c == ADDITION || c == SUBTRACTION
			|| c == MULTIPLICATION || c == DIVISION);
}

RPN::RPN(std::string input)
{
	int	numCounter = 0;
	int	opeCounter = 0;

	for (size_t i = 0; i < input.length(); i++)
	{
		if (isdigit(input[i]) || isOperation(input[i]))
		{
			if (isdigit(input[i]))
				numCounter++;
			else
				opeCounter++;
			_list.push_back(input[i]);
		}
		else if (!isspace(input[i]))
			throw (std::exception());
	}
	if (numCounter != opeCounter + 1)
		throw (std::exception());
}

RPN::RPN(const RPN &copy)
{
	_list = copy._list;
	_result = copy._result;
}

RPN::~RPN()
{
}

RPN & RPN::operator=(const RPN &assign)
{
	(void) assign;
	return *this;
}

double	RPN::getResult()	{
	return (_result);
}

void	RPN::solveEquation()
{
	std::list<double>	holdNumbers;
	double				num1;
	double				num2;

	_result = 0;
	while (!_list.empty())
	{
		while (isdigit(_list.front()))
		{
			holdNumbers.push_back(_list.front() - 48);
			_list.pop_front();
		}
		num2 = holdNumbers.back();
		holdNumbers.pop_back();
		num1 = holdNumbers.back();
		holdNumbers.pop_back();
		switch (_list.front())
		{
			case ADDITION:
				holdNumbers.push_back(num1 + num2);
				break;

			case SUBTRACTION:
				holdNumbers.push_back(num1 - num2);
				break;

			case MULTIPLICATION:
				holdNumbers.push_back(num1 * num2);
				break;

			case DIVISION:
				holdNumbers.push_back(num1 / num2);
				break;

			default:
				break;
		}
		_list.pop_front();
	}
	_result = holdNumbers.front();
}

