TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

#DEPENDPATH = ./text
#INCLUDEPATH = ./text
#LIBS += -L./text/debug

SOURCES +=  \
    editor.cpp \
    load.cpp \
    save.cpp \
    show.cpp \
    showodd.cpp \
    text/append_line.cpp \
    text/create_text.cpp \
    text/j.cpp \
    text/m.cpp \
    text/mp.cpp \
    text/process_forward.cpp \
    text/remove_all.cpp

HEADERS +=  \
    common.h \
    text/_text.h \
    text/text.h

QMAKE_CFLAGS += -Wall

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

SUBDIRS += \
    text/text.pro

