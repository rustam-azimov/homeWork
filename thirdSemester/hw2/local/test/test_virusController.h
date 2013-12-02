#ifndef TEST_VIRUSCONTROLLER_H
#define TEST_VIRUSCONTROLLER_H

#include <QObject>
#include <QtTest/QTest>

#include "virusController.h"

class TestVirusController : public QObject {
	Q_OBJECT

private slots:
	void initTestCase()
	{
		mVirusController = new VirusController;
	}

	void testCreateVirus() {
		int temp = mVirusController->baseSize();

		mVirusController->createNewVirus();
		mVirusController->createNewVirus();
		mVirusController->createNewVirus();

		QVERIFY((mVirusController->baseSize() - temp) == 3);
	}

	void testPower() {
		mVirusController->createNewVirus();

		QVERIFY(mVirusController->virusPower(0) == -1);
		QVERIFY(mVirusController->virusPower(-10) == -1);
		QVERIFY(mVirusController->virusPower(1) > 0);
	}

	void testCreateHybridizeVirus() {
		int temp = mVirusController->baseSize();

		mVirusController->createNewVirus();
		mVirusController->createNewVirus();
		mVirusController->createNewVirus();

		QVERIFY((mVirusController->baseSize() - temp) == 3);

		QVERIFY(mVirusController->createHybridizeVirus(2, 3) > 0);

		QVERIFY((mVirusController->baseSize() - temp == 3)
				|| (mVirusController->baseSize() - temp == 4));
	}

	void cleanupTestCase()
	{
		delete mVirusController;
	}

private:
	VirusController *mVirusController;
};

#endif // TEST_VIRUSCONTROLLER_H
