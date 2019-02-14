TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

QMAKE_CXXFLAGS += -std=c++17

HEADERS += \
    profile.h \
    test_runner.h \
    translator.h
