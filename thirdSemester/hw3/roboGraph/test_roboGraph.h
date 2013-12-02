#ifndef TEST_ROBOGRAPH_H
#define TEST_ROBOGRAPH_H

#include <QObject>
#include <QtTest/QTest>

#include "roboGraph.h"

class TestRoboGraph : public QObject {
	Q_OBJECT

private slots:
	void initTestCase()
	{
		mTestSize = 5;

		mTestRobo1 = new RoboGraph(mTestSize);
		mTestRobo2 = new RoboGraph(mTestSize);
		mTestRobo3 = new RoboGraph(mTestSize);
	}

	void testRoboOne()
	{
		mTestRobo1->addLink(0, 4);
		mTestRobo1->addLink(1, 4);
		mTestRobo1->addLink(2, 4);
		mTestRobo1->addLink(3, 4);

		mTestRobo1->addRobot(0);
		mTestRobo1->addRobot(1);
		mTestRobo1->addRobot(2);

		QVERIFY(mTestRobo1->isAllRobotDestroyed() == true);
	}

	void testRoboTwo()
	{
		mTestRobo2->addLink(0, 1);
		mTestRobo2->addLink(0, 3);
		mTestRobo2->addLink(2, 3);
		mTestRobo2->addLink(2, 4);
		mTestRobo2->addLink(3, 3);
		mTestRobo2->addLink(3, 4);

		mTestRobo2->addRobot(2);
		mTestRobo2->addRobot(4);

		QVERIFY(mTestRobo2->isAllRobotDestroyed() == true);
	}

	void testRoboThree() {
		mTestRobo3->addLink(0, 1);
		mTestRobo3->addLink(0, 3);
		mTestRobo3->addLink(0, 4);
		mTestRobo3->addLink(1, 2);
		mTestRobo3->addLink(3, 4);

		mTestRobo3->addRobot(0);
		mTestRobo3->addRobot(3);
		mTestRobo3->addRobot(1);
		mTestRobo3->addRobot(4);
		mTestRobo3->addRobot(5);

		QVERIFY(mTestRobo3->isAllRobotDestroyed() == true);
	}

	void cleanupTestCase()
	{
		delete mTestRobo1;
		delete mTestRobo2;
		delete mTestRobo3;
	}


private:
	int mTestSize;

	RoboGraph *mTestRobo1;
	RoboGraph *mTestRobo2;
	RoboGraph *mTestRobo3;
};


#endif // TEST_ROBOGRAPH_H
