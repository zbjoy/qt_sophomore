#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QWidget>
#include <QPainter>
#include <QLabel>
#include "mainwindow.h"
#include "mypushbutton.h"
#include "coinpushbutton.h"

class PlayScene : public MainWindow
{
    Q_OBJECT
public:
    PlayScene(int level, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);

private:
    MyPushButton* btnBack;
    QLabel* levelLabel;

    int mLevel;
signals:
    void btnBackClicked();
};

#endif // PLAYSCENE_H
