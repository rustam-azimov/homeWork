/*#include "arrayStack.h"

ArrayStack::ArrayStack() {
    arraySize = 50;
    arrayCounter = 0;
    arrayList = new int*[arraySize];
    for (int i = 0; i < arraySize; i++) {
        arrayList[i] = new int[2];
    }
    for (int i = 0; i < arraySize; i++) {
    arrayList[i][0] = 0;
    arrayList[i][1] = -1;
    }
    arrayList[0][0] = -1;
    arrayList[0][1] = 0;
}

ArrayStack::~ArrayStack() {
    for (int i = 0; i < arraySize; i++)
        delete[] arrayList[i];
    delete[] arrayList;
}
*/

