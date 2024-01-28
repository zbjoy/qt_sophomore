#ifndef MENUSCENE_H
#define MENUSCENE_H

#include <QWidget>
#include "mainwindow.h"
#include <QPainter>
#include "playscene.h"

#include "mypushbutton.h"

class MenuScene : public MainWindow
{
    Q_OBJECT
public:
    explicit MenuScene(QWidget *parent = nullptr);

    void setBtnEnabled(bool);

    void btnZoom(bool); //down(true)  up(false)

    ~MenuScene();


protected:

    void paintEvent(QPaintEvent *event);

private:
    MyPushButton* btnBack;
    PlayScene* playScene;
signals:
    void btnBackClicked();
};

#endif // MENUSCENE_H
