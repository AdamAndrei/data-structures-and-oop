#include <iostream>
#include <vector>
#include <string>
#include "../include/LinkedList.h"

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

int main()
{
    showBasicLinkedList();

    return 0;
}
