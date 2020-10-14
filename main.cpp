#include <chrono>
#include <iostream>

#include "collections/linked_list.hpp"

using namespace std;

int main() {
    List<int> list1, list2;

    list1.AddToTail(7);
    list1.AddToTail(5);
    list1.AddToTail(9);
    list1.AddToTail(4);
    list1.AddToTail(6);

    list2.AddToTail(8);
    list2.AddToTail(4);

    cout << "Printing operands list:" << endl;
    cout << list1 << endl;
    cout << list2 << endl << endl;

    List<int>* sum = List<int>::AddTwoNumbers(list1,list2);

    cout << "Printing list after summation:" << endl;
    cout << *sum << endl;

    delete sum;
}
