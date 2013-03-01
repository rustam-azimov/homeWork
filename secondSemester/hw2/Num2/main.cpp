#include "pointerstack.h"
#include "parser.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void testPointerStack() {
    Stack* object = new PointerStack;
    cout << "Test Pointer Stack" << endl;
    cout << "Pushing elements from 'a' to 'f' :" << endl;
    for (char i = 'a'; i < 'h'; i++) {
        object->push(i);
        cout << object->top() << " ";
    }
    cout << endl << "Pop 7 times and observe the top elements:" << endl;
    for (int i = 0; i < 7; i++) {
        object->pop();
        cout << object->top() << " ";
    }
    cout << endl;
    delete object;
}

void testParser() {
    cout << "Test Parser" << endl
         <<"Enter the expression:" << endl;
    char str[255];
    cin >> str;
    Parser* object = new Parser(str);
    cout << object->isCorrectExpression();
    delete object;
}

int main()
{
    testPointerStack();
    testParser();
    return 0;
}

