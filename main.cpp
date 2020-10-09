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

    cout << "Element #3 from the end is: " << list.GetNthElementFromEnd_TwoPtrs(3)->item << endl;

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; i++)
        list.GetNthElementFromEnd_Counter(3);
    auto stop = chrono::high_resolution_clock::now();

    cout << "1: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << endl;

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; i++)
        list.GetNthElementFromEnd_TwoPtrs(3);
    stop = chrono::high_resolution_clock::now();

    cout << "2: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << endl;

    return 0;
}
