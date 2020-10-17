#include <chrono>
#include <iostream>

#include "collections/array.hpp"

using namespace std;

int main() {
    const int n = 9;

    int *array = new int[n]{1, 2, 3, 4, 5, 6, 7, 8, 9};

    Array<int>::Print(array, n);
    cout << "Element 1 is at location: " << Array<int>::BinarySearch(array, n, 1) << endl;
    cout << "Element 3 is at location: " << Array<int>::BinarySearch(array, n, 3) << endl;
    cout << "Element 9 is at location: " << Array<int>::BinarySearch(array, n, 9) << endl;
}
