#ifndef TEST_OS_H
#define TEST_OS_H

#include <QObject>
#include <QtTest/QTest>

#include "osFactory.h"
#include "os.h"

class TestOS : public QObject {
	Q_OBJECT

private slots:
	void initTestCase()
	{
		mOSFactory = new OSFactory;

		mWindows = new Windows;
		mLinux = mOSFactory->createOS("Linux");
	}

	void testName() {
		QVERIFY(mWindows->name() == "Windows");
		QVERIFY(mLinux->name() == "Linux");
	}

	void testSafety() {
		QVERIFY(mWindows->safety() == 50);
		QVERIFY(mLinux->safety() == 100);
	}

	void cleanupTestCase()
	{
		delete mOSFactory;

		delete mWindows;
		delete mLinux;
	}

private:
	OS *mWindows;
	OS *mLinux;

	OSFactory *mOSFactory;
};

#endif // TEST_OS_H
