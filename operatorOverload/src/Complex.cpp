#include "Complex.h"
#include <iostream>
#include <string>

Complex::Complex()
{
    this->realPart = 0;
    this->imagPart = 0;
}

Complex::Complex(int r, int i)
{
    this->realPart = r;
    this->imagPart = i;
}

Complex::Complex(const Complex &other)
{
    this->realPart = other.realPart;
    this->imagPart = other.imagPart;
    std::cout << "Copy constructor" << std::endl;
}

Complex::~Complex()
{
}

Complex Complex::addUsingCurrentObj(const Complex &rhs)
{
    return Complex(this->realPart + rhs.realPart, this->imagPart + rhs.imagPart);
}

Complex Complex::operator+(const Complex &rhs) const
{
    std::cout << "member function: operator+" << std::endl;
    return Complex(this->realPart + rhs.realPart, this->imagPart + rhs.imagPart);
}

Complex Complex::addTwoComplexNumbers(const Complex &lhs, const Complex &rhs)
{
    return Complex(lhs.realPart + rhs.realPart, lhs.imagPart + rhs.imagPart);
}

Complex Complex::addAnInt(int k) const
{
    return Complex(this->realPart + k, this->imagPart + k);
}

Complex Complex::operator+(int k) const
{
    return Complex(this->realPart + k, this->imagPart + k);
}

Complex &Complex::operator+=(const Complex &c)
{
    this->realPart += c.realPart;
    this->imagPart += c.imagPart;

    return *this;
}

Complex &Complex::operator+=(int k)
{
    this->realPart += k;
    this->imagPart += k;

    return *this;
}

Complex Complex::operator-()
{
    return Complex(-this->realPart, -this->imagPart);
}

Complex Complex::operator-(const Complex &c)
{
    return Complex(this->realPart - c.realPart, this->imagPart - c.imagPart);
}

Complex Complex::operator-(int k)
{
    return Complex(this->realPart - k, this->imagPart - k);
}

Complex &Complex::operator=(const Complex &c)
{
    if (this != &c)
    {
        this->realPart = c.realPart;
        this->imagPart = c.imagPart;
    }
    std::cout << "operator=" << std::endl;
    return *this;
}

Complex &Complex::operator++()
{
    this->realPart++;
    this->imagPart += 2;
    return *this;
}

Complex Complex::operator++(int)
{
    Complex old = *this;
    this->realPart++;
    this->imagPart += 2;
    return old;
}

bool Complex::operator>=(const Complex &c) const
{
    return this->realPart >= c.realPart && this->imagPart >= c.imagPart;
}

bool Complex::operator==(const Complex &c) const
{
    return this->realPart == c.realPart && this->imagPart == c.imagPart;
}

bool Complex::operator<(const Complex &c) const
{
    return this->realPart < c.realPart;
}

bool Complex::operator>(const Complex &c) const
{
    return this->realPart > c.realPart;
}

// Complex operator+(const Complex &lhs, const Complex &rhs)
// {
//     std::cout << "non-member(friend) function: operator+" << std::endl;
//     return Complex(lhs.realPart + rhs.realPart, lhs.imagPart + rhs.imagPart);
// }

Complex operator+(int k, const Complex &c)
{
    return Complex(c.realPart + k, c.imagPart + k);
}

Complex operator-(int k, const Complex &c)
{
    return Complex(k - c.realPart, k - c.imagPart);
}

std::ostream &operator<<(std::ostream &out, const Complex &c)
{
    out << std::to_string(c.realPart);
    if (c.imagPart < 0)
    {
        out << " - " << std::to_string(-c.imagPart) << "i";
    }
    else
    {
        out << " + " << std::to_string(c.imagPart) << "i";
    }
    return out;
}
