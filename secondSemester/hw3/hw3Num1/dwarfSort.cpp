#include "dwarfSort.h"

void DwarfSort::sort() {
    int i = 1;
    int j = 2;
    while(i < arraySize) {
        if (array[i - 1] <= array[i]) {
            i = j;
            j++;
        }
        else {
            int tempValue = array[i - 1];
            array[i - 1] = array[i];
            array[i] = tempValue;
            i--;
            if (i == 0) {
                i = j;
                j++;
            }
        }
    }
}
