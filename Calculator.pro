QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calculator
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        calculatorwindow.cpp \
		api/tim/bitwise.cpp \
		api/tim/logic.cpp \
		api/tim/constants.cpp \
		api/tim/input.cpp \
		api/tim/strings.cpp \
		api/tim/number.cpp \
		api/josh/inversion.cpp \
		api/aleks/add.cpp \
		api/aleks/power.cpp \
		api/aleks/signtoggle.cpp \
		api/josh/circleEquation.cpp \
		api/andrew/memory.cpp \
		api/andrew/modular.cpp \
    helpwindow.cpp \
    aboutwindow.cpp

HEADERS  += calculatorwindow.h \
		api/tim/bitwise.h \
		api/tim/logic.h \
		api/tim/constants.h \
		api/tim/input.h \
		api/tim/strings.h \
		api/tim/number.h \
		api/josh/inversion.h \
		api/josh/circleEquation.h \
		api/aleks/add.h \
		api/aleks/power.h \
		api/aleks/signtoggle.h \
		api/andrew/memory.h \
		api/andrew/modular.h \
    helpwindow.h \
    aboutwindow.h

FORMS += \
    calculatorwindow.ui \
    helpwindow.ui \
    aboutwindow.ui
