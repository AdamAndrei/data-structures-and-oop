#include <iostream>
#include <vector>
#include <string>
#include "../include/LinkedList.h"
#include "../include/Problem1.h"
#include "../include/OrderedLinkedList.h"
#include "../include/Stack.h"

using namespace std;

void showBasicLinkedList()
{
    LinkedList<int> integerList;
    integerList.addFront(1);
    integerList.addFront(2);
    integerList.addFront(3);
    integerList.addFront(4);
    integerList.print();

    integerList.addTail(4);
    integerList.print();

    integerList.updateElement(4, 5);
    integerList.print();

    integerList.deleteElement(5);
    integerList.print();

    integerList.insertAfterElement(2, 100);
    integerList.print();

    integerList.insertBeforeElement(100, 999);
    integerList.print();

    integerList.clear();
    integerList.print();
}

void problem1()
{
    LinkedList<int> li;
    li.addFront(1);
    li.addFront(2);
    li.addFront(1);
    li.addFront(3);
    li.addFront(2);
    li.addFront(2);
    li.addFront(2);
    li.addFront(5);
    li.addFront(5);

    std::cout << li << std::endl;
    int distinct = Problem1::distinctElementsCount(li);
    std::cout << "List has " << std::to_string(distinct) << " distinct elements using iterator and " << std::to_string(li.distinctElementsCount()) << " by the inner method!" << std::endl;
}

void orderedLinkedList()
{
    OrderedLinkedList<int> l;
    l.addG(6);
    l.addG(1);
    l.addG(4);
    l.addG(3);
    l.addG(8);
    l.print();
}

void testStack()
{
    Stack<int> s;
    s.add(1);
    s.add(3);
    s.add(2);

    std::cout << s << std::endl;

    int p = s.pop();

    std::cout << p << ", " << s.pop() << ", " << s.pop() << std::endl;

    std::cout << s << std::endl;
}

bool charSeqToSTack(std::string str)
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
                if (s.isEmpty() || ord[c] < ord[s.getTop()])
                {
                    s.add(c);
                }
                else
                {
                    s.clear();
                    return false;
                }
            }
            else
            {
                if (s.isEmpty())
                {
                    return false;
                }
                if (ord[c] - ord[s.getTop()] != 3)
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

int main()
{
    // showBasicLinkedList();
    // problem1();
    // orderedLinkedList();
    // testStack();

    std::cout << "is ordered: " << charSeqToSTack("{d[s(a)]}") << std::endl;
    std::cout << "is ordered: " << charSeqToSTack("{d[()()s(a)][]()}") << std::endl;
    std::cout << "is ordered: " << charSeqToSTack("{d[s(a)])}") << std::endl;

    return 0;
}
