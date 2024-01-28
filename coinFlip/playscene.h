#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QWidget>
#include <QPainter>
#include <QLabel>
#include <QPushButton>
#include "mainwindow.h"
#include "mypushbutton.h"
#include "coinpushbutton.h"

class PlayScene : public MainWindow
{
    Q_OBJECT
public:
    PlayScene(int level, QWidget *parent = nullptr);

    void setLevel(int level);

protected:
    void paintEvent(QPaintEvent *event);

private:
    MyPushButton* btnBack;
    QLabel* levelLabel;
    QLabel* winLabel;
    coinPushButton* coinBtn[4][4];

    void flip(int row, int col);

    void isWin();

    bool hasWin;

    int mLevel;
signals:
    void btnBackClicked();

    void goNext(int goLevel);
};

#endif // PLAYSCENE_H
