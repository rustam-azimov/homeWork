#include <QtCore/QCoreApplication>

#include "mainClass.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    try
    {
        MainClass obj;
    }
    catch(Exception)
    {}

    return a.exec();
}
