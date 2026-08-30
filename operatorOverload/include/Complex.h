#pragma once
#include <ostream>

class Complex
{
private:
    int realPart;
    int imagPart;

public:
    Complex();
    Complex(int r, int i);
    Complex(const Complex &other);
    ~Complex();

    Complex addUsingCurrentObj(const Complex &rhs);
    // metoda a clasei
    Complex operator+(const Complex &rhs) const;

    Complex addTwoComplexNumbers(const Complex &lhs, const Complex &rhs);
    // nu e metoda a clasei
    // friend Complex operator+(const Complex &lhs, const Complex &rhs);

    Complex addAnInt(int k) const;
    Complex operator+(int k) const;
    // Complex operator+(float k) const;

    friend Complex operator+(int k, const Complex &c);

    Complex &operator+=(const Complex &c);
    Complex &operator+=(int k);

    Complex operator-();
    Complex operator-(const Complex &c);
    Complex operator-(int k);
    friend Complex operator-(int k, const Complex &c);

    Complex &operator=(const Complex &c);

    // prefix
    Complex &operator++();
    // postfix
    // int e un parametru null doar pentru diferentiere
    Complex operator++(int);

    bool operator>=(const Complex &c) const;
    bool operator==(const Complex &c) const;

    bool operator<(const Complex &c) const;
    bool operator>(const Complex &c) const;

    friend std::ostream &operator<<(std::ostream &out, const Complex &c);
};
