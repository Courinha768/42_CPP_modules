#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span(void)
{
	this->_size = 0;
}

Span::Span(unsigned int N)
{
	this->_size = N;
}

Span::Span(Span const & src)
{
	for (unsigned long i = 0; i < src._array.size(); i++)
		this->_array.push_back(src._array[i]);
	this->_size = src._size;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=(Span const & rhs)
{
	if ( this != &rhs )
	{
		this->_array.clear();
		for (unsigned long i = 0; i < rhs._array.size(); i++)
			this->_array.push_back(rhs._array[i]);
		this->_size = rhs._size;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

const char* Span::OutOfBoundsException::what() const throw()	{
	return ("Array index is out of bounds");
}

const char* Span::SpanTooSmallException::what() const throw()	{
	return ("Span is too small to find shortest/longest span");
}

unsigned int	Span::getSize()	const	{
	return (this->_size);
}

int	Span::getValue(int i) const	{
	if (i >= 0 && (unsigned long)i < this->_array.size())
		return (this->_array[i]);
	else
		throw (OutOfBoundsException());
	return (0);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	Span::addNumber(int value)
{
	if (this->_array.size() < this->_size)
		this->_array.push_back(value);
	else
		throw (Span::OutOfBoundsException());
}

void	Span::addManyNumbers(int rangeStart, int rangeEnd)
{
	for (int i = rangeStart; i <= rangeEnd; i++)
		this->addNumber(i);
}

int		Span::shortestSpan()
{
	if (this->_array.size() < 2)
		throw (SpanTooSmallException());

	int	shortest_distance = abs(this->_array[0] - this->_array[1]);
	for (unsigned long i = 0; i < this->_array.size() - 1; i++)
	{
		if (abs(this->_array[i] - this->_array[i + 1]) < shortest_distance)
			shortest_distance = abs(this->_array[i] - this->_array[i + 1]);
	}
	return (shortest_distance);
}

int		Span::longestSpan()
{
	if (this->_array.size() < 2)
		throw (SpanTooSmallException());

	int	longest_distance = 0;
	for (unsigned long i = 0; i < this->_array.size() - 2; i++)
	{
		if (abs(this->_array[i] - this->_array[i + 1]) > longest_distance)
			longest_distance = abs(this->_array[i] - this->_array[i + 1]);
	}
	return (longest_distance);
}

/* ************************************************************************** */