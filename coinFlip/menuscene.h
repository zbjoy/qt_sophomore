#ifndef MENUSCENE_H
#define MENUSCENE_H

#include <QWidget>
#include "mainwindow.h"

#include "mypushbutton.h"

class MenuScene : public MainWindow
{
    Q_OBJECT
public:
    explicit MenuScene(QWidget *parent = nullptr);

    void setBtnEnabled(bool);

    void btnZoom(bool); //down(true)  up(false)

    ~MenuScene();

private:
    MyPushButton* btnBack;
signals:
    void btnBackClicked();
};

#endif // MENUSCENE_H
