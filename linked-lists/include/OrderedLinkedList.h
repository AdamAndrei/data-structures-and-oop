#pragma once
#include <iostream>

template <typename T>

class OrderedLinkedList
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
    OrderedLinkedList()
    {
        this->head = nullptr;
        this->size = 0;
    }

    ~OrderedLinkedList()
    {
        clear();
    }

    bool isEmpty() const
    {
        return this->head == nullptr;
    }

    void removeHead()
    {
        if (!isEmpty())
        {
            node *toDelete = this->head;
            this->head = this->head->next;
            delete toDelete;
            size--;
        }
    }

    void deleteElement(T val)
    {
        if (isEmpty())
        {
            return;
        }

        if (head->value == val)
        {
            removeHead();
        }
        node *previous = head;
        node *current = previous->next;
        while (previous != nullptr && current != nullptr)
        {
            if (current->value == val)
            {
                previous->next = current->next;
                delete current;
                size--;
                break;
            }
            previous = previous->next;
            current = current->next;
        }
    }

    void clear()
    {
        while (head != nullptr)
        {
            removeHead();
        }
        size = 0;
    }

    friend std::ostream &operator<<(std::ostream &os, const OrderedLinkedList<T> &list)
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
            os << current->value << "~" << current->next;
            if (current->next != nullptr)
            {
                os << " -> ";
            }
            current = current->next;
        }
        os << " -> null";
        return os;
    }

    int distinctElementsCount() const
    {
        node *current = this->head;
        int count = 0;
        while (current != nullptr)
        {
            bool found = false;
            node *checker = current->next;
            while (checker != nullptr)
            {
                if (checker->value == current->value)
                {
                    found = true;
                    break;
                }
                checker = checker->next;
            }
            if (!found)
            {
                count++;
            }

            current = current->next;
        }

        return count;
    }

    void print() const
    {
        std::cout << *this << std::endl;
    }

    void addG(T val)
    {
        node *v = new node(val);
        if (this->isEmpty())
        {
            this->head = v;
            this->size++;
            return;
        }

        if (this->head->value > val)
        {
            v->next = this->head;
            this->head = v;
            this->size++;
            return;
        }

        node *current = this->head;
        while (current != nullptr)
        {
            if (current->value < val && val <= current->next->value)
            {
                v->next = current->next;
                current->next = v;
                break;
            }

            current = current->next;
        }
    }

    void add(T val)
    {
        node *v = new node(val);
        if (this->isEmpty())
        {
            this->head = v;
            this->size++;
            return;
        }

        if (this->head->value > val)
        {
            v->next = this->head;
            this->head = v;
            this->size++;
            return;
        }

        node *previous = this->head;
        node *current = previous->next;
        while (previous != nullptr)
        {
            if (current == nullptr)
            {
                previous->next = v;
                this->size++;
                break;
            }

            if (current->value > val)
            {
                previous->next = v;
                v->next = current;
                this->size++;
                break;
            }

            previous = previous->next;
            current = current->next;
        }
    }
};