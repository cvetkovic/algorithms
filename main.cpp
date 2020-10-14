#include <chrono>
#include <iostream>

#include "collections/linked_list.hpp"

using namespace std;

int main() {
    List<int> list1, list2, list3;

    list1.AddToTail(12);
    list1.AddToTail(15);
    list1.AddToTail(10);
    list1.AddToTail(11);
    list1.AddToTail(5);
    list1.AddToTail(6);
    list1.AddToTail(2);
    list1.AddToTail(3);

    for (int i = 1; i <= 6; i++)
        list2.AddToTail(i * 10);

    for (int i = 6; i >= 1; i--)
        list3.AddToTail(i * 10);

    cout << "Printing whole list:" << endl;
    cout << list1 << endl << endl;
    cout << list2 << endl;
    cout << list3 << endl;

    list1.DeleteNodesWithGreaterValueOnRight();
    list2.DeleteNodesWithGreaterValueOnRight();
    list3.DeleteNodesWithGreaterValueOnRight();

    cout << "Printing list after deletion:" << endl;
    cout << list1 << endl;
    cout << list2 << endl;
    cout << list3 << endl << endl;
}
