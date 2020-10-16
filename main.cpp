#include <chrono>
#include <iostream>

#include "collections/linked_list.hpp"

using namespace std;

int main() {
    List<int> list;

    list.AddToTail(1);
    list.AddToTail(1);
    list.AddToTail(2);
    list.AddToTail(0);
    list.AddToTail(2);
    list.AddToTail(0);
    list.AddToTail(1);

    cout << "Printing list:" << endl;
    cout << list << endl << endl;

    list.Sort012s();

    cout << "Printing sorted list:" << endl;
    cout << list << endl << endl;
}
