#include "playscene.h"
#include <QMenuBar>
#include <QTimer>
#include <QPropertyAnimation>
#include <QDebug>
#include <QLabel>
#include <QSound>

#include "dataconfig.h"


PlayScene::PlayScene(int level, QWidget *parent)
    : MainWindow{parent}
{
    hasWin = false;
    mLevel = level;
    btnBack = new MyPushButton(this);
    btnBack->setPixmap(":/Image/res/BackButton.png", ":/Image/res/BackButtonSelected.png");
    btnBack->resize(72, 32);
    btnBack->move(this->width() - btnBack->width(), this->height() - btnBack->height());
    connect(btnBack, &MyPushButton::clicked, [=](){
        emit btnBackClicked();
    });

    levelLabel = new QLabel;
    levelLabel->setParent(this);

    int xOffset = 57;
    int yOffset = 200;

    int colWidth = 50;
    int rowHeight = 50;

    dataConfig temp;
    QVector<QVector<int>> data = temp.mData[level];
    for(int i = 0; i < 16; ++i)
    {
        int row = i / 4;
        int col = i % 4;

        coinPushButton* coin = new coinPushButton(this);
        coinBtn[row][col] = coin;
        coin->resize(50, 50);
        coin->move(xOffset + colWidth * col, yOffset + rowHeight * row);

        //coin->setStatus(0);
        coin->setStatus(data[row][col]);

        connect(coin, &coinPushButton::clicked, [=](){

            // coin->setStatus(!coin->status());
            // coin->flip();
            this->flip(row, col);

        });
    }

}

void PlayScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Image/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, this->menuBar()->height(), this->width(), this->height() - this->menuBar()->height(), pix);

    pix.load(":/Image/res/Title.png");
    pix = pix.scaled(pix.width()/2,pix.height()/2);
    painter.drawPixmap(0,this->menuBar()->height(),pix);

    levelLabel->setText(QString("Level %1").arg(mLevel));
    levelLabel->setFont(QFont("华文新魏", 20));
    levelLabel->resize(150, 50);
    levelLabel->move(30, this->height() - levelLabel->height());

    // QWidget::paintEvent(event);
}

void PlayScene::flip(int row, int col)
{
    if(hasWin)
    {
        return;
    }
    QSound::play(":/Music/res/ConFlipSound.wav");
    coinBtn[row][col]->flip();

    QTimer::singleShot(240, [=](){
        if(row - 1 >= 0)
        {
            coinBtn[row - 1][col]->flip();
        }

        if(row + 1 <= 3)
        {
            coinBtn[row + 1][col]->flip();
        }

        if(col - 1 >= 0)
        {
            coinBtn[row][col - 1]->flip();
        }

        if(col + 1 <= 3)
        {
            coinBtn[row][col + 1]->flip();
        }

        isWin(); //QTimer::signalShot延时了放到外面就错了  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    });


}

void PlayScene::isWin()
{
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            if(!coinBtn[i][j]->status())
            {
                // qDebug() << "有银币";
                return;
            }
            // qDebug() << coinBtn[i][j]->status();
        }
    }

    // qDebug() << "胜利";
    QSound::play(":/Music/res/LevelWinSound.wav");
    hasWin = true;
    QLabel* winLabel = new QLabel(this);
    QPixmap pix;
    pix.load(":/Image/res/LevelCompletedDialogBg.png");
    winLabel->setPixmap(pix);
    winLabel->resize(pix.width(), pix.height());
    winLabel->move((this->width() - winLabel->width()) / 2, -winLabel->height());
    winLabel->show();


    QPropertyAnimation* animation = new QPropertyAnimation(winLabel, "geometry", this);

    animation->setDuration(1000);
    animation->setEasingCurve(QEasingCurve::OutBounce);

    animation->setStartValue(winLabel->geometry());
    animation->setEndValue(QRect(winLabel->x(), winLabel->y() + 170, winLabel->width(), winLabel->height()));

    animation->start(QAbstractAnimation::DeleteWhenStopped);

    QTimer::singleShot(1500, [=](){
        if(mLevel != 20)
        {
            emit goNext(mLevel+1);

        }

    });
}


















