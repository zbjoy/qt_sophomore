#include "menuscene.h"
#include <QMenuBar>
#include <QSound>

MenuScene::MenuScene(QWidget *parent)
    : MainWindow{parent}
{
    btnBack = new MyPushButton(this);
    btnBack->setPixmap(":/Image/res/BackButton.png", ":/Image/res/BackButtonSelected.png");
    btnBack->resize(72, 32);
    btnBack->move(this->width() - btnBack->width(), this->height() - btnBack->height());
    connect(btnBack, &MyPushButton::clicked, [=](){
        emit btnBackClicked();
    });

    int xOffset = 25;
    int yOffset = 130;

    int colWidth = 70;
    int rowHeight = 70;

    for(int i = 0; i < 20; ++i)
    {
        MyPushButton* btn = new MyPushButton(this);
        btn->resize(57, 57);
        btn->setText(QString::number(i+1));
        int row = i / 4;
        int col = i % 4;
        btn->move(xOffset + col * colWidth, yOffset + row * rowHeight);
        btn->setPixmap(":/Image/res/LevelIcon.png");



        connect(btn, &MyPushButton::clicked, [=](){
            QSound::play(":/Music/res/TapButtonSound.wav");
            playScene = new PlayScene(i + 1);
            playScene->show();
            playScene->move(this->pos());
            this->hide();
            playScene->setAttribute(Qt::WA_DeleteOnClose);

            connect(playScene, &PlayScene::goNext, [=](int level)
                    {
                        playScene->setLevel(level);
                    });



            connect(playScene, &PlayScene::btnBackClicked, [=](){
                this->show();
                this->move(playScene->pos());
                playScene->close();

            });
        });


    }
}

void MenuScene::setBtnEnabled(bool able)
{

    btnBack->setEnabled(able);

}

void MenuScene::btnZoom(bool down)
{
    if(down)
    {
        btnBack->zoomDown();
        return;
    }

    btnBack->zoomUp();
}

MenuScene::~MenuScene()
{
    delete btnBack;
}

void MenuScene::paintEvent(QPaintEvent *event)
{
    // //绘制背景图片
    // QPainter painter(this);
    // //搬动画家到菜单栏下面
    // painter.translate(0,this->menuBar()->height());
    // //画背景图
    // QPixmap pix(":/Image/res/OtherSceneBg.png");
    // painter.drawPixmap(0,0,this->width(),this->height(),pix);
    // //painter.drawPixmap();
    // //绘制logo
    // pix.load(":/Image/res/Title.png");
    // painter.drawPixmap(0,0,pix);
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Image/res/OtherSceneBg.png");
    // painter.drawPixmap(this->menuBar()->width(), this->menuBar()->height(), this->width() - this->menuBar()->width(), this->height() - this->menuBar()->height(), pix);
    painter.drawPixmap(0 , this->menuBar()->height(), this->width(), this->height() - this->menuBar()->height(), pix);
    pix.load(":/Image/res/Title.png");
    painter.drawPixmap(0,this->menuBar()->height(),pix);
}
