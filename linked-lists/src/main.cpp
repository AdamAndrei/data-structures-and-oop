#include <iostream>
#include <vector>
#include <string>
#include "../include/LinkedList.h"
#include "../include/Problem1.h"

using namespace std;


void showBasicLinkedList() {
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

void problem1() {
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
    std::cout << "List has " << std::to_string(distinct) << " distinct elements using iterator and " << std::to_string(li.distinctElementsCount()) <<  " by the inner method!" << std::endl;
}

int main()
{
    showBasicLinkedList();
    problem1();

    return 0;
}
