#include "Point.hpp"

Fixed	get_position(Point const point1, Point const point2, Point const point)
{
	Fixed	a((point1.getY() - point2.getY()) / (point1.getX() - point2.getX()));
	Fixed	b(point1.getY() - a * point1.getX());

	return (a * point.getX() + b - point.getY());
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	d1(get_position(a, b, point));
	Fixed	d2(get_position(b, c, point));
	Fixed	d3(get_position(a, c, point));

	Fixed	e1(get_position(a, b, c));
	Fixed	e2(get_position(b, c, a));
	Fixed	e3(get_position(a, c, b));

	if (d1 * e1 < 0 || d2 * e2 < 0 || d3 * e3 < 0)
		return (false);
	return (true);
}
