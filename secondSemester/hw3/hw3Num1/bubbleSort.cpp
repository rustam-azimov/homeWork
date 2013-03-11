#include "bubbleSort.h"

using namespace std;

void BubbleSort::sort() {
    bool isSorted = false;
    while(!isSorted) {
        isSorted = true;
        for (int i = 0; i < arraySize - 1; i++)
            if (array[i] > array[i+1]) {
                isSorted = false;
                int tempValue = array[i];
                array[i] = array[i+1];
                array[i+1] = tempValue;
            }
    }
}
