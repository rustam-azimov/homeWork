#ifndef TEST_VIRUS_H
#define TEST_VIRUS_H

#include <QObject>
#include <QtTest/QTest>

#include "virus.h"

class TestVirus : public QObject {
	Q_OBJECT

private slots:
	void initTestCase()
	{
		mVirusOne = new Virus(1);
		mVirusTwo = new Virus(2);
	}

	void testType() {
		QCOMPARE(mVirusOne->type(), 1);
		QCOMPARE(mVirusTwo->type(), 2);
	}

	void testPower() {
		QVERIFY(mVirusOne->power() > 0);
		QVERIFY(mVirusTwo->power() > 0);
	}

	void testCanHybridize() {
		QVERIFY((mVirusOne->power() > VirusPower::hybridizeBorder)
			== (mVirusOne->canHybridize()));
	}

	void testMutate() {
		mVirusOne->mutate();

		QVERIFY(mVirusOne->type() == 1);
	}

	void testHybridisation() {
		Virus *newVirus = new Virus(mVirusOne, mVirusTwo, 4);

		QVERIFY(((newVirus->type() == mVirusOne->type())
					&& (newVirus->power() == mVirusOne->power())
					)
				|| ((newVirus->type() == mVirusTwo->type())
					&& (newVirus->power() == mVirusTwo->power())
					)
				|| ((newVirus->type() == 4)
					&& (newVirus->power() > mVirusOne->power())
					&& (newVirus->power() > mVirusTwo->power())
					)
				);

		delete newVirus;
	}

	void cleanupTestCase()
	{
		delete mVirusOne;
		delete mVirusTwo;
	}

private:
	Virus *mVirusOne;
	Virus *mVirusTwo;
};

#endif // TEST_VIRUS_H
