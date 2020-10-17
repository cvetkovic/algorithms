//
// Created by jugos000 on 16-Oct-20.
//

#ifndef TESTGROUND_ARRAY_HPP
#define TESTGROUND_ARRAY_HPP

#include <algorithm>
#include <iostream>

using namespace std;

template<class T>
class Array {

private:
    static int gcd(int a, int b) {
        if (b == 0)
            return a;
        else
            return gcd(b, a % b);
    }

public:
    static void RotateLeft(T *array, const int n, const int p);

    static void RotateLeftInSets(T *array, const int n, const int p);

    static void Print(T *array, int n);

    static int BinarySearch(T *array, int n, int element);
};

template<class T>
void Array<T>::RotateLeft(T *array, const int n, const int p) {
    T temp[p];

    for (int i = 0; i < p; i++)
        temp[i] = array[i];
    for (int i = 0; i < n - p; i++)
        array[i] = array[i + p];
    for (int i = 0; i < p; i++)
        array[n - p + i] = temp[i];
}

template<class T>
void Array<T>::RotateLeftInSets(T *array, const int n, const int p) {
    int numberOfSets = Array<int>::gcd(n, p);

    for (int set = 0; set < numberOfSets; set++) {
        int tmp = array[set];
        int pos1 = set;

        while (true) {
            int pos2 = pos1 + p;

            if (pos2 >= n)
                pos2 -= n;

            if (set == pos2)
                break;

            array[pos1] = array[pos2];
            pos1 = pos2;
        }

        array[pos1] = tmp;
    }
}

template<class T>
void Array<T>::Print(T *array, int n) {
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";

    cout << endl;
}

template<class T>
int Array<T>::BinarySearch(T *array, int n, int element) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (array[mid] < element)
            low = mid + 1;
        else if (array[mid] > element)
            high = mid - 1;
        else
            return mid;
    }

    return -1;
}

#endif //TESTGROUND_ARRAY_HPP
