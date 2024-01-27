#include "mylabel.h"
#include <QDebug>

MyLabel::MyLabel(QWidget *parent)
    : QLabel{parent}
{
    installEventFilter(this);
}


void MyLabel::mousePressEvent(QMouseEvent *event)
{
    // QString str = "";
    // Qt::MouseButtons status = event->buttons();
    // if(status & Qt::LeftButton)
    // {
    //     str += "LeftButton;";
    // }
    // if(status & Qt::RightButton)
    // {
    //     str += "RightButton;";
    // }
    // if(status & Qt::MidButton)
    // {
    //     str += "MidButton";
    // }

    // this->setText(QString("<h1><center>[%1](%2,%3)</center></h1>").arg(str).arg(event->x()).arg(event->y()));
}

void MyLabel::mouseMoveEvent(QMouseEvent *event)
{
    QString str = "";
    Qt::MouseButtons status = event->buttons();
    if(status & Qt::LeftButton)
    {
        str += "LeftButton;";
    }
    if(status & Qt::RightButton)
    {
        str += "RightButton;";
    }
    if(status & Qt::MidButton)
    {
        str += "MidButton";
    }

    this->setText(QString("<h1><center>[%1](%2,%3)</center></h1>").arg(str).arg(event->x()).arg(event->y()));
}

void MyLabel::keyPressEvent(QKeyEvent *ev)
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
    this->setText(str);
}

bool MyLabel::event(QEvent *e)
{
    if(e->type() == QEvent::MouseMove)
    {
        this->mouseMoveEvent(static_cast<QMouseEvent*>(e));
        return true;
    }

    return QLabel::event(e);
}

bool MyLabel::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::MouseMove)
    {
        return true;
    }
    return false;
}





















