#ifndef TEST_ADJACENCYMATRIX_H
#define TEST_ADJACENCYMATRIX_H

#include <QObject>
#include <QtTest/QTest>

#include "adjacencyMatrix.h"

class TestAdjacencyMatrix : public QObject {
	Q_OBJECT

private slots:
	void initTestCase()
	{
		mAdjacencyMatrix = new AdjacencyMatrix(5);
	}

	void testSize() {
		QVERIFY(mAdjacencyMatrix->size() == 5);
	}

	void testAddLink() {
		mAdjacencyMatrix->addLink(2, 3);

		QVERIFY(mAdjacencyMatrix->isConnected(2, 3));
		QVERIFY(mAdjacencyMatrix->isConnected(3, 2));
		QVERIFY(!mAdjacencyMatrix->isConnected(1, 4));
	}

	void testBreakLink() {
		mAdjacencyMatrix->breakLink(3, 2);

		QVERIFY(!mAdjacencyMatrix->isConnected(2, 3));
		QVERIFY(!mAdjacencyMatrix->isConnected(3, 2));
	}

	void testAddComputer() {
		mAdjacencyMatrix->addComputer();

		QVERIFY(mAdjacencyMatrix->size() == 6);
	}

	void testRemoveComputer() {
		mAdjacencyMatrix->removeComputer(3);
		mAdjacencyMatrix->removeComputer(4);

		QVERIFY(mAdjacencyMatrix->size() == 4);
	}

	void cleanupTestCase()
	{
		delete mAdjacencyMatrix;
	}

private:
	AdjacencyMatrix *mAdjacencyMatrix;
};


#endif // TEST_ADJACENCYMATRIX_H
