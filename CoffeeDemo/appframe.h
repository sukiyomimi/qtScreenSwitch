#ifndef APPFRAME_H
#define APPFRAME_H

#include <QWidget>
#include "registerscreen.h"

class AppFrame : public QWidget
{

public:
    explicit AppFrame(QWidget *parent = nullptr);
    ~AppFrame();
    //迁移到下个界面
    QWidget* forwardTo(QString newScrnName, QWidget* parent = NULL);
    //进入到下个界面
    QWidget* goDefault(QString newScrnName, QWidget* parent = NULL);
    //返回
    QWidget* back();
    virtual void onFuncKeyPressed(int keyID);
    virtual void onKeyBoardPressed(int keyID);
    virtual void onPageKeyPressed(int keyID);

};

#endif // APPFRAME_H
