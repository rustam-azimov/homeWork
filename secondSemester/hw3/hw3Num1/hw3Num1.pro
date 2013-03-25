
QT += core \
    testlib

QT -= gui

TARGET = sorter
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    sorter.cpp \
    bubbleSort.cpp \
    quickSort.cpp \
    dwarfSort.cpp

HEADERS += \
    sorter.h \
    bubbleSort.h \
    quickSort.h \
    dwarfSort.h \
    sorterTest.h

