#include "pointerStack.h"
#include "arrayStack.h"
#include "parser.h"
#include "calculator.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    cout << "The cacluator program." << endl;
    int type;
    while (true) {
        cout << "Enter the type of stack" << endl
             << "1 - array stack" << endl
                << "2 - pointer stack" << endl
                << "0 - exit" << endl;
        cin >> type;
        if (type == 0) {
            return 0;
        }
        if ( (type != 1) && (type != 2)) {
            cout << "Bad type of stack" << endl;
            return 1;
        }
        cout << "Enter the expression in Reverse Polish Notation" << endl;
        char string[255];
        cin >> string;
        Calculator *object = new Calculator((StackType)type, string);
        double result = object->calculate();
        delete object;
        cout << "The result is " << result << endl;
    }
    return 0;
}

