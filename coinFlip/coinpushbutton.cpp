#include "coinpushbutton.h"

coinPushButton::coinPushButton(QWidget *parent)
    : QPushButton{parent}
{
    mStatus = 0;

    this->setStyleSheet("QPushButton{border:0px;}");
}

int coinPushButton::status() const
{
    return mStatus;
}

void coinPushButton::setStatus(int newStatus)
{
    mStatus = newStatus;
    update();
}

void coinPushButton::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Image/res/BoardNode.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
    if(mStatus == 1)//金币
    {
        this->setIcon(QIcon(":/Image/res/Coin0001.png"));
    }
    else
    {
        this->setIcon(QIcon(":/Image/res/Coin0008.png"));
    }

    this->setIconSize(this->size());
    //this->setIcon();
    QPushButton::paintEvent(e);//setIcon是父类QPushButton中的,交给QPushButton去处理
}
