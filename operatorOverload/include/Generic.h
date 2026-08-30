#pragma once

// T anonim - nu e cunoscut
template <typename T>
class Generic
{
// private:
//     T a;
//     T b;
//     T[] c;

public:
    static T maximum(const T &a, const T &b);
};

template <typename T>
T Generic<T>::maximum(const T &a, const T &b)
{
    if (a >= b)
    {
        return a;
    }

    return b;
}
