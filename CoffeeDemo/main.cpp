#include "mainwindow.h"
#include <QApplication>
#include "appinit.h"
#include "quiwidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setFont(QFont("Microsoft Yahei", 9));
    QUIWidget::setCode();
    AppInit::Instance()->start();
    QUIWidget qui;
    MainWindow w;
    qui.setMainWidget(&w);
    //设置标题文本居中
    qui.setAlignment(Qt::AlignCenter);

    //设置窗体可拖动大小
    qui.setSizeGripEnabled(true);
    qui.show();
    return a.exec();
}
