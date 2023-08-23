#-------------------------------------------------
#
# Project created by QtCreator 2020-04-27T23:18:17
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CoffeeDemo
TEMPLATE = app
#win32:CONFIG(debug){
#UI_DIR = $$PWD/Debug/temp/ui
#MOC_DIR = $$PWD/Debug/temp/moc
#RCC_DIR = $$PWD/Debug/temp/rcc
#OBJECTS_DIR = $$PWD/Debug/temp/obj
#DESTDIR = $$PWD/Debug/bin
#}

#临时文件存放位置
MOC_DIR         = temp/moc  #指定moc命令将含Q_OBJECT的头文件转换成标准.h文件的存放目录
RCC_DIR         = temp/rcc  #指定rcc命令将.qrc文件转换成qrc_*.h文件的存放目录
UI_DIR          = temp/ui   #指定ui命令将.ui文件转换成ui_*.h文件的存放目录
OBJECTS_DIR     = temp/obj  #指定目标文件(obj)的存放目录

#指定生成的应用程序放置的目录
IDE_SOURCE_TREE = $$PWD #.pro或.pri文件所在的位置
IDE_BUILD_TREE  = $$IDE_SOURCE_TREE/../
win32:CONFIG(debug, debug|release){
    contains(DEFINES, WIN64) {
    DESTDIR = $$IDE_BUILD_TREE/_debug64
    } else {
    DESTDIR = $$IDE_BUILD_TREE/_debug86
    }
} else:win32:CONFIG(release, debug|release){
    contains(DEFINES, WIN64) {
    DESTDIR = $$IDE_BUILD_TREE/_release64
    } else {
    DESTDIR = $$IDE_BUILD_TREE/_release86
    }
}

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += Common/Log/
INCLUDEPATH += Common/AppManager/
INCLUDEPATH += Common/ScreenManager/

SOURCES += \
        Common/AppManager/appframe.cpp \
        form.cpp \
        main.cpp \
        mainwindow.cpp \
        Common/Log/log.cpp \
        Common/ScreenManager/screenmanager.cpp \
        welcome.cpp \
        setting.cpp \
        appinit.cpp \
        quiwidget.cpp

HEADERS += \
        Common/AppManager/appframe.h \
        commandef.h \
        form.h \
        mainwindow.h \
        Common/Log/log.h \
        Common/AppManager/registerscreen.h \
        Common/ScreenManager/screenmanager.h \
        welcome.h \
        setting.h \
        appinit.h \
        quiwidget.h \
        head.h

FORMS += \
        form.ui \
        mainwindow.ui \
        welcome.ui \
        setting.ui

#指定编译器选项和项目配置
CONFIG  += c++11
CONFIG  += warn_on           #告诉qmake要把编译器设置为输出警告信息的

RESOURCES += \
    other/qss.qrc \
    other/main.qrc \
