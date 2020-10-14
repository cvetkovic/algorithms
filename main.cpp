#include <chrono>
#include <iostream>

#include "collections/linked_list.hpp"

using namespace std;

int main() {
    List<int> list;

    list.AddToTail(1);
    list.AddToTail(2);
    list.AddToTail(3);
    list.AddToTail(4);
    list.AddToTail(5);
    list.AddToTail(6);

    cout << "Printing whole list:" << endl;
    cout << list << endl << endl;

    list.ReverseGroups(3);

    cout << "Printing whole reversed list:" << endl;
    cout << list << endl << endl;
}
