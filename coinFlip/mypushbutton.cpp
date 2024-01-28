#include "mypushbutton.h"
#include <QDebug>

MyPushButton::MyPushButton(QWidget *parent)
    : QPushButton{parent}
{
    //pixmapPath = "";
    mStatus = Normal;
    normalImagePath = "";
    pressedImagePath = "";
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

void MyPushButton::setPixmap(QString str1, QString str2)
{
    // pixmapPath = str;
    normalImagePath = str1;
    if(str2 != "")
    {
        pressedImagePath = str2;
    }
}


void MyPushButton::paintEvent(QPaintEvent *)
{
    if(normalImagePath == "")
    {
        return;
    }
    QPainter painter(this);
    QPixmap pixmap;
    if(mStatus == Normal)
    {
        // painter.drawPixmap(0, 0, this->width(), this->height(), QPixmap(normalImagePath));
        pixmap.load(normalImagePath);
    }
    else if(mStatus == Pressed && pressedImagePath != "")
    {
        // painter.drawPixmap(0, 0, this->width(), this->height(), QPixmap(pressedImagePath));
        pixmap.load(pressedImagePath);
    }
    else
    {
        pixmap.load(normalImagePath);
    }
    painter.drawPixmap(0, 0, this->width(), this->height(), pixmap);
    painter.drawText(0, 0, this->width(), this->height(), Qt::AlignHCenter | Qt::AlignVCenter, this->text());
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    // if(e->button() == Qt::LeftButton)
    // {
    //     status = pressed;
    //     update();
    // }
    this->mStatus = Pressed;
    update();
    QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        mStatus = Normal;
        update();
    }
    QPushButton::mouseReleaseEvent(e);
}
