TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    list.cpp \
    base_container.cpp

HEADERS += \
    list.h \
    base_container.h \
    base_iterator.h \
    base_iterator_implement.h \
    list_iterator.h \
    list_iterator_implement.h
