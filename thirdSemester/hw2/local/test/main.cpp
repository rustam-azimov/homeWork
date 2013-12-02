#include <QCoreApplication>

#include "test_virus.h"
#include "test_virusController.h"
#include "test_antivirusBase.h"
#include "test_computer.h"
#include "test_os.h"
#include "test_adjacencyMatrix.h"
#include "test_LANController.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	TestVirus test1;
	QTest::qExec(&test1);

	TestVirusController test2;
	QTest::qExec(&test2);

	TestAntivirusBase test3;
	QTest::qExec(&test3);

	TestComputer test5;
	QTest::qExec(&test5);

	TestOS test4;
	QTest::qExec(&test4);

	TestAdjacencyMatrix test6;
	QTest::qExec(&test6);

	TestLAN test7;
	QTest::qExec(&test7);

	return a.exec();
}
