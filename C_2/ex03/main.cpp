#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
#include <limits>
std::ostream &operator<<(std::ostream &output, Fixed const &fixed)
{
    output << fixed.toFloat();
    return output;
}

float triangleArea(const Point& p1, const Point& p2, const Point& p3)
{
    return std::abs((p1.getX() * (p2.getY() - p3.getY()) +
                     p2.getX() * (p3.getY() - p1.getY()) +
                     p3.getX() * (p1.getY() - p2.getY())) / 2.0f);
}

bool is_in_triangle(const Point& p1, const Point& p2, const Point& p3, const Point& p)
{
    float A = triangleArea(p1, p2, p3);
    float A1 = triangleArea(p, p2, p3);
    float A2 = triangleArea(p1, p, p3);
    float A3 = triangleArea(p1, p2, p);
    return A == (A1 + A2 + A3);
}

int main(void)
{
    Point p1(0, 0);
    Point p2(4, 0);
    Point p3(0, 3);
    Point p4(2, 1);

    std::cout << "Area of triangle: " << triangleArea(p1, p2, p3) << std::endl;
    std::cout << "Point p4 is in triangle: " << is_in_triangle(p1, p2, p3, p4) << std::endl;
    
    return 0;
}