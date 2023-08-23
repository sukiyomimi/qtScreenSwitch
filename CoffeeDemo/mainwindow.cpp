#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "appframe.h"
#include "screenmanager.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setProperty("canMove", true);
    QTimer::singleShot(50, this, SLOT(onloadWelcome()));

    QTimer::singleShot(5000, this, SLOT(onloadMainScreen()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onloadWelcome()
{
    QWidget* m_scrn = ScreenManager::instance()->goDefault("Welcome", ui->scrn);
    m_scrn->resize(ui->scrn->size());
}

void MainWindow::onloadMainScreen()
{
    QWidget* m_scrn = ScreenManager::instance()->goDefault("Form", ui->scrn);
    m_scrn->resize(ui->scrn->size());
}

void MainWindow::on_pushButton_keyID_Confirm_clicked()
{

}

void MainWindow::on_pushButton_keyID_Setting_clicked()
{
    QWidget* m_scrn = ScreenManager::instance()->forwardTo("Setting", ui->scrn);
    m_scrn->resize(ui->scrn->size());
}

void MainWindow::on_pushButton_keyID_Cancel_clicked()
{
    QWidget* m_scrn = ScreenManager::instance()->back();
    m_scrn->resize(ui->scrn->size());
}
