#ifndef TEST_LANCONTROLLER_H
#define TEST_LANCONTROLLER_H

#include <QObject>
#include <QtTest/QTest>

#include <QSet>

#include "lanController.h"

class TestLAN : public QObject {
	Q_OBJECT

private slots:
	void initTestCase()
	{
		mController = new LANController;
	}

	void testComputerNumber()
	{
		QVERIFY(mController->numberOfComputers() == 5);
	}

	void testAddComputer()
	{
		mController->addComputer("Windows");

		QVERIFY(mController->numberOfComputers() == 6);
	}

	void testLoadVirus()
	{
		mController->infectComputer(3);
	}

	void testConnectComputers()
	{
		mController->connectComputer(3, 4);

		QVERIFY(mController->connections(3).at(4)
				&& mController->connections(4).at(3));
	}

	void testStep() {
		mController->infectComputer(3);
		mController->infectComputer(2);
		mController->infectComputer(1);

		mController->nextStep();
		mController->nextStep();
		mController->nextStep();
		mController->nextStep();
	}

	void cleanupTestCase()
	{
		delete mController;
	}

private:
	LANController *mController;
};

#endif // TEST_LANCONTROLLER_H
