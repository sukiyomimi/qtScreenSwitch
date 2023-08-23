#ifndef FORM_H
#define FORM_H

#include "appframe.h"

namespace Ui {
class Form;
}

class Form : public AppFrame
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private:
    Ui::Form *ui;
};
REGISTER_SCREEN_CLASS(Form);
#endif // FORM_H
