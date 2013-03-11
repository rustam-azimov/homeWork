#include "quickSort.h"

void QuickSort::sort() {
    qSort(0, arraySize - 1);
}

void QuickSort::qSort(int first, int last) {
    int referenceElement = array[(first + last)/ 2];
    int left = first;
    int right = last;
    while (left <= right)
    {
        while (array[left] < referenceElement)
            left++;
        while (array[right] > referenceElement)
            right--;
        if (left <= right) {
            int tempValue;
            tempValue = array[left];
            array[left] = array[right];
            array[right] = tempValue;
            left++;
            right--;
        }
    }
    if (left < last)
        qSort(left, last);
    if (first < right)
        qSort(first, right);
}
