#include "menuscene.h"

MenuScene::MenuScene(QWidget *parent)
    : MainWindow{parent}
{
    btnBack = new MyPushButton(this);
    btnBack->setPixmap(":/Image/res/BackButton.png");
    btnBack->move(this->width() - btnBack->width(), this->height() - btnBack->height());
    connect(btnBack, &MyPushButton::clicked, [=](){
        emit btnBackClicked();
    });
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
