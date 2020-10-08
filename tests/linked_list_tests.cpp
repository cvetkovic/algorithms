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
    cout << list.GetMiddleElement2()->item << endl << endl;

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; i++)
        list.GetMiddleElement();
    auto stop = chrono::high_resolution_clock::now();

    cout << "1: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << endl;

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; i++)
        list.GetMiddleElement2();
    stop = chrono::high_resolution_clock::now();

    cout << "2: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << endl;

    // first function will be faster because there is no branching prediction inside 'while' loop
}