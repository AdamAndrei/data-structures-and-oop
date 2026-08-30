#pragma once
#include "Point.h"
#include <iostream>
#include <cstring>

class Vector
{
private:
    Point start;
    Point end;
    char* name;

public:
    Vector();
    Vector(const char* name, Point start, Point end);
    Vector(const char* name, double x1, double y1, double x2, double y2);
    Vector(const char* name, Point end);

    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    ~Vector();

    Point getStart() const { return this->start; }
    Point getEnd() const { return this->end; }

    void print() const;

    Vector operator+(const Vector &other) const;
    Vector operator-(const Vector &other) const;

    Vector &operator+=(const Vector &other);
    Vector &operator-=(const Vector &other);

    Vector operator-() const;

    friend std::ostream &operator<<(std::ostream &os, const Vector &v);
};
