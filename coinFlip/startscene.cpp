#include "startscene.h"
#include <QTimer>

StartScene::StartScene(QWidget *parent)
    : MainWindow{parent}
{
    btnStart = new MyPushButton(this);
    menuScene = new MenuScene;
    btnStart->resize(114, 114);
    btnStart->move((this->width()- btnStart->width()) / 2, this->height() / 4 * 3 - btnStart->height() / 2);
    btnStart->setPixmap(":/Image/res/MenuSceneStartButton.png");

    connect(btnStart, &MyPushButton::clicked, [=](){
        btnStart->setEnabled(false);
        btnStart->zoomDown();
        QTimer::singleShot(150, [=](){
            btnStart->zoomUp();
        });

        QTimer::singleShot(300, [=](){
            btnStart->setEnabled(true);
            this->hide();
            menuScene->show();
        });
    });

    connect(menuScene, &MenuScene::btnBackClicked, [=](){
        menuScene->setBtnEnabled(false);
        menuScene->btnZoom(true);
        QTimer::singleShot(150, [=](){
            menuScene->btnZoom(false);
        });

        QTimer::singleShot(300, [=](){
            menuScene->setBtnEnabled(true);
            // menuScene->btnZoom(false);
            menuScene->hide();
            this->show();
        });
    });
}

StartScene::~StartScene()
{
    // delete btnStart;
    // btnStart = NULL;
    delete menuScene;
    menuScene = NULL;
}

void StartScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(), this->height(), QPixmap(":/Image/res/MenuSceneBg.png"));

}
