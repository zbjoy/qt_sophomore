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

    installEventFilter(this);

    label = new MyLabel(this);
    //label->setMouseTracking(true);
    label->resize(this->width(), this->height());
    //label->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {
        this->label->keyPressEvent(static_cast<QKeyEvent*>(event));
        return true;
    }
}




