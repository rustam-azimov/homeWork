#include <iostream>

#include "mainClass.h"

MainClass::MainClass() throw(Exception)
{
    std::cout << "Main class constructor called.\n";
    throw Exception();
}

MainClass::~MainClass()
{
    std::cout << "Main class destructor called.\n";
}
