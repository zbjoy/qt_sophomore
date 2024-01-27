#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton* btn1 = new QPushButton("设置值为中间", this);
    QPushButton* btn2 = new QPushButton("获得当前值", this);

    btn1->move(200, 400);
    btn2->move(400, 400);

    connect(btn1, &QPushButton::clicked, [=](){
        ui->widget->setValue(50);//ui->widget->maximumHeight() / 2);
    });

    connect(btn2, &QPushButton::clicked, [=](){
        QMessageBox::information(this, QString("现在的值"), QString::number(ui->widget->value()));
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::on_pushButton_clicked()
// {
//     QMessageBox::information(this, QString("现在的值"), QString::number(ui->widget->value()));
// }


// void MainWindow::on_pushButton_2_clicked()
// {
//     ui->widget->setValue(50);
// }

