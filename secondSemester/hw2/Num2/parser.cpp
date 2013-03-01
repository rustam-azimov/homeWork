#include "Parser.h"
#include <iostream>

Parser::Parser(char *ch) {
str = ch;
brCounter = 0;
}

bool Parser::isCorrectExpression() {
return addition();
}

bool Parser::isNumber() {
bool isNum = false;
if (*str == '+' || *str == '-')
str++;
if (isdigit(*str))
isNum = true;
while (isdigit(*str))
str++;
return isNum;
}

bool Parser::addition() {
if (!multiplication())
return false;
while (*str == '+' || *str == '-') {
str++;
if (!multiplication())
return false;
}
if (brCounter > 0) {
if (*str != ')')
return false;
} else
if (*str != 0)
return false;
return true;
}

bool Parser::bracket() {
if (*str == '(') {
brCounter++;
str++;
if (!addition())
return false;
if (*str == 0)
return false;
if (*str == ')')
brCounter--;
else
return false;
str++;
return true;
} else
return isNumber();
}

bool Parser::multiplication() {
if (!bracket())
return false;
while (*str == '*' || *str == '/') {
str++;
if (!bracket())
return false;
}
return true;
}
