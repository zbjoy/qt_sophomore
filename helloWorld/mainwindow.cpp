#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(800, 600);
    QPushButton* btn = new QPushButton("关闭", this);
    connect(btn, &QPushButton::clicked, this, &MainWindow::close);
}

MainWindow::~MainWindow() {}
