#include <QtGui/QApplication>
#include "widget.h"

#include "testTicTac.h"

int main(int argc, char *argv[])
{
    TestTicTac test;
    QTest::qExec(&test);

    QApplication a(argc, argv);
    Widget w;
    w.show();
    
    return a.exec();
}
