#include "mypushbutton.h"

MyPushButton::MyPushButton(QWidget *parent)
    : QPushButton{parent}
{
    this->sta = Nomaled;
}

void MyPushButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    if(this->sta == Nomaled)
    {
        brush.setColor(Qt::green);
    }
    else if(this->sta == Pressed)
    {
        brush.setColor(Qt::blue);
    }
    else
    {
        brush.setColor(Qt::red);
    }
    painter.setBrush(brush);
    painter.drawEllipse(0, 0, this->width() - 1, this->height() - 1);
    painter.drawText(0, 0, this->width(), this->height(),Qt::AlignHCenter | Qt::AlignVCenter , "按键");
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
        sta = Pressed;
    update();

    QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
        sta = Entered;
    update();
    QPushButton::mouseReleaseEvent(e);
}

void MyPushButton::enterEvent(QEvent *event)
{
    sta = Entered;
    update();
    // return QPushButton::paintEvent(e);
}

void MyPushButton::leaveEvent(QEvent *event)
{
    sta = Nomaled;
    update();
    // return QPushButton::paintEvent(e);
}





















