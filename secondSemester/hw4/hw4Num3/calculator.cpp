#include "calculator.h"

Calculator::Calculator() {

}

float Calculator::calculate(float leftValue, char opr, float rightValue) {
    float result = 0;
    switch (opr) {
    case '+': {
        result = leftValue + rightValue;
        break;
    }
    case '-': {
        result = leftValue - rightValue;
        break;
    }
    case '*': {
        result = leftValue * rightValue;
        break;
    }
    case '/': {
        result = leftValue / rightValue;
        break;
    }
    }
    return result;
}
