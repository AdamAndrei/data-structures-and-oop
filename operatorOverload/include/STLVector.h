#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
class STLVector
{
private:
    std::vector<T> container;

public:
    void add(const T &e);
    void showIterations();
};

template <typename T>
inline void STLVector<T>::add(const T &e)
{
    this->container.push_back(e);
}

template <typename T>
inline void STLVector<T>::showIterations()
{
    // classic
    for (int i = 0; i < this->container.size(); i++)
    {
        if (i == this->container.size() - 1)
        {
            std::cout << i << ":" << this->container[i];
        }
        else
        {
            std::cout << i << ":" << this->container[i] << ", ";
        }
    }

    std::cout << std::endl;

    typename std::vector<T>::iterator it = this->container.begin();

    std::cout << *it << std::endl;

    it++;
    std::cout << *it << std::endl;

    for (typename std::vector<T>::iterator it = this->container.begin(); it != this->container.end(); it++)
    {
        if (it == --this->container.end())
        {
            std::cout << *it;
        }
        else
        {
            std::cout << *it << ", ";
        }
    }

    std::cout << std::endl;
}
