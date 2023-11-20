#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <cmath>

class Span
{

	public:

		Span(void);
		Span(unsigned int N);
		Span(Span const & src);
		~Span();

		unsigned int		getSize() const;
		int				getValue(int i) const;

		Span&	operator=(Span const & rhs);

		class OutOfBoundsException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class SpanTooSmallException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		void	addNumber(int value);
		void	addManyNumbers(int rangeStart, int rangeEnd);
		int		shortestSpan();
		int		longestSpan();

	private:

		unsigned int		_size;
		std::vector<int>	_array;

};

#endif /* ************************************************************ SPAN_H */