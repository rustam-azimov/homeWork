#include <iostream>
#include <climits>
#include "arrayStack.h"

using namespace std;

ArrayStack::ArrayStack() {
    arraySize = 50;
    arrayCounter = 0;
    arrayStack = new double*[arraySize];
    for (int i = 0; i < arraySize; i++)
        arrayStack[i] = new double[2];
    for (int i = 0; i < arraySize; i++) {
            arrayStack[i][0] = 0;
            arrayStack[i][1] = -1;
    }
    arrayStack[0][0] = -1;
    arrayStack[0][1] = 0;
}

bool ArrayStack::isEmpty() const {
    return (arrayStack[0][1] == 0);
}

int ArrayStack::findHole() const {
    for (int i = 1; i <= arraySize; i++)
        if (arrayStack[i][1] == -1)
            return i;
    return -1;
}

void ArrayStack::increaseArray() {
    int newSize = arraySize * 2;
    double **newArray = new double*[newSize];
    for (int i = 0; i < newSize; i++)
        newArray[i] = new double[2];
    for (int i = 0; i < arraySize; i++) {
        newArray[i][0] = arrayStack[i][0];
        newArray[i][1] = arrayStack[i][1];
    }
    for (int i = arraySize; i < newSize; i++) {
        newArray[i][0] = 0;
        newArray[i][1] = -1;
    }
    for (int i = 0; i < arraySize; i++)
        delete[] arrayStack[i];
    delete[] arrayStack;
    arraySize = newSize;
    arrayStack = newArray;
    return;
}

void ArrayStack::push(double value) {
    if (isEmpty()) {
        arrayStack[1][0] = value;
        arrayStack[1][1] = 0;
        arrayStack[0][1] = 1;
        arrayCounter++;
        return;
    }
    if (arrayCounter == (arraySize - 1))
        increaseArray();
    int emptyElement = findHole();
    int currentIndex = 0;
    arrayCounter++;
    arrayStack[emptyElement][0] = value;
    arrayStack[emptyElement][1] = arrayStack[currentIndex][1];
    arrayStack[currentIndex][1] = emptyElement;
    return;
}

double ArrayStack::top() const {
    if (isEmpty()) {
        cout << "Stack is empty!";
        return INT_MAX;
    }
    return arrayStack[(int)arrayStack[0][1]][0];
}

void ArrayStack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty!";
        return;
    }
    int popedIndex = (int)arrayStack[0][1];
    arrayStack[0][1] = arrayStack[popedIndex][1];
    arrayStack[popedIndex][0] = 0;
    arrayStack[popedIndex][1] = -1;
    arrayCounter--;
}

ArrayStack::~ArrayStack() {
    for (int i = 0; i < arraySize; i++)
        delete[] arrayStack[i];
    delete[] arrayStack;
}

