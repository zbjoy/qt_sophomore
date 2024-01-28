#include "playscene.h"
#include <QMenuBar>


PlayScene::PlayScene(int level, QWidget *parent)
    : MainWindow{parent}
{
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
    for(int i = 0; i < 16; ++i)
    {
        int row = i / 4;
        int col = i % 4;

        coinPushButton* coin = new coinPushButton(this);

        coin->resize(50, 50);
        coin->move(xOffset + colWidth * col, yOffset + rowHeight * row);

        coin->setStatus(0);


        connect(coin, &coinPushButton::clicked, [=](){
            coin->setStatus(!coin->status());
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
}
