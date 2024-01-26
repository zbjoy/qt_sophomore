#include "widget2.h"
#include <QPushButton>

Widget2::Widget2(QWidget *parent)
    : QWidget{parent}
{
    this->resize(800, 600);
    this->move(600, 300);
    QPushButton* btn2 = new QPushButton("窗口2", this);
    connect(btn2, &QPushButton::clicked, [=](){
        emit openWidget1();
    });
}
