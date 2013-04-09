#ifndef TESTBINARYTREE_H
#define TESTBINARYTREE_H

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "binaryTree.h"

class TestBinaryTree : public QObject
{
    Q_OBJECT
public:
    explicit TestBinaryTree(QObject* parent = 0):
        QObject(parent)
    {}

private slots:
    void init()
    {
        testTree = new BinaryTree<int>;
    }

    void cleanup()
    {
        delete testTree;
    }

    void testCreate() {}

    void testIsEmpty()
    {
        QVERIFY(testTree->isEmpty());
    }

    void testAdd()
    {
        testTree->add(6);
        testTree->add(228);
        QVERIFY(!testTree->isEmpty());
    }

    void testClearTree()
    {
        testTree->add(6);
        testTree->add(228);
        testTree->clearTree();
        QVERIFY(testTree->isEmpty());
    }

    void testIsContained()
    {
        QVERIFY(!testTree->isContained(6));
        testTree->add(6);
        QVERIFY(testTree->isContained(6));
        QVERIFY(!testTree->isContained(228));
    }

    void testRemove()
    {
        testTree->add(5);
        testTree->add(3);
        testTree->add(4);
        testTree->add(2);
        testTree->add(8);
        testTree->add(9);
        testTree->remove(8);
        testTree->remove(9);
        testTree->remove(3);
        testTree->remove(5);
        QVERIFY(!testTree->isContained(5));
        QVERIFY(!testTree->isContained(8));
        QVERIFY(!testTree->isContained(9));
        QVERIFY(!testTree->isContained(3));
    }

private:
    BinaryTree<int> *testTree;
};

#endif // TESTBINARYTREE_H
