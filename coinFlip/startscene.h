#ifndef STARTSCENE_H
#define STARTSCENE_H

#include <QMainWindow>
#include <QPainter>
#include "mainwindow.h"
#include <QPushButton>

#include "mypushbutton.h"
#include "menuscene.h"

class StartScene : public MainWindow
{
    Q_OBJECT
public:
    explicit StartScene(QWidget *parent = nullptr);

    ~StartScene();

signals:


protected:
    void paintEvent(QPaintEvent *event);


private:
    MyPushButton* btnStart;

    MenuScene* menuScene;
};

#endif // STARTSCENE_H
