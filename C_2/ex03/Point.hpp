#ifndef POINT_HPP

# define POINT_HPP

# include <iostream>
# include <cmath>
# include "Fixed.hpp"

class Point {
private:
    const Fixed x;
    const Fixed y;

public:
    Point();
    Point(const float x_val, const float y_val);
    Point(const Point& other);
    Point& operator=(const Point& other);
    ~Point() {}
    float getX() const;
    float getY() const;
};

#endif