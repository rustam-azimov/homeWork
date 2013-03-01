#include "listArray.h"

using namespace std;

ArrayList::ArrayList() {
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


bool ArrayList::isEmpty() {
     return (arrayList[0][1] == 0);
}

int ArrayList::findHole() {
    for (int i = 1; i <= arraySize; i++)
        if (arrayList[i][1] == -1)
            return i;
    return -1;
}

void ArrayList::increaseArray() {
     int newSize = arraySize*2;
     int **newArray = new int*[newSize];
     for (int i = 0; i < newSize; i++)
         newArray[i] = new int[2];
     for (int i = 0; i < arraySize; i++) {
         newArray[i][0] = arrayList[i][0];
         newArray[i][1] = arrayList[i][1];
     }
     for (int i = arraySize; i < newSize; i++) {
         newArray[i][0] = 0;
         newArray[i][1] = -1;
     }
     for (int i = 0; i < arraySize; i++)
         delete[] arrayList[i];
     delete[] arrayList;
     arraySize = newSize;
     arrayList = newArray;
     return;
}

void ArrayList::addValueInPos(int value, int position) {
     if (isEmpty()) {
         arrayList[1][0] = value;
         arrayList[1][1] = 0;
         arrayList[0][1] = 1;
         arrayCounter++;
         return;
     }
     if (arrayCounter == (arraySize - 1))
         increaseArray();
         int emptyElement = findHole();
     if (position > arrayCounter)
         position = arrayCounter + 1;
     int currentIndex = 0;
     for (int i = 0; i < position - 1; i++)
         currentIndex = arrayList[currentIndex][1];
     arrayCounter++;
     arrayList[emptyElement][0] = value;
     arrayList[emptyElement][1] = arrayList[currentIndex][1];
     arrayList[currentIndex][1] = emptyElement;
     return;
}

bool ArrayList::isContained(int value) {
     if (isEmpty())
         return false;
     int currentIndex = arrayList[0][1];;
     while (currentIndex != 0) {
           if (arrayList[currentIndex][0] == value)
               return true;
           currentIndex = arrayList[currentIndex][1];
     }
     return false;     
}

void ArrayList::removeValue(int value) {
     if (!isContained(value)) {
         cout << "List does not contain this element\n";
         return;
     }
     int currentIndex = arrayList[0][1];
     while (arrayList[arrayList[currentIndex][1]][0] != value)
         currentIndex = arrayList[currentIndex][1];
     int deletedElement = arrayList[currentIndex][1];
     arrayList[currentIndex][1] = arrayList[deletedElement][1];
     arrayList[deletedElement][0] = 0;
     arrayList[deletedElement][1] = -1;
     arrayCounter --;
     return;
}

int ArrayList::length() {
    return arrayCounter;
}

void ArrayList::print() {
     if (isEmpty()) {
         cout << "List is empty!";
         return;
     }
     int currentIndex = arrayList[0][1];
     while (currentIndex != 0) {
           cout << arrayList[currentIndex][0] << " ";
           currentIndex = arrayList[currentIndex][1];
     }
     cout << endl;
     return;
}

ArrayList::~ArrayList() {
     for (int i = 0; i < arraySize; i++)
         delete[] arrayList[i];
     delete[] arrayList;
}
