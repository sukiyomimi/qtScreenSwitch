#include "appframe.h"
#include "screenmanager.h"
#include "commandef.h"
#include <QApplication>
#include <QKeyEvent>
#include <QtCore>

#define KEY_PRESSPARAM(_KEY_ID, _KEY_STR) {\
    QKeyEvent event = QKeyEvent(QEvent::KeyPress, _KEY_ID, Qt::NoModifier, _KEY_STR);\
    if (ScreenManager::instance()->curScrn())\
    {\
       qApp->sendEvent(QApplication::focusWidget(), &event);\
    }\
}\

#define KEY_PRESS(_KEY_ID) {\
    QKeyEvent event = QKeyEvent(QEvent::KeyPress, _KEY_ID, Qt::NoModifier);\
    if (ScreenManager::instance()->curScrn())\
    {\
       qApp->sendEvent(QApplication::focusWidget(), &event);\
    }\
}\

AppFrame::AppFrame(QWidget *parent) :
    QWidget(parent,Qt::FramelessWindowHint)
{

}

AppFrame::~AppFrame()
{

}

QWidget *AppFrame::forwardTo(QString newScrnName, QWidget *parent)
{
    return ScreenManager::instance()->forwardTo(newScrnName, parent);
}

QWidget *AppFrame::goDefault(QString newScrnName, QWidget *parent)
{
    return ScreenManager::instance()->goDefault(newScrnName, parent);
}

QWidget *AppFrame::back()
{
    return  ScreenManager::instance()->back();
}

void AppFrame::onFuncKeyPressed(int keyID)
{
    switch (keyID) {
    case KeyID_0:
    {
    }
        break;
    case KeyID_1:
    {
    }
        break;
    default:
        break;
    }
}

void AppFrame::onKeyBoardPressed(int keyID)
{
    Q_UNUSED(keyID);
}

void AppFrame::onPageKeyPressed(int keyID)
{
    switch (keyID) {
    case KeyID_Confirm:
    {
    }
        break;
    default:
        break;
    }
}
