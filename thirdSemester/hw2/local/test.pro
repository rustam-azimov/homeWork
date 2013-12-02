#-------------------------------------------------
#
# Project created by QtCreator 2013-11-22T16:51:32
#
#-------------------------------------------------

QT       += core \
    testlib

QT       -= gui

TARGET = local
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    test/main.cpp \
    virus.cpp \
    virusController.cpp \
    antivirusBase.cpp \
    computer.cpp \
    osFactory.cpp \
    lanController.cpp \
    adjacencyMatrix.cpp

HEADERS  += \
    virus.h \
    virusController.h \
    antivirusBase.h \
    computer.h \
    os.h \
    osFactory.h \
    lanController.h \
    adjacencyMatrix.h \
    test/test_adjacencyMatrix.h \
    test/test_antivirusBase.h \
    test/test_computer.h \
    test/test_LANController.h \
    test/test_os.h \
    test/test_virus.h \
    test/test_virusController.h
