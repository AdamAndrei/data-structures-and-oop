# Circular linked list

```cpp
#pragma once
#include <iostream>

template <typename T>

class CircularLinkedList
{
public:
    CircularLinkedList();
    ~CircularLinkedList();

    bool isEmpty() const;
    void insert(const T &val);

    void josephus(int p);

    friend std::ostream &operator<<(std::ostream &os, const CircularLinkedList<T> &list)
    {
        if (list.isEmpty())
        {
            os << "[empty list]";
            return os;
        }
        os << "size: " << std::to_string(list.size) << " | " << "head: " << list.head->value << " | ";
        node *current = list.head;
        do
        {
            os << current->value;
            if (current->next != list.head)
            {
                os << " -> ";
            }
            current = current->next;
        } while (current != list.head);

        os << " -> beginning";
        return os;
    }

private:
    struct node
    {
        T value;
        node *next;
        node(T val) : value(val), next(nullptr) {}
    };
    int size;
    node *head;

    void removeNext(node *&n);
};
```

The _head_ keeps track of the last item inserted, as now there is no beginning because the list is circular no _node_ will have its _next_ assigned as _nullptr_. You only need to implement the methods in this header.

```cpp
void removeNext(node *&n);
```

___removeNext___ is private because node is a private type — callers outside the class have no way to pass one. It handles the "kill" step in the Josephus problem: it deletes the node after _n_, not n itself. This is intentional — deleting a node in a singly linked list requires the predecessor to relink the chain, and here n is always that predecessor.

```cpp
void josephus(int p);
```

The [___Josephus problem___ (click here for details)](https://en.wikipedia.org/wiki/Josephus_problem) imagines the circular linked list and it just removes the _p-th_ element of the list (if the list has fewer than _p_ elements is not a problem as it is going around) untill only one is left. So here, because we start with the _head_ pointing to the last element inserted and we have the _removeNext_ method at each iteration we need to do ___p-1___ steps and then delete the next node from the one we landed on.


# Stack using linked list

```cpp
#pragma once

template <typename T>
class Stack
{
public:
    Stack();
    ~Stack();

    bool isEmpty() const;
    void push(const T &val);
    T pop();
    const T &peek() const;

private:
    struct node
    {
        T value;
        node *next;
        node(T val) : value(val), next(nullptr) {}
    };
    int size;
    node *top;
};
```

For a ___stack___ we only need to keep track of the ___top___ of the stack because it follows the rule _LIFO_ (__Last In, First Out__) meaning that we only _add to_/_remove from_ the top.

```cpp
void push(const T &val);
```
___push___ adds a new element to the top of the stack

<br>

```cpp
T pop();
```

___pop___ removes the top of the stack and returns the value (if the stack is empty an error should be thrown)


<br>

```cpp
const T &peek() const
```

___peek___ retrieves the value at the top of the stack, but it does not remove or add anything (if the stack is empty throw error).


## Use a stack to check paranthesis

Example: __{ (2+3)-30/6*[3*(4+2)] }__

### Idea

- give an order number for each paranthesis
- save in a stack the paranthesis as you go along the string
    - if it is an open bracket add it to the stack and move on (it means that another set of brackets is opened inside other brackets)
    - if it is a close bracket:
        - if the top of the stack is an open bracket  matching the current open one _pop_ it (because they are matching so it is fine and there is no need for the open bracket anymore cause we found its pair) and move on
        - otherwise, if the top is a closed bracket that does not match the current open one it means the expression is invalid

```cpp
bool isExpressionCorrect(std::string str)
{
    Stack<char> s;
    char ord[256] = {};
    ord['('] = 1;
    ord['['] = 2;
    ord['{'] = 3;
    ord[')'] = 4;
    ord[']'] = 5;
    ord['}'] = 6;

    for (char c : str)
    {
        if (ord[c] != 0)
        {
            if (ord[c] < 4) // open paranthesis
            {
                s.push(c);
            }
            else
            {
                if (s.isEmpty())
                {
                    return false;
                }
                if (ord[c] - ord[s.peek()] != 3)
                {
                    s.clear();
                    return false;
                }
                s.pop();
            }
        }
    }

    if (!s.isEmpty())
    {
        s.clear();
        return false;
    }

    return true;
}
```