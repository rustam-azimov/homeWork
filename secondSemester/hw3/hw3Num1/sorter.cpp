#include "sorter.h"

#include <iostream>

using namespace std;

Sorter::Sorter(int *inputArray, int size) {
    array = new int[size];
    for (int i = 0; i < size; i++)
        array[i] = inputArray[i];
    arraySize = size;
}

void Sorter::print() {
    for (int i = 0; i < arraySize; i++)
        cout << array[i] << " ";
    cout << endl;
}

Sorter::~Sorter(){
    delete[] array;
}
