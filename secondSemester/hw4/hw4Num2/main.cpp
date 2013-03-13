#include <QtGui/QApplication>
#include "widget.h"

 /**
 * @file main.cpp
 * @author Azimov Rustam <rustam.azimov19021995@gmail.com>
 *
 * @section DESCRIPTION
 *
 * This is a program with a very simple calculator.
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    
    return a.exec();
}
