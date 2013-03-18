#pragma once

/**
* @file widget.h
*
* @section DESCRIPTION
*
* Calculator class realization.
*/

class Calculator {
public:
    Calculator();
    float calculate(float leftValue, char opr, float rightValue);
};
