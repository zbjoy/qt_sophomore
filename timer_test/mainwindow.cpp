#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    ,timerId(0)
    ,timerId2(0)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(800, 600);
    QPushButton* btnStart = new QPushButton("start", this);
    QPushButton* btnStop = new QPushButton("Stop", this);
    btnStart->move(200, 200);
    btnStop->move(350, 200);
    connect(btnStart, &QPushButton::clicked, [=](){
        this->timerId = startTimer(1000);
    });

    connect(btnStop, &QPushButton::clicked, [=](){
        this->killTimer(this->timerId);
        this->timerId = 0;
    });

    QTimer* timer = new QTimer(this);
    lcdNumber = new QLCDNumber(this);
    lcdNumber->move(270, 300);
    lcdNumber->resize(191, 81);

    QPushButton* btnStart2 = new QPushButton("start", this);
    QPushButton* btnStop2 = new QPushButton("Stop", this);
    btnStart2->move(200, 400);
    btnStop2->move(350, 400);

    connect(timer, &QTimer::timeout, [=](){
        static int num = 0;
        this->lcdNumber->display(num++);
    });

    connect(btnStart2, &QPushButton::clicked, [=](){
        //this->timerId2 = startTimer(1000);
        timer->start(10);
    });

    connect(btnStop2, &QPushButton::clicked, [=](){
        //this->killTimer(this->timerId2);
        //this->timerId2 = 0;
        timer->stop();
    });



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == this->timerId)
    {
        static int num = 0;
        this->ui->lcdNumber->display(num++);
    }

    if(event->timerId() == this->timerId2)
    {
        static int num = 0;
        this->lcdNumber->display(num++);
    }

}
