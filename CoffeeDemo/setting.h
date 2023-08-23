#ifndef SETTING_H
#define SETTING_H

#include "appframe.h"

namespace Ui {
class Setting;
}

class Setting : public AppFrame
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = 0);
    ~Setting();

private:
    Ui::Setting *ui;
};
REGISTER_SCREEN_CLASS(Setting);
#endif // SETTING_H
