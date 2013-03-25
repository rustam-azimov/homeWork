#include "sorterTest.h"

using namespace std;

 /**
  * @file main.cpp
  * @author Azimov Rustam <rustam.azimov19021995@gmail.com>
  *
  * @section DESCRIPTION
  *
  * This program allows the user to sort the columns of the matrix, of any size, from the first element.
  */

int main()
{
    SorterTest test;
    QTest::qExec(&test);
    return 0;
}

