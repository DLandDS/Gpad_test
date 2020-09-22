TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

LIBS += -L /usr/lib/ -lSDL2main -lSDL2
INCLUDEPATH += /usr/include/SDL2/

