# Linked List Problems

## Problem 2 — Print elements in reverse

### Approach

The `LinkedList` iterator is forward-only, so we cannot walk backwards directly.
Two clean options:

**Option A — Vector accumulation (recommended):**
Collect all values into a `std::vector` via the iterator, then print from the last
index down to zero. O(n) time, O(n) space.

**Option B — Recursion:**
A recursive helper advances to the next element first, then prints on the way back
(post-order). Elegant, but uses O(n) call-stack space and risks stack overflow on
very long lists.

### Implementation (standalone, uses public Iterator API)

```cpp
// include/Problem2.h
#pragma once
#include <vector>
#include <iostream>
#include "LinkedList.h"

class Problem2
{
public:
    template <typename T>
    static void printReverse(const LinkedList<T> &list)
    {
        std::vector<T> values;
        for (auto it = list.begin(); it != list.end(); ++it)
            values.push_back(*it);

        for (int i = static_cast<int>(values.size()) - 1; i >= 0; --i)
        {
            std::cout << values[i];
            if (i > 0) std::cout << " -> ";
        }
        std::cout << std::endl;
    }
};
```

### Complexity
| | Time | Space |
|---|---|---|
| Vector approach | O(n) | O(n) |
| Recursive approach | O(n) | O(n) call stack |

---

## Problem 3 — Reverse a linked list

### Approach

Two flavours worth knowing:

**Option A — Non-mutating (standalone, uses public API):**
Iterate the original list forward and `addFront` each value into a new list.
Because `addFront` prepends, it naturally reverses the order. Returns a brand-new
`LinkedList<T>`, leaving the original untouched.

**Option B — In-place (method on `LinkedList`):**
The classic three-pointer walk: `prev`, `curr`, `next`. At each step, flip
`curr->next` to point backwards, advance all three pointers, repeat. After the
loop, `head` is updated to the last node visited. O(n) time, O(1) space. Requires
access to the private `head` pointer, so it must live inside the class.

### Implementation A — standalone, returns new list

```cpp
// include/Problem3.h
#pragma once
#include "LinkedList.h"

class Problem3
{
public:
    template <typename T>
    static LinkedList<T> reversed(const LinkedList<T> &list)
    {
        LinkedList<T> result;
        for (auto it = list.begin(); it != list.end(); ++it)
            result.addFront(*it);   // prepend = reverse order
        return result;
    }
};
```

### Implementation B — in-place method inside `LinkedList`

Add inside `LinkedList<T>`:

```cpp
void reverse()
{
    node *prev = nullptr;
    node *curr = head;
    while (curr != nullptr)
    {
        node *next = curr->next;  // save successor
        curr->next = prev;        // flip the link
        prev = curr;              // advance prev
        curr = next;              // advance curr
    }
    head = prev;                  // prev is now the new head
}
```

Step-by-step on `1 -> 2 -> 3 -> null`:

```
Start:  prev=null  curr=1  next=2   →  flip: 1->null
Step 2: prev=1     curr=2  next=3   →  flip: 2->1
Step 3: prev=2     curr=3  next=null→  flip: 3->2
End:    curr=null, head=3
Result: 3 -> 2 -> 1 -> null  ✓
```

### Complexity
| | Time | Space |
|---|---|---|
| Non-mutating (Option A) | O(n) | O(n) — new list |
| In-place (Option B) | O(n) | O(1) |

---

## Problem 4 — Compare two linked lists

### Approach

Walk both lists simultaneously with two iterators. At each step:
1. If the current elements differ → not equal, return `false`.
2. Advance both iterators.

After the loop, check that **both** iterators reached `end()`. If one list is
longer than the other, the shorter one's iterator will be at `end()` while the
longer one's won't — that also means not equal.

### Implementation (standalone, uses public Iterator API)

```cpp
// include/Problem4.h
#pragma once
#include "LinkedList.h"

class Problem4
{
public:
    template <typename T>
    static bool areEqual(const LinkedList<T> &a, const LinkedList<T> &b)
    {
        auto itA = a.begin();
        auto itB = b.begin();

        while (itA != a.end() && itB != b.end())
        {
            if (*itA != *itB) return false;
            ++itA;
            ++itB;
        }

        // both must be exhausted — guards against different lengths
        return itA == a.end() && itB == b.end();
    }
};
```

### Example usage

```cpp
LinkedList<int> x, y;
x.addTail(1); x.addTail(2); x.addTail(3);
y.addTail(1); y.addTail(2); y.addTail(3);
std::cout << Problem4::areEqual(x, y) << "\n";  // 1 (true)

y.addTail(4);
std::cout << Problem4::areEqual(x, y) << "\n";  // 0 (false)
```

### Complexity
| | Time | Space |
|---|---|---|
| Compare | O(min(n, m)) | O(1) |

---

---

## Problem 5 — Get the middle element (single pass)

### Approach: slow/fast pointer (tortoise & hare)

Use two iterators that start at `begin()`:
- **`slow`** advances **1 step** per iteration
- **`fast`** advances **2 steps** per iteration

When `fast` can no longer take 2 more steps, `slow` is sitting at the middle.
This is a single O(n) traversal with O(1) extra space — no need to know `size`.

The existing `Iterator::next()` method lets us peek one position ahead, so
`fast.next() != list.end()` tells us whether a second step is possible. No changes
to `LinkedList.h` are needed.

### Trace

```
List: 1 -> 2 -> 3 -> 4 -> 5

init : slow=1  fast=1
iter1: slow=2  fast=3   (fast: 1→2→3)
iter2: slow=3  fast=5   (fast: 3→4→5)
      fast.next() == end → stop
result: slow = 3  ✓
```

```
List: 1 -> 2 -> 3 -> 4   (even length → second middle returned)

init : slow=1  fast=1
iter1: slow=2  fast=3
iter2: slow=3  fast=end  (fast: 3→4→end)
      fast == end → stop
result: slow = 3  ✓
```

### Implementation

See [include/GetMid.h](include/GetMid.h).

```cpp
template <typename T>
static std::optional<T> getMid(const LinkedList<T> &list)
{
    if (list.begin() == list.end())
        return std::nullopt;

    auto slow = list.begin();
    auto fast = list.begin();

    while (fast != list.end() && fast.next() != list.end())
    {
        ++slow;
        ++fast;
        ++fast;
    }

    return *slow;
}
```

### Complexity
| | Time | Space |
|---|---|---|
| getMid | O(n) | O(1) |

---

## Notes on consistency with Problem 1

All three solutions follow the same pattern as `Problem1`:
- Standalone `class` with a `static` template method
- Only use the public `Iterator` API (`begin()`, `end()`, `operator*`, `operator++`, `operator!=`, `next()`)
- No friendship or access to private members required (except Problem 3 Option B,
  which is a proper method added to `LinkedList` itself)
