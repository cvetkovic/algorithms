#include <chrono>
#include <iostream>

#include "collections/linked_list.hpp"

using namespace std;

int main() {
    List<int> list;

    list.AddToHead(3);
    list.AddToHead(2);
    list.AddToHead(1);
    list.AddToTail(4);
    list.AddToTail(5);
    list.AddToTail(6);

    cout << "Printing whole list:" << endl;
    cout << list << endl << endl;

    list.ReverseList_Recursively(list.GetHead());

    cout << "Printing whole reversed list:" << endl;
    cout << list << endl << endl;

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; i++)
        list.ReverseList_Recursively(list.GetHead());
    auto stop = chrono::high_resolution_clock::now();

    cout << "1: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << endl;

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; i++)
        list.ReverseList_Iterative();
    stop = chrono::high_resolution_clock::now();

    cout << "2: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << endl;

    return 0;
}
