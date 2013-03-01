#pragma once

class Parser {
public:
    Parser(char* ch);
    bool isCorrectExpression();
    ~Parser() {}
protected:
    bool isNumber();
    bool addition();
    bool multiplication();
    bool bracket();
    char *str;
    int brCounter;
};
