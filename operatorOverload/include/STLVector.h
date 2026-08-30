#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>

template <typename T>
class STLVector
{
private:
    std::vector<T> container;

    void forwardIterators();
    void reverseIterators();

    void indexedIteration();
    void simpleIteratorIteration();
    void forIteratorIteration();
    void simpleForIteration();

    void eraseIterator();

    void shuffle();
    static bool myComparer(const T &a, const T &b);

    void sortAscending();
    void sortDescendingWithComparer();
    void sortDescendingWithLambda();

    void findElement();
    void findElementIf();

    void countElement();
    void countElementIf();

    void reverseContainer();

public:
    void add(const T &e);

    void showIterators();

    void showIterations();

    void showErase();

    void showSort();

    void showFind();

    void showCount();

    void showReverse();
};

template <typename T>
inline void STLVector<T>::add(const T &e)
{
    this->container.push_back(e);
}

template <typename T>
inline void STLVector<T>::showIterators()
{
    this->forwardIterators();
    this->reverseIterators();
}

template <typename T>
inline void STLVector<T>::forwardIterators()
{
    typename std::vector<T>::iterator forwardIterator = this->container.begin();
    typename std::vector<T>::const_iterator constForwardIterator = this->container.cbegin();

    std::cout << *forwardIterator << std::endl;
    std::cout << *constForwardIterator << std::endl;

    forwardIterator++;
    constForwardIterator++;

    std::cout << *forwardIterator << std::endl;
    std::cout << *constForwardIterator << std::endl;

    forwardIterator = this->container.end() - 1;
    std::cout << *forwardIterator << std::endl;

    constForwardIterator = this->container.cend() - 1;
    std::cout << *constForwardIterator << std::endl;
    //-----------------------------------------------------------

    this->indexedIteration();

    *forwardIterator = 100;
    std::cout << *(this->container.end() - 1) << std::endl;
    std::cout << *constForwardIterator << std::endl;

    this->indexedIteration();

    // *constForwardIterator = 10;
    // std::cout << *(this->container.end() - 1) << std::endl;
    // std::cout << *forwardIterator << std::endl;
}

template <typename T>
inline void STLVector<T>::reverseIterators()
{
    // other time
}

template <typename T>
inline void STLVector<T>::showIterations()
{
    indexedIteration();
    simpleIteratorIteration();
    forIteratorIteration();
    simpleForIteration();
}

template <typename T>
inline void STLVector<T>::showErase()
{
    eraseIterator();
}

template <typename T>
inline void STLVector<T>::indexedIteration()
{
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
        // std::cout << i << ":" << this->container.at(i) << ", ";
    }

    std::cout << std::endl;
}

template <typename T>
inline void STLVector<T>::simpleIteratorIteration()
{
    typename std::vector<T>::iterator it = this->container.begin();

    std::cout << *it << std::endl;

    it++;
    std::cout << *it << std::endl;
    it++;
    std::cout << *it << std::endl;
    it++;
    std::cout << *it << std::endl;
}

template <typename T>
inline void STLVector<T>::forIteratorIteration()
{
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

template <typename T>
inline void STLVector<T>::simpleForIteration()
{

    for (const T &e : this->container)
    {
        std::cout << e << ", ";
    }

    std::cout << std::endl;
}

template <typename T>
inline void STLVector<T>::eraseIterator()
{
    typename std::vector<T>::iterator it = this->container.begin();
    it++;

    std::cout << *it << std::endl;
    this->indexedIteration();

    typename std::vector<T>::iterator eraseIt = this->container.erase(it);

    std::cout << *eraseIt << std::endl;
    std::cout << *it << std::endl;

    this->indexedIteration();

    this->container.pop_back();

    this->indexedIteration();
}

template <typename T>
inline void STLVector<T>::shuffle()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(this->container.begin(), this->container.end(), gen);
}

template <typename T>
inline bool STLVector<T>::myComparer(const T &a, const T &b)
{
    return a > b;
}

template <typename T>
inline void STLVector<T>::showSort()
{
    this->sortAscending();

    std::cout << std::endl;

    this->sortDescendingWithComparer();

    std::cout << std::endl;

    this->sortDescendingWithLambda();
}

template <typename T>
inline void STLVector<T>::sortAscending()
{
    this->shuffle();
    this->indexedIteration();

    // auto it = this->container.begin();
    // it++;
    // it++;
    // bazat operator<
    std::sort(this->container.begin(), this->container.end());

    this->indexedIteration();
}

template <typename T>
inline void STLVector<T>::sortDescendingWithComparer()
{
    this->shuffle();
    this->indexedIteration();

    std::sort(this->container.begin(), this->container.end(), myComparer);

    this->indexedIteration();
}

template <typename T>
inline void STLVector<T>::sortDescendingWithLambda()
{
    this->shuffle();
    this->indexedIteration();

    std::sort(this->container.begin(), this->container.end(), [](const T &a, const T &b)
              { return a > b; });

    this->indexedIteration();
}

template <typename T>
inline void STLVector<T>::showFind()
{
    this->findElement();

    std::cout << std::endl;

    this->findElementIf();
}

template <typename T>
inline void STLVector<T>::findElement()
{
    T defaultValue{};

    this->indexedIteration();

    // se bazeaza pe operator==
    typename std::vector<T>::iterator it = std::find(this->container.begin(), this->container.end(), defaultValue);

    if (it != this->container.end())
    {
        std::cout << "found default value at index " << std::distance(this->container.begin(), it) << std::endl;
    }
    else
    {
        std::cout << "default value not found" << std::endl;
    }
}

template <typename T>
inline void STLVector<T>::findElementIf()
{
    T defaultValue{};

    this->indexedIteration();

    auto myIt = this->container.begin();
    for (; myIt != this->container.end(); myIt++)
    {
        // varianta find default
        if (*myIt == defaultValue)
        {
            break;
        }

        // varianta find if
        // if (prdicat(*myIt))
        // {
        //     break;
        // }
    }

    // myIt a la prima aparitie a default value

    typename std::vector<T>::iterator it = std::find_if(this->container.begin(), this->container.end(), [&defaultValue](const T &e)
                                                        { return e == defaultValue; });

    if (it != this->container.end())
    {
        std::cout << "found default value at index " << std::distance(this->container.begin(), it) << std::endl;
    }
    else
    {
        std::cout << "default value not found" << std::endl;
    }
}

template <typename T>
inline void STLVector<T>::showCount()
{
    this->countElement();

    std::cout << std::endl;

    this->countElementIf();
}

template <typename T>
inline void STLVector<T>::countElement()
{
    T defaultValue{};

    this->indexedIteration();

    typename std::vector<T>::difference_type occurrences = std::count(this->container.begin(), this->container.end(), defaultValue);

    std::cout << "default value occurs " << occurrences << " times" << std::endl;
}

template <typename T>
inline void STLVector<T>::countElementIf()
{
    T defaultValue{};

    this->indexedIteration();

    typename std::vector<T>::difference_type occurrences = std::count_if(this->container.begin(), this->container.end(), [&defaultValue](const T &e)
                                                                         { return !(e == defaultValue); });

    std::cout << "non-default values: " << occurrences << std::endl;
}

template <typename T>
inline void STLVector<T>::showReverse()
{
    this->reverseContainer();
}

template <typename T>
inline void STLVector<T>::reverseContainer()
{
    this->shuffle();
    this->indexedIteration();

    std::reverse(this->container.begin(), this->container.end());

    this->indexedIteration();
}
