#include "widget1.h"
#include <QPushButton>

Widget1::Widget1(QWidget *parent)
    : QWidget(parent)
{
    this->resize(800, 600);
    this->move(600, 300);
    QPushButton* btn1 = new QPushButton("窗口1", this);
    widget2 = new Widget2;
    connect(btn1, &QPushButton::clicked, [=](){
        this->hide();
        widget2->show();
    });

    connect(widget2, &Widget2::openWidget1, [=](){
        widget2->hide();
        this->show();
    });
}

Widget1::~Widget1() {}
