#include "Rational.h"

Rational::Rational(int p, int q)
{
    this->p = p;
    this->q = q;
    this->m = new int(10);
}

Rational::~Rational()
{
    // delete this->m;
}

Rational &Rational::operator=(const Rational &r)
{
    // comparatie intre adrese
    if (this != &r)
    {
        this->p = r.p;
        this->q = r.q;
        this->m = new int(*r.m);
    }

    return *this;
}

bool Rational::operator>=(const Rational &r) const
{
    return this->p >= r.p && this->q >= r.q;
}

std::ostream &operator<<(std::ostream &out, const Rational &r)
{
    out << "numarator: " << r.p << " numitor: " << r.q;
    out << " m value: " << *r.m << " m address: " << r.m;
    return out;
}
