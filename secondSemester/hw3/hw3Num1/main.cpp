#include <iostream>
#include <cstdlib>
#include "bubbleSort.h"
#include "quickSort.h"
#include "dwarfSort.h"

using namespace std;

int main() {
    cout << "Enter size of the array: ";
    int size;
    cin >> size;
    int *arrayUser = new int[size];
    cout << "Original array:" << endl;
    for (int i = 0; i < size; i++) {
        arrayUser[i] = rand() %99;
        cout << arrayUser[i] << " ";
    }
    cout << endl;
    Sorter* bsort = new BubbleSort(arrayUser, size);
    bsort->sort();
    cout << "Sorted Bubble sort:" << endl;
    bsort->print();
    Sorter* dsort = new DwarfSort(arrayUser, size);
    dsort->sort();
    cout << "Sorted Dwarf sort:" << endl;
    dsort->print();
    Sorter* qsort = new QuickSort(arrayUser, size);
    qsort->sort();
    cout << "Sorted Quick sort:" << endl;
    qsort->print();
    return 0;
}
