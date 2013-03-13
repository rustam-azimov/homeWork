#include <QtGui/QApplication>
#include "widget.h"

 /**
 * @file main.cpp
 * @author Azimov Rustam <rustam.azimov19021995@gmail.com>
 *
 * @section DESCRIPTION
 *
 * In this program you can play all night long...
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    
    return a.exec();
}
