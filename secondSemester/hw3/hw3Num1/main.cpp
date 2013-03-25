#include <iostream>
#include <cstdlib>
#include "sorterTest.h"

using namespace std;


 /**
  * @file main.cpp
  * @author Azimov Rustam <rustam.azimov19021995@gmail.com>
  *
  * @section DESCRIPTION
  *
  * This program allows the user to sort the array,
  * the desired length, with: bubble sort, dwarf sort, quick sort.
  */

int main() {
    SorterTest test;
    QTest::qExec(&test);
    return 0;
}
