TEMPLATE = lib
CONFIG += c++11

SOURCES += \
    ../editor.cpp \
    ../load.cpp \
    ../save.cpp \
    ../show.cpp \
    ../showodd.cpp \
    append_line.cpp \
    create_text.cpp \
    j.cpp \
    m.cpp \
    mp.cpp \
    process_forward.cpp \
    remove_all.cpp

HEADERS += \
    _text.h \
    text.h

DEFINES += MAKE_TEXT_LIB

QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
