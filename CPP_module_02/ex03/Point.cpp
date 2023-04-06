#include "Point.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Point::Point() : x(Fixed()), y(Fixed()) {}

Point::Point(const Point & src) : x(src.x), y(src.y) {}

Point::Point(const float _x, const float _y) : x(Fixed(_x)), y(Fixed(_y)) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Point::~Point()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Point &				Point::operator=( Point const & rhs )
{
	this->~Point();
	new(this) Point(rhs.x.toFloat(), rhs.y.toFloat());
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Point const & i )
{
	o << "(" << i.getX() << "," << i.getY() << ")";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

Fixed	Point::getX( void ) const
{
	return (this->x);
}

Fixed	Point::getY( void ) const
{
	return (this->y);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */