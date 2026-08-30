#pragma once
#include <optional>
#include "LinkedList.h"

// Returns the middle element of a linked list in a single pass.
//
// Algorithm: slow/fast pointer (tortoise & hare)
//   - slow advances 1 step per iteration
//   - fast advances 2 steps per iteration
//   - when fast cannot advance 2 more steps, slow is at the middle
//
// For even-length lists the second middle is returned (e.g. 1->2->3->4 → 3).
// Returns std::nullopt for an empty list.

class GetMid
{
public:
    template <typename T>
    static std::optional<T> getMid(const LinkedList<T> &list)
    {
        if (list.begin() == list.end())
            return std::nullopt;

        auto slow = list.begin();
        auto fast = list.begin();

        // fast can advance 2 steps only when both the next and the one after exist
        while (fast != list.end() && fast.next() != list.end())
        {
            ++slow; // 1 step
            ++fast; // 1st of 2 steps
            ++fast; // 2nd of 2 steps
        }

        return *slow;
    }
};
