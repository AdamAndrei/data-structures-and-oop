#pragma once
#include <iostream>

class Point
{
private:
    double x;
    double y;

public:
    Point();
    Point(double x, double y);

    double getX() const { return x; }
    double getY() const { return y; }

    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }

    Point operator+(const Point &other) const;
    Point operator-(const Point &other) const;

    Point &operator+=(const Point &other);
    Point &operator-=(const Point &other);

    Point operator-() const;

    friend std::ostream &operator<<(std::ostream &os, const Point &p);
};