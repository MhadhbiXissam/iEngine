
QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QVNCClient
TEMPLATE = app
INCLUDEPATH += ./../../include/
LIBS += -L./../../libs -lvncclient
SOURCES += main.cpp\
        mainwindow.cpp \
    qvncclientwidget.cpp

HEADERS  += mainwindow.h \
    qvncclientwidget.h

FORMS    += mainwindow.ui
