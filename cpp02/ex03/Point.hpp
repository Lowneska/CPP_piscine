#ifndef _POINT_HPP_
#define _POINT_HPP_
#include "Fixed.hpp"
class Point
{
	private :
		Fixed x;
		Fixed y;
	public :
		Point();
		Point(const float, const float);
		Point(Point const &point);
		~Point();
		Point &operator=(const Point &point);

};
#endif