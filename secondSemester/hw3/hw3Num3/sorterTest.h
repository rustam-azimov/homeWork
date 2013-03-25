#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "matrixForSort.h"

class SorterTest : public QObject
{
    Q_OBJECT

 public:

   explicit SorterTest(QObject *parent = 0)
        : linesSize(10), columsSize(15), QObject(parent) {}

private slots:
       void initTestCase()
       {
           matrix = new MatrixForSort(linesSize, columsSize);
       }

       void testSorting()
       {
           matrix->sorting();
       }

       void cleanupTestCase()
       {
           delete matrix;
       }

private:
       int const linesSize;
       int const columsSize;
       MatrixForSort* matrix;
   };
