#ifndef MAINCLASS_H
#define MAINCLASS_H

#include "classField.h"

class Exception
{};

class MainClass
{
public:
    MainClass() throw(Exception);
    ~MainClass();

private:
    ClassField field;
};

#endif // MAINCLASS_H
