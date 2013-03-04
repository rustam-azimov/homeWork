#include "pointerStack.h"
#include <climits>
#include <cstdlib>
#include <iostream>

using namespace std;

PointerStack::PointerStack() {
    head = new Node;
    head->next = NULL;
    nodeCounter = 0;
}

PointerStack::~PointerStack() {
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

bool PointerStack::isEmpty() const {
    return(head->next == NULL);
}

void PointerStack::push(double value) {
    Node* addElement = new Node;
    addElement->value = value;
    addElement->next = head->next;
    head->next = addElement;
    nodeCounter++;
}

void PointerStack::pop() {
    if(isEmpty()) {
        cout << "List is Empty!" << endl;
        return;
    }
    Node* deletedElement = head->next;
    head->next = deletedElement->next;
    delete deletedElement;
    nodeCounter--;
}

double PointerStack::top() const {
    if(isEmpty()){
        cout << "List is empty!";
        return INT_MAX;
    }
    return(head->next->value);
}
