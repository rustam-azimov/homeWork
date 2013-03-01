#include "listpointer.h"
#include <cstdlib>
#include <iostream>

using namespace std;

ListPointer::ListPointer() {
    head = new Node;
    head->next = NULL;
    nodeCounter = 0;
}

bool ListPointer::isEmpty() {
    if(head->next == NULL) {
        return true;
    }
    return false;
}

void ListPointer::addValueInPos(int value, int position) {
    if (isEmpty()) {
        head->next = new Node;
        head->next->value = value;
        head->next->next = NULL;
        nodeCounter++;
        return;
    }
    if (position > nodeCounter)
        position = nodeCounter + 1;
    Node* prevElement = head;
    for(int i = 0; i < (position - 1); i++ ) {
        prevElement = prevElement->next;
    }
    Node* addElement = new Node;
    addElement->next = prevElement->next;
    prevElement->next = addElement;
    addElement->value = value;
    nodeCounter++;
}

bool ListPointer::isContained(int value) {
    Node* temp = head->next;
    while(temp) {
        if(temp->value == value)
            return true;
        temp = temp->next;
    }
    return false;
}

void ListPointer::removeValue(int value) {
    if(!isContained(value)) {
        cout << "Did not find such value!" << endl;
        return;
    }
    Node* prevElement = head;
    while(!(prevElement->next->value == value))
        prevElement = prevElement->next;
    Node* deletedElement = prevElement->next;
    prevElement->next = deletedElement->next;
    delete deletedElement;
    nodeCounter--;
}

int ListPointer::length() {
    return nodeCounter;
}

void ListPointer::print() {
    if(isEmpty()) {
        cout << "Empty list!" << endl;
        return;
    }
    Node* temp = head->next;
    while(temp) {
        cout << temp->value << " ";
        temp= temp->next;
    }
    cout << endl;
}

ListPointer::~ListPointer() {
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
    delete &nodeCounter;
}
