#pragma once
#include <iostream>
template <typename T>

class Stack
{
private:
    struct node
    {
        T value;
        node *next;
        node(T val) : value(val), next(nullptr) {}
    };
    node *head;
    int size;

public:
    Stack()
    {
        this->head = nullptr;
        this->size = 0;
    }
    ~Stack()
    {
        clear();
    }

    bool isEmpty() const
    {
        return this->head == nullptr;
    }

    void print() const
    {
        std::cout << *this << std::endl;
    }

    void clear()
    {
        while (head != nullptr)
        {
            pop();
        }
        size = 0;
    }

    T pop()
    {
        if (!isEmpty())
        {
            T v = this->head->value;
            node *toDelete = this->head;
            this->head = this->head->next;
            delete toDelete;
            size--;
            return v;
        }
        throw std::underflow_error("pop an empty stack");
    }

    T getTop()
    {
        if (!isEmpty())
        {
            return this->head->value;
        }
        throw std::underflow_error("get on an empty stack");
    }

    void add(T val)
    {
        node *v = new node(val);
        v->next = this->head;
        this->head = v;
        size++;
    }

    friend std::ostream &operator<<(std::ostream &os, const Stack<T> &list)
    {
        if (list.isEmpty())
        {
            os << "[empty list]";
            return os;
        }
        os << "size: " << std::to_string(list.size) << " | ";
        node *current = list.head;
        while (current != nullptr)
        {
            os << current->value;
            if (current->next != nullptr)
            {
                os << " -> ";
            }
            current = current->next;
        }
        os << " -> null";
        return os;
    }

    class Iterator
    {
    private:
        node *current;

    public:
        Iterator(node *v) : current(v) {};
        Iterator &operator++()
        {
            current = current->next;
            return *this;
        }

        T &operator*()
        {
            return current->value;
        }

        bool operator!=(const Iterator &other) const
        {
            return current != other.current;
        }

        Iterator next() const
        {
            Iterator temp = *this;
            ++temp;
            return temp;
        }
    };

    Iterator begin() const
    {
        return Iterator(head);
    }

    Iterator end() const
    {
        return Iterator(nullptr);
    }
};
