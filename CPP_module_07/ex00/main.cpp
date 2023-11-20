#include "whatever.hpp"
#include <iostream>

class Awesome
{
  public:
	Awesome(void) : _n(0) {}
	Awesome( int n ) : _n( n ) {}
	Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
	bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
	bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
	bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
	bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
	bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
	bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
	int get_n() const { return _n; }
  private:
	int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

int	main(void)
{
	std::cout << "---------------------" << std::endl;
	{
		int a = 5;
		int b = 6;

		std::cout << "a : " << a << std::endl;
		std::cout << "b : " << b << std::endl;
		swap(a, b);
		std::cout << "a : " << a << std::endl;
		std::cout << "b : " << b << std::endl;

		std::cout << "---------------------" << std::endl;

		std::string c = "Hello";
		std::string d = "World";

		std::cout << "c : " << c << std::endl;
		std::cout << "d : " << d << std::endl;
		swap(c, d);
		std::cout << "c : " << c << std::endl;
		std::cout << "d : " << d << std::endl;
	}
	std::cout << "---------------------" << std::endl;
	{
		int a = 5;
		int b = 6;

		std::cout << "a : " << a << std::endl;
		std::cout << "b : " << b << std::endl;
		std::cout << "max = " << max(a, b) << std::endl;
	}
	std::cout << "---------------------" << std::endl;
	{
		int a = 5;
		int b = 6;

		std::cout << "a : " << a << std::endl;
		std::cout << "b : " << b << std::endl;
		std::cout << "min = " << max(a, b) << std::endl;
	}
	std::cout << "---------------------" << std::endl;
	{
		Awesome	a(2), b(4);

		swap(a, b);
		std::cout << a << " " << b << std::endl;
		std::cout << max(a, b) << std::endl;
		std::cout << min(a, b) << std::endl;
	}
	std::cout << "---------------------" << std::endl;
}