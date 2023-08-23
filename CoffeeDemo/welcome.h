#ifndef WELCOME_H
#define WELCOME_H

#include "appframe.h"

namespace Ui {
class Welcome;
}

class Welcome : public AppFrame
{
    Q_OBJECT

public:
    explicit Welcome(QWidget *parent = 0);
    ~Welcome();

private:
    Ui::Welcome *ui;
};
REGISTER_SCREEN_CLASS(Welcome);
#endif // WELCOME_H
