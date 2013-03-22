#include <QtGui/QApplication>
#include "widget.h"
#include "calculatorTest.h"

 /**
 * @file main.cpp
 * @author Azimov Rustam <rustam.azimov19021995@gmail.com>
 *
 * @section DESCRIPTION
 *
 * This is program - calculator, like a windows caclulator.
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
