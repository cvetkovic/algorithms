#include <chrono>
#include <iostream>

#include "collections/linked_list.hpp"

using namespace std;

int main() {
    List<int> list1, list2;

    list1.AddToTail(5);
    list1.AddToTail(10);
    list1.AddToTail(15);
    list1.AddToTail(40);

    list2.AddToTail(2);
    list2.AddToTail(3);
    list2.AddToTail(20);

    List<int>* reverseMerged = List<int>::MergeTwoListsInReverseOrder(list1, list2);

    cout << "List 1: " << list1 << endl;
    cout << "List 2: " << list2 << endl << endl;
    cout << "Merged: " << *reverseMerged << endl;

    delete reverseMerged;

    exit(0);
}
