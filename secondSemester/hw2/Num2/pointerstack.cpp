#include "pointerStack.h"

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

bool PointerStack::isEmpty() {
    return(head->next == NULL);
}

void PointerStack::push(char value) {
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

char PointerStack::top() {
    if(isEmpty()){
        cout << "List is empty!" << endl;
        return '!';
    }
    return(head->next->value);
}
