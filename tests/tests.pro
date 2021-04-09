include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG += qt

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov


HEADERS += \
    ../app/common.h \
    ../app/text/_text.h \
    ../app/text/text.h \
    extra_tests.h \
    j_test.h \
    m_test.h \
    save_test.h \
    show_test.h \
    showodd_test.h

SOURCES += main.cpp \
    ../app/load.cpp \
    ../app/save.cpp \
    ../app/show.cpp \
    ../app/showodd.cpp \
    ../app/text/append_line.cpp \
    ../app/text/create_text.cpp \
    ../app/text/j.cpp \
    ../app/text/m.cpp \
    ../app/text/mp.cpp \
    ../app/text/process_forward.cpp \
    ../app/text/remove_all.cpp

INCLUDEPATH += ../app

