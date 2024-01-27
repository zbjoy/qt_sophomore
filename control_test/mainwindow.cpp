#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->resize(800, 600);
    this->move(600, 200);

    listWidget = new listWidget_test;//(this);
    treeWidget = new treeWidget_test;//(this);

    connect(listWidget, &listWidget_test::closeListWidget, [=](){
        listWidget->hide();
    });

    connect(treeWidget, &treeWidget_test::closeTreeWidget, [=](){
        treeWidget->hide();
    });

    QPushButton* btn_openListWidget = new QPushButton("listWidget", this);
    QPushButton* btn_openTreeWidget = new QPushButton("treeWidget", this);

    btn_openListWidget->move(200, 400);
    btn_openTreeWidget->move(400, 400);

    connect(btn_openListWidget, &QPushButton::clicked, [=](){
        listWidget->show();
    });

    connect(btn_openTreeWidget, &QPushButton::clicked, [=](){
        treeWidget->show();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
    delete listWidget;
    delete treeWidget;
}
