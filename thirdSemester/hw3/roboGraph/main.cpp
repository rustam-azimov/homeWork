#include <QCoreApplication>

#include "test_roboGraph.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	TestRoboGraph test;
	QTest::qExec(&test);

	return a.exec();
}
