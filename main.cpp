#include <chrono>
#include <iostream>

#include "collections/array.hpp"
#include "collections/linked_list.hpp"

using namespace std;

int main() {
    const int n = 9;

    int *array = new int[n]{1, 2, 3, 4, 5, 6, 7, 8, 9};

    Array<int>::Print(array, n);
    Array<int>::RotateLeftInSets(array, n, 2);
    Array<int>::Print(array, n);
}
