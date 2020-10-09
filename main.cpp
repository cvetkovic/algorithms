#include <chrono>
#include <iostream>

#include "collections/linked_list.hpp"

using namespace std;

int main() {
    List<int> list;

    ListNode<int>* n1 = new ListNode<int>(1);
    ListNode<int>* n2 = new ListNode<int>(2);
    ListNode<int>* n3 = new ListNode<int>(3);
    ListNode<int>* n4 = new ListNode<int>(4);
    ListNode<int>* n5 = new ListNode<int>(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n2;

    list.SetHead(n1);

    cout << "Existence of cycle in linked list: " << list.CheckIfCycleExists_Floyd() << endl;
    cout << "Loop length: " << list.CalculateLoopLength() << endl;

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; i++)
        list.CheckIfCycleExists_WithSet();
    auto stop = chrono::high_resolution_clock::now();

    cout << "1: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << endl;

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; i++)
        list.CheckIfCycleExists_WithVisited();
    stop = chrono::high_resolution_clock::now();

    cout << "2: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << endl;

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; i++)
        list.CheckIfCycleExists_Floyd();
    stop = chrono::high_resolution_clock::now();

    cout << "3: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << endl;

    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;

    exit(0);
}
