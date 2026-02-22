#pragma once
#include "LinkedList.h"

class Problem1
{
public:
    template <typename T>
    static int distinctElementsCount(const LinkedList<T> &origList)
    {
        int count = 0;
        for (auto it = origList.begin(); it != origList.end(); ++it) {
            bool found = false;
            for (auto itC = it.next(); itC != origList.end(); ++itC) {
                if (*it == *itC) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                count++;
            }
        }

        return count;
    }
};