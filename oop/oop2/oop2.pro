TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    list.cpp \
    base_container.cpp \
    exceptions.cpp \
    node.cpp

HEADERS += \
    list.h \
    base_container.h \
    base_iterator.h \
    base_iterator_implement.h \
    list_iterator.h \
    list_iterator_implement.h \
    const_list_iterator.h \
    const_list_iterator_implement.h \
    list_implement.h \
    exceptions.h \
    node.h
