#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <typename T>

class Array
{

	public:

		Array(void): _array(new T[0]), _size(0) {
		};
		Array(unsigned int n): _array(new T[n]), _size(n) {};
		Array(Array const & src)	{
			this->_size = src._size;
			this->_array = new T[src._size];
			for (int i = 0; i < src._size; i++)	{
				this->_array[i] = src._array[i];
			}
		}
		~Array()	{delete[] _array;}

		unsigned int size() const	{
			return (this->_size);
		}

		Array	&operator=(Array const &rhs)
		{
			if ( this != &rhs )	{
				delete[] (this->_array);
				this->_size = rhs._size;
				this->_array = new T[rhs._size];
				for (int i = 0; i < rhs._size; i++)	{
					this->_array[i] = rhs._array[i];
				}
			}
			return *this;
		}

		class OutOfBoundsExeption: public std::exception
		{
			public:
				virtual const char* what() const throw()	{
					return ("Array index is out of bounds");};
		};

		T&	operator[](int n) {
			if (0 <= n && n < this->_size) {
				return _array[n];
			} else {
				throw (OutOfBoundsExeption());
			}
		}

		const T& operator[](int n) const {
			if (0 <= n && n < _size) {
				return _array[n];
			} else {
				throw (OutOfBoundsExeption());
			}
		}

	private:
		T*		_array;
		int		_size;

};

#endif /* *********************************************************** ARRAY_H */