#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void onloadWelcome();
    void onloadMainScreen();
private slots:
    void on_pushButton_keyID_Confirm_clicked();

    void on_pushButton_keyID_Setting_clicked();

    void on_pushButton_keyID_Cancel_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
