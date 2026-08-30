#define _CRT_SECURE_NO_WARNINGS
#include "geometric_vectors/domain/Vector.h"

static char* copyStr(const char* src) {
    if (!src) return nullptr;
    char* buf = new char[strlen(src) + 1];
    strcpy(buf, src);
    return buf;
}

Vector::Vector() : start(0, 0), end(0, 0), name(nullptr) {}

Vector::Vector(const char* name, Point start, Point end)
    : start(start), end(end), name(copyStr(name)) {}

Vector::Vector(const char* name, double x1, double y1, double x2, double y2)
    : start(x1, y1), end(x2, y2), name(copyStr(name)) {}

Vector::Vector(const char* name, Point end)
    : start(0, 0), end(end), name(copyStr(name)) {}

Vector::Vector(const Vector& other)
    : start(other.start), end(other.end), name(copyStr(other.name)) {}

Vector& Vector::operator=(const Vector& other) {
    if (this == &other) return *this;
    delete[] name;
    name = copyStr(other.name);
    start = other.start;
    end = other.end;
    return *this;
}

Vector::~Vector() {
    delete[] name;
}

void Vector::print() const {
    std::cout << "Name address: " << static_cast<void*>(name) << "\n";
    std::cout << "Name value:   " << (name ? name : "(null)") << "\n";
    std::cout << "Vector:       " << *this << "\n";
}

Vector Vector::operator+(const Vector &other) const
{
    return Vector(nullptr, this->start + other.start, this->end + other.end);
}

Vector Vector::operator-(const Vector &other) const
{
    return Vector(nullptr, this->start - other.start, this->end - other.end);
}

Vector &Vector::operator+=(const Vector &other)
{
    this->start += other.start;
    this->end += other.end;
    return *this;
}

Vector &Vector::operator-=(const Vector &other)
{
    this->start -= other.start;
    this->end -= other.end;
    return *this;
}

Vector Vector::operator-() const
{
    return Vector(nullptr, -start, -end);
}

std::ostream &operator<<(std::ostream &os, const Vector &v)
{
    os << "[" << v.start << ", " << v.end << "]";
    return os;
}
