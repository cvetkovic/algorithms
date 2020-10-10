#include <chrono>
#include <iostream>

#include "collections/linked_list.hpp"

using namespace std;

int main() {
    List<int> list;

    list.AddToTail(3);
    list.AddToTail(4);
    list.AddToTail(5);
    list.AddToTail(2);
    list.AddToTail(4);
    list.AddToTail(5);
    list.AddToTail(4);
    list.AddToTail(9);
    list.AddToTail(9);

    cout << "Printing whole list:" << endl;
    cout << list << endl << endl;

    list.EvenOddSegregation();

    cout << "Even-odd segregated list: " << list << endl << endl;

    return 0;
}
