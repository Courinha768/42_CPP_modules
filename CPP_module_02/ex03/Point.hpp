#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <string>

# include "Fixed.hpp"

class Point
{

	public:

		Point();
		Point( Point const & src );
		Point(const float _x, const float _y);
		~Point();

		Point &		operator=( Point const & rhs );

		Fixed	getX( void ) const;
		Fixed	getY( void ) const;

	private:

		Fixed const	x;
		Fixed const	y;

};

std::ostream &			operator<<( std::ostream & o, Point const & i );

#endif /* *********************************************************** POINT_H */