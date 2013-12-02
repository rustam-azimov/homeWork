#ifndef TEST_COMPUTER_H
#define TEST_COMPUTER_H

#include <QObject>
#include <QtTest/QTest>

#include <QSet>

#include "computer.h"
#include "osFactory.h"

class TestComputer : public QObject {
	Q_OBJECT

private slots:
	void initTestCase()
	{
		mOSFactory = new OSFactory;

		mComputerOne = new Computer(mOSFactory->createOS("Windows"));
		mComputerTwo = new Computer(mOSFactory->createOS("Linux"));
	}

	void testDefencePower() {
		QVERIFY(mComputerOne->safety() == 50);
	}

	void testLoadViruses() {
		QSet<int> viruses;

		viruses.insert(3);
		viruses.insert(5);
		viruses.insert(22);

		mComputerOne->loadViruses(viruses);
		mComputerOne->nextStep();

		QVERIFY(mComputerOne->numberOfViruses() == 3);
	}

	void testUniteViruses() {
		QSet<int> viruses;

		viruses.insert(12);
		viruses.insert(5);

		mComputerTwo->loadViruses(viruses);
		mComputerTwo->nextStep();

		QVERIFY(mComputerTwo->numberOfViruses() == 2);

		QSet<int> temp = mComputerTwo->viruses();
		mComputerOne->loadViruses(temp);
		mComputerOne->nextStep();
		temp = mComputerOne->viruses();
		mComputerTwo->loadViruses(temp);
		mComputerTwo->nextStep();

		QVERIFY(mComputerOne->numberOfViruses() == 4);
		QVERIFY(mComputerTwo->numberOfViruses() == 4);
	}

	void cleanupTestCase()
	{
		delete mComputerOne;
		delete mComputerTwo;

		delete mOSFactory;
	}

private:
	Computer *mComputerOne;
	Computer *mComputerTwo;

	OSFactory *mOSFactory;
};

#endif // TEST_COMPUTER_H
