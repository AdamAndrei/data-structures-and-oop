#pragma once
#include <iostream>
template <typename T>

class LinkedList
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
    LinkedList()
    {
        this->head = nullptr;
        this->size = 0;
    }
    ~LinkedList()
    {
        clear();
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

    void addFront(T val)
    {
        node *v = new node(val);
        v->next = this->head;
        this->head = v;
        size++;
    }

    bool isEmpty() const
    {
        return this->head == nullptr;
    }

    void print() const
    {
        std::cout << *this << std::endl;
    }

    void addTail(T val)
    {
        node *v = new node(val);
        node *current = head;
        while (current != nullptr)
        {
            if (current->next == nullptr)
            {
                current->next = v;
                size++;
                break;
            }
            current = current->next;
        }
    }

    void updateElement(T oldValue, T newValue)
    {
        node *current = head;
        while (current != nullptr)
        {
            if (current->value == oldValue)
            {
                current->value = newValue;
                break;
            }
            current = current->next;
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

    void insertAfterElement(T val, T valToAdd)
    {
        node *current = head;
        while (current != nullptr)
        {
            if (current->value == val)
            {
                node *v = new node(valToAdd);
                v->next = current->next;
                current->next = v;
                size++;
                break;
            }
            current = current->next;
        }
    }

    void insertBeforeElement(T val, T valToAdd)
    {
        if (isEmpty())
        {
            return;
        }
        if (head->value == val)
        {
            addFront(val);
        }

        node *previous = head;
        node *current = previous->next;

        while (previous != nullptr && current != nullptr)
        {
            if (current->value == val)
            {
                node *v = new node(valToAdd);
                previous->next = v;
                v->next = current;
                size++;
                break;
            }
            current = current->next;
            previous = previous->next;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list)
    {
        if (list.isEmpty())
        {
            os << "[empty list]";
            return os;
        }
        os << "size: " << std::to_string(list.size) << " | ";
        node* current = list.head;
        while (current != nullptr)
        {
            os << current->value << "~" << current->next;
            if (current->next != nullptr) {
                os << " -> ";
            }
            current =  current->next;
        }
        os << " -> null";
        return os;
    }
};
