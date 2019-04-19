TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    io.cpp \
    gauss.cpp \
    interpolation.cpp

HEADERS += \
    io.h \
    gauss.h \
    interpolation.h
