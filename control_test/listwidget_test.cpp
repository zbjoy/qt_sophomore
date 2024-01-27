#include "listwidget_test.h"
#include "ui_listwidget_test.h"
#include <QPushButton>
#include <QListWidget>
#include <QStringList>

listWidget_test::listWidget_test(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::listWidget_test)
{
    ui->setupUi(this);
    QListWidget* widget = new QListWidget(this);
    this->resize(800, 600);
    this->move(600, 200);
    widget->resize(this->width(), this->height());

    QPushButton* btn = new QPushButton("关闭", widget);
    btn->move(600, 400);
    connect(btn, &QPushButton::clicked, [=](){
        emit closeListWidget();
    });

    QStringList list;
    list << "床前明月光"<<"疑似地上霜"<<"举头望明月"<<"低头思故乡";
    widget->addItems(list);
}

listWidget_test::~listWidget_test()
{
    delete ui;
}
