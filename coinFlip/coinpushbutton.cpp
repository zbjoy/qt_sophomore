#include "coinpushbutton.h"

coinPushButton::coinPushButton(QWidget *parent)
    : QPushButton{parent}
{
    mStatus = 0;
    mFrame = 0;
    timerId = 0;

    // if(timerId == 0)
    // {
    //     if(mStatus == 1)//金币
    //     {
    //         this->setIcon(QIcon(":/Image/res/Coin0001.png"));
    //     }
    //     else
    //     {
    //         this->setIcon(QIcon(":/Image/res/Coin0008.png"));
    //     }
    // }

    connect(&timer, &QTimer::timeout, [=](){
        if(mStatus == 1)
        {
            mFrame--;
        }
        else
        {
            mFrame++;
        }

        this->setIcon(QIcon(QString(":/Image/res/Coin000%1.png").arg(mFrame)));

        if(mFrame == 1 || mFrame == 8)
        {
            //killTimer(this->timerId);
            //timerId = 0;
            timer.stop();
        }

    });

    this->setStyleSheet("QPushButton{border:0px;}");
}

int coinPushButton::status() const
{
    return mStatus;
}

void coinPushButton::setStatus(int newStatus)
{
    mStatus = newStatus;
    // if(mStatus == 1 && timerId == 0)//金币
    // {
    //     this->setIcon(QIcon(":/Image/res/Coin0001.png"));
    // }
    // else
    // {
    //     this->setIcon(QIcon(":/Image/res/Coin0008.png"));
    // }

    // if(timerId == 0)
    // {
        if(mStatus == 1)//金币
        {
            this->setIcon(QIcon(":/Image/res/Coin0001.png"));
        }
        else
        {
            this->setIcon(QIcon(":/Image/res/Coin0008.png"));
        }
    // }

    this->setIconSize(this->size());

    update();
}

void coinPushButton::flip()
{
    if(mStatus == 1)
    {
        mFrame = 1;
    }
    else
    {
        mFrame = 8;
    }
    mStatus = !mStatus;
    //timerId = startTimer(30);

    timer.start(30);
}

void coinPushButton::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Image/res/BoardNode.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
    // if(mStatus == 1 && timerId == 0)//金币
    // {
    //     this->setIcon(QIcon(":/Image/res/Coin0001.png"));
    // }
    // else
    // {
    //     this->setIcon(QIcon(":/Image/res/Coin0008.png"));
    // }

    // if(timerId == 0)
    // {
    //     if(mStatus == 1)//金币
    //     {
    //         this->setIcon(QIcon(":/Image/res/Coin0001.png"));
    //     }
    //     else
    //     {
    //         this->setIcon(QIcon(":/Image/res/Coin0008.png"));
    //     }
    // }


    this->setIconSize(this->size());
    //this->setIcon();
    QPushButton::paintEvent(e);//setIcon是父类QPushButton中的,交给QPushButton去处理
}

void coinPushButton::timerEvent(QTimerEvent *e)
{
    if(mStatus == 1)
    {
        mFrame--;
    }
    else
    {
        mFrame++;
    }

    this->setIcon(QIcon(QString(":/Image/res/Coin000%1.png").arg(mFrame)));

    if(mFrame == 1 || mFrame == 8)
    {
        killTimer(this->timerId);
        timerId = 0;
    }
    // update();

    QPushButton::timerEvent(e);
}

























