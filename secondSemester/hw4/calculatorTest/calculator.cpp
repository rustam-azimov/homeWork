#include "calculator.h"

Calculator::Calculator() {
    clear();
}

void Calculator::clear() {
    expression = "";
    leftNumb = "";
    rightNumb = "";
    currentOpr = "";
    isHaveDot = false;
    needToChangeNumb = false;
}

void Calculator::changeExpresion(QString str) {
    if ((str == "+") || (str == "-") || (str == "/") || (str == "*")) {
        calculate();
        needToChangeNumb = true;
        currentOpr = str;
    }else if(str == ".") {
        if(!isHaveDot) {
            isHaveDot = true;
            rightNumb = rightNumb + ".";
            expression = rightNumb;
        }
    }else {
        if(needToChangeNumb){
            needToChangeNumb = false;
            isHaveDot = false;
            leftNumb = rightNumb;
            rightNumb = str;
            expression = rightNumb;
        } else {
            rightNumb = rightNumb + str;
            expression = rightNumb;
        }
    }
}


void Calculator::calculate() {
    if ((leftNumb != "")&&(rightNumb != "")&&(currentOpr != "")) {
        float leftValue = leftNumb.toFloat();
        float rightValue = rightNumb.toFloat();
        char opr = (char)*currentOpr.toLatin1();
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
        if (result == (int)result) {
            isHaveDot = false;
        }
        else {
            isHaveDot = true;
        }
        rightNumb = QString::number(result);
        leftNumb = "";
        expression = rightNumb;
    }
}
