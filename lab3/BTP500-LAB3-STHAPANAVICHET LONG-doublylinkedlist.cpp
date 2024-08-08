#include <iostream>
#include "lab3.h"

using namespace std;

void printList(const DList<int>& list) {
    int data[20];
    int numData = list.getData(data);
    for (int i = 0; i < numData; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main() {
    DList<int> DLinkedList1;

    cout << "DList: push_front() starting with empty list" << endl;
    cout << "Before push_front: " << endl;
    printList(DLinkedList1);

    DLinkedList1.push_front(1);
    cout << "After push_front: " << endl;
    printList(DLinkedList1);
    cout << endl;
    DLinkedList1.pop_front();


    cout << "DList: push_back() starting with empty list" << endl;
    cout << "Before push_back: " << endl;
    printList(DLinkedList1);
    DLinkedList1.push_back(1);

    cout << "After push_back: " << endl;
    printList(DLinkedList1);
    cout << endl;


    cout << "DList: push_front() 3 times then push_back() 3 times" << endl;
    cout << "Before push_front: " << endl;
    printList(DLinkedList1);
    DLinkedList1.push_front(2);
    DLinkedList1.push_front(3);
    DLinkedList1.push_front(4);
    cout << "after push_front: " << endl;
    printList(DLinkedList1);

    cout << "Before push_back: " << endl;
    printList(DLinkedList1);
    DLinkedList1.push_back(6);
    DLinkedList1.push_back(7);
    DLinkedList1.push_back(8);
    cout << "After push_back: " << endl;
    printList(DLinkedList1);
    cout << endl;


    cout << "DList: push_back() 3 times then push_front() 3 times" << endl;
    cout << "Before push_back: " << endl;
    printList(DLinkedList1);
    DLinkedList1.push_back(20);
    DLinkedList1.push_back(30);
    DLinkedList1.push_back(40);
    cout << "after push_back: " << endl;
    printList(DLinkedList1);
    cout << "Before push_front: " << endl;
    printList(DLinkedList1);
    DLinkedList1.push_front(60);
    DLinkedList1.push_front(70);
    DLinkedList1.push_front(80);
    cout << "After push_front: " << endl;
    printList(DLinkedList1);
    cout << endl;

    DList<int> DLinkedList2;
    cout << "DList: pop_front() and pop_back() on empty list" << endl;
    cout << "Before pop_front: " << endl;
    printList(DLinkedList2);
    DLinkedList2.pop_front();
    cout << "After pop_front: " << endl;
    printList(DLinkedList2);

    cout << "Before pop_back: " << endl;
    printList(DLinkedList2);
    DLinkedList2.pop_back();
    cout << "After pop_back: " << endl;
    printList(DLinkedList2);
    cout << endl;


    cout << "DList: pop_front() on non-empty list" << endl;
    cout << "Before pop_front: " << endl;
    printList(DLinkedList1);
    DLinkedList1.pop_front();
    cout << "After pop_front: " << endl;
    printList(DLinkedList1);
    cout << endl;


    cout << "DList: pop_back() on non-empty list" << endl;
    cout << "Before pop_back: " << endl;
    printList(DLinkedList1);
    DLinkedList1.pop_back();
    cout << "After pop_back: " << endl;
    printList(DLinkedList1);
    cout << endl;


    cout << "DList: alternating pop_front()/pop_back() on non-empty list" << endl;
    for(int i = 0; i < 3; i++) {
        cout << "Before pop_front: " << endl;
        printList(DLinkedList1);
        DLinkedList1.pop_front();
        cout << "After pop_front: " << endl;
        printList(DLinkedList1);

        cout << "Before pop_back: " << endl;
        printList(DLinkedList1);
        DLinkedList1.pop_back();
        cout << "After pop_back: " << endl;
        printList(DLinkedList1);
        cout << endl;
    }
    cout << endl;

    cout << "DList: calling push functions after pop functions." << endl;
    cout << "Before push_front: " << endl;
    printList(DLinkedList1);
    DLinkedList1.push_front(1);
    cout << "After push_front: " << endl;
    printList(DLinkedList1);
    DLinkedList1.pop_front();
    cout << "After pop_front: " << endl;
    printList(DLinkedList1);

    cout << "Before push_back: " << endl;
    printList(DLinkedList1);
    DLinkedList1.push_back(2);
    cout << "After push_back: " << endl;
    printList(DLinkedList1);
    DLinkedList1.push_front(3);
    cout << "After push_front: " << endl;
    printList(DLinkedList1);

    return 0;
}
