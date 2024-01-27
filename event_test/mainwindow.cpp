#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // this->setMouseTracking(true);

    MyLabel* label = new MyLabel(this);
    //label->setMouseTracking(true);
    label->resize(this->width(), this->height());
    //label->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    int button = ev->key();
    QString str = "";
    if(button & Qt::Key_A)
    {
        str += "A;";
    }
    if(button & Qt::Key_W)
    {
        str += "W;";
    }
    if(button & Qt::Key_S)
    {
        str += "S;";
    }
    if(button & Qt::Key_D)
    {
        str += "D";
    }
    str += "ppp";
    qDebug() << "按键";
    //this->setText(str);

}


