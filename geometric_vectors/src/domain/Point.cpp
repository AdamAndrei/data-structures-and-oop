#include "geometric_vectors/domain/Point.h"

Point::Point() : x(0), y(0) {}

Point::Point(double x, double y) : x(x), y(y) {}

Point Point::operator+(const Point &other) const
{
    return Point(this->x + other.x, this->y + other.y);
}

Point Point::operator-(const Point &other) const
{
    return Point(this->x - other.x, this->y - other.y);
}

Point &Point::operator+=(const Point &other)
{
    this->x += other.x;
    this->y += other.y;
    return *this;
}

Point &Point::operator-=(const Point &other)
{
    this->x -= other.x;
    this->y -= other.y;
    return *this;
}

Point Point::operator-() const
{
    return Point(-this->x, -this->y);
}

std::ostream &operator<<(std::ostream &os, const Point &p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}