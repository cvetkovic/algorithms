//
// Created by jugos000 on 10/8/2020.
//

#include "../collections/linked_list.hpp"

#include <chrono>
#include <iostream>
using namespace std;

void MiddleElementPerformanceTest() {
    List<int> list;

    list.AddToHead(3);
    list.AddToHead(2);
    list.AddToHead(1);
    list.AddToTail(4);
    list.AddToTail(5);
    list.AddToTail(6);

    cout << "Printing whole list:" << endl;
    cout << list << endl << endl;
    cout << "The middle element of the list is:" << endl;
    cout << list.GetMiddleElement_WithIf()->item << endl << endl;

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; i++)
        list.GetMiddleElement();
    auto stop = chrono::high_resolution_clock::now();

    cout << "1: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << endl;

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; i++)
        list.GetMiddleElement_WithIf();
    stop = chrono::high_resolution_clock::now();

    cout << "2: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << endl;

    // first function will be faster because there is no branching prediction inside 'while' loop
}

void LoopDetection() {
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

void ReverseList() {
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
}

void NthElementFromTheEnd() {
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
}