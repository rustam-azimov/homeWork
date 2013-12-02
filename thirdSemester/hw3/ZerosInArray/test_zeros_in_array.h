#ifndef TEST_ZEROS_IN_ARRAY_H
#define TEST_ZEROS_IN_ARRAY_H

#include <QObject>
#include <QtTest/QTest>

#include "zerosInArray.h"

class TestZerosArray : public QObject {
Q_OBJECT

private slots:
void initTestCase()
{
	mSize = 100;
	mArray = new int[mSize];

	for (int i = 0; i < mSize; i++) {
		mArray[i] = 0;
	}
}

void testZeros1()
{
	for (int i = 0; i < mSize; i++) {
		mArray[i] = 2;
	}

	QVERIFY(countOfZerosInArray(mArray, mSize) == 0);
}

void testZeros2()
{
	for (int i = 0; i < mSize; i++) {
		mArray[i] = i % 2;
	}

	QVERIFY(countOfZerosInArray(mArray, mSize) == (mSize + 1) / 2);
}

void cleanupTestCase()
{
	delete[] mArray;
}

private:
	int *mArray;
	int mSize;
};
#endif // TEST_ZEROS_IN_ARRAY_H
