#include <chrono>
#include <iostream>

#include "collections/linked_list.hpp"

using namespace std;

int main() {
    List<int> list;

    list.AddToHead(3);
    list.AddToHead(2);
    list.AddToHead(1);
    list.AddToTail(3);
    list.AddToTail(2);
    list.AddToTail(1);

    cout << "Printing whole list:" << endl;
    cout << list << endl << endl;

    cout << "Is palindrome: " << list.IsPalindrome_MiddleTraversal() << endl;

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; i++)
        list.IsPalindrome_Stack();
    auto stop = chrono::high_resolution_clock::now();

    cout << "1: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << endl;

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; i++)
        list.IsPalindrome_MiddleTraversal();
    stop = chrono::high_resolution_clock::now();

    cout << "2: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << endl;

    return 0;
}
