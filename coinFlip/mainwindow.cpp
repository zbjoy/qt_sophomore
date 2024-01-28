#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("翻金币");
    this->setWindowIcon(QIcon("://Image//res//Coin0001.png"));
    this->resize(320, 588);
}

MainWindow::~MainWindow()
{
    delete ui;
}
