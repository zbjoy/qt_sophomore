#include "mypushbutton.h"

MyPushButton::MyPushButton(QWidget *parent)
    : QPushButton{parent}
{
    pixmapPath = "";
}

void MyPushButton::zoomDown()
{
    QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry", this);
    animation->setDuration(100);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));

    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void MyPushButton::zoomUp()
{
    QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry", this);
    animation->setDuration(100);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(this->x(), this->y() - 10, this->width(), this->height()));

    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void MyPushButton::setPixmap(QString str)
{
    pixmapPath = str;
}


void MyPushButton::paintEvent(QPaintEvent *)
{
    if(pixmapPath == "")
    {
        return;
    }
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(), this->height(), QPixmap(pixmapPath));
}
