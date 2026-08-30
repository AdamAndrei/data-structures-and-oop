#pragma once
#include <ostream>

class Rational
{
private:
    int p;
    int q;
    int *m;

public:
    Rational(int p, int q);
    ~Rational();

    Rational &operator=(const Rational &r);

    bool operator>=(const Rational &r) const;

    friend std::ostream &operator<<(std::ostream &out, const Rational &r);
};
