#include "calculator.h"
#include <iostream>
#include <float.h>
#include <string.h>
#include <cstdlib>

using namespace std;

Calculator::Calculator(StackType type, char *ch) {
    switch (type) {
        case (array): {
            stack = new ArrayStack;
            break;
        }
        case (pointer): {
            stack = new PointerStack;
            break;
        }
    }
    expression = ch;
}

int state(char ch) {
    if (ch == '+')
        return 2;
    if (ch == '-')
        return 3;
    if (ch == '*')
        return 4;
    if (ch == '/')
        return 5;
    return 1;
}

double Calculator::calculate(){
        char *ch = expression;
        while (*ch != 0) {
            switch (state(*ch)) {
                case pls: {
                    double value1 = stack->top();
                    stack->pop();
                    double value2 = stack->top();
                    stack->pop();
                    double result = value2 + value1;
                    stack->push(result);
                    break;
                }
                case mns: {
                    double value1 = stack->top();
                    stack->pop();
                    double value2 = stack->top();
                    stack->pop();
                    double result = value2 - value1;
                    stack->push(result);
                    break;
                }
                case mlt: {
                    double value1 = stack->top();
                    stack->pop();
                    double value2 = stack->top();
                    stack->pop();
                    double result = value2 * value1;
                    stack->push(result);
                    break;
                }
                case dvn: {
                    double value1 = stack->top();
                    stack->pop();
                    double value2 = stack->top();
                    stack->pop();
                    double result = value2 / value1;
                    stack->push(result);
                    break;
                }
                case num: {
                stack->push(*ch - '0');
                    break;
                }
            }
            ch++;
        }
        return (stack->top());
}

Calculator::~Calculator() {
    delete stack;
}
