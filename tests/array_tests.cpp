//
// Created by jugos000 on 17-Oct-20.
//

#include "../collections/array.hpp"

#include <chrono>
#include <iostream>

using namespace std;

void RotateLeft() {
    const int n = 9;

    int *array = new int[n]{1, 2, 3, 4, 5, 6, 7, 8, 9};

    Array<int>::Print(array, n);
    Array<int>::RotateLeftInSets(array, n, 2);
    Array<int>::Print(array, n);
}


void BinarySearch() {
    const int n = 9;

    int *array = new int[n]{1, 2, 3, 4, 5, 6, 7, 8, 9};

    Array<int>::Print(array, n);
    cout << "Element 1 is at location: " << Array<int>::BinarySearch(array, n, 1) << endl;
    cout << "Element 3 is at location: " << Array<int>::BinarySearch(array, n, 3) << endl;
    cout << "Element 9 is at location: " << Array<int>::BinarySearch(array, n, 9) << endl;
}