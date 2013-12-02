#ifndef TEST_ANTIVIRUSBASE_H
#define TEST_ANTIVIRUSBASE_H

#include <QObject>
#include <QtTest/QTest>

#include "antivirusBase.h"

class TestAntivirusBase : public QObject {
	Q_OBJECT

private slots:
	void initTestCase()
	{
		mAntivirusBase = new AntivirusBase();
	}

	void testIsContainVirus() {
		QVERIFY(!mAntivirusBase->isVirusKnown(3));
		QVERIFY(!mAntivirusBase->isVirusKnown(43));
		QVERIFY(mAntivirusBase->isVirusKnown(0));
	}

	void testAddVirus() {
		mAntivirusBase->addVirus(15);
		mAntivirusBase->addVirus(3);
		mAntivirusBase->addVirus(2);

		QVERIFY(mAntivirusBase->isVirusKnown(15));
		QVERIFY(mAntivirusBase->isVirusKnown(2));
	}

	void testPowerUp() {
		mAntivirusBase->powerUp(3);
	}

	void testAntvirusPower() {
		QVERIFY(mAntivirusBase->antivirusPower(15) == 15);

		mAntivirusBase->powerUp(15);
		mAntivirusBase->powerUp(15);
		mAntivirusBase->powerUp(15);

		QVERIFY(mAntivirusBase->antivirusPower(15) == 15 + AntivirusPower::learnSpeed * 3);
	}


	void cleanupTestCase()
	{
		delete mAntivirusBase;
	}

private:
	AntivirusBase *mAntivirusBase;
};

#endif // TEST_ANTIVIRUSBASE_H
