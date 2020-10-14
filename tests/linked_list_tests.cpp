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

    ListNode<int> *n1 = new ListNode<int>(1);
    ListNode<int> *n2 = new ListNode<int>(2);
    ListNode<int> *n3 = new ListNode<int>(3);
    ListNode<int> *n4 = new ListNode<int>(4);
    ListNode<int> *n5 = new ListNode<int>(5);

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

void RemoveDuplicatesFromSortedLinkedList() {
    List<int> list;

    list.AddToHead(3);
    list.AddToHead(2);
    list.AddToHead(1);
    list.AddToTail(3);
    list.AddToTail(3);
    list.AddToTail(4);

    cout << "Printing whole list:" << endl;
    cout << list << endl << endl;

    list.RemoveDuplicatesFromSorted();

    cout << "Printing whole duplicates removal (list was already sorted): " << list << endl << endl;
}

void RemoveDuplicatesFromUnoortedUsingSet() {
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

    list.RemoveDuplicatedFromUnsorted_Set();

    cout << "Printing whole duplicates removal (list was already sorted): " << list << endl << endl;
}

void EvenOddSegregation() {
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

    cout << "Printing whole list:" <<
         endl;
    cout << list << endl <<
         endl;

    list.EvenOddSegregation();

    cout << "Even-odd segregated list: " << list << endl <<
         endl;
}

void TwoListsIntersection() {
    List<int> list;

    ListNode<int> *t1 = new ListNode<int>(3);
    ListNode<int> *t2 = new ListNode<int>(6);
    ListNode<int> *t3 = new ListNode<int>(9);
    ListNode<int> *t4 = new ListNode<int>(15);
    ListNode<int> *t5 = new ListNode<int>(30);
    ListNode<int> *t6 = new ListNode<int>(10);

    List<int> l1, l2;
    l1.SetHead(t1);
    l2.SetHead(t6);

    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = t5;
    t5->next = nullptr;
    t6->next = t4;

    cout << "Intersection at node with value: " << List<int>::TwoListsIntersection(l1, l2)->item << endl;

    delete t1;
    delete t2;
    delete t3;
    delete t4;
    delete t5;
    delete t6;

    exit(0);
}

void MergeListsInReverseOrder() {
    List<int> list1, list2;

    list1.AddToTail(5);
    list1.AddToTail(10);
    list1.AddToTail(15);
    list1.AddToTail(40);

    list2.AddToTail(2);
    list2.AddToTail(3);
    list2.AddToTail(20);

    cout << "List 1: " << list1 << endl;
    cout << "List 2: " << list2 << endl << endl;

    List<int>* reverseMerged = List<int>::MergeTwoListsInReverseOrder(list1, list2);

    cout << "Merged: " << *reverseMerged << endl;

    delete reverseMerged;

    exit(0);
}

void ReverseGroups() {
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

void ListsEqualityAndCloning() {
    List<int> list;

    list.AddToTail(1);
    list.AddToTail(2);
    list.AddToTail(3);
    list.AddToTail(4);
    list.AddToTail(5);
    list.AddToTail(6);

    List<int> list2(list);

    cout << "Printing whole list:" << endl;
    cout << list << endl << endl;

    cout << "Lists equal: " << (list == list2) << endl;
}