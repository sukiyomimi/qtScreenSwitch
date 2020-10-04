#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "appframe.h"
#include "screenmanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget* m_scrn = ScreenManager::instance()->goDefault("Form", ui->scrn);
    m_scrn->resize(ui->scrn->size());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_keyID_0_clicked()
{

}

void MainWindow::on_pushButton_keyID_1_clicked()
{

}

void MainWindow::on_pushButton_keyID_Confirm_clicked()
{

}
