#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x_val, const float y_val) : x(x_val), y(y_val) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

float Point::getX() const
{
    return x.toFloat();
}

float Point::getY() const
{
    return y.toFloat();
}




