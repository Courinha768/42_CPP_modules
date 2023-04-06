#include <iostream>
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point a(23, 4);
	Point b(2, 3);
	Point c(8, 16);
	Point point(12, 9);

	std::cout << bsp(a, b, c, point) << std::endl;

	return 0;
}