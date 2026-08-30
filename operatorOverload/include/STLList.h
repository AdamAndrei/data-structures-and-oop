#pragma once
#include <list>
#include <algorithm>
#include <iostream>

template <typename T>
class STLList
{
private:
    std::list<T> container;

public:
    void addBack(const T &e);
    void addFront(const T &e);

    void iterateThrough();
};

template <typename T>
inline void STLList<T>::addBack(const T &e)
{
    this->container.push_back(e);
}

template <typename T>
inline void STLList<T>::addFront(const T &e)
{
    this->container.push_front(e);
}

template <typename T>
inline void STLList<T>::iterateThrough()
{
    for (auto it = this->container.begin(); it != this->container.end(); it++)
    {
        if (it == --this->container.end())
        {

            std::cout << *it;
        }
        else
        {

            std::cout << *it << ",";
        }
    }

    std::cout << std::endl;
}
