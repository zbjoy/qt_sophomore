#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextCodec>
#include <QDebug>
#include <QFileInfo>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFileInfo info;
    info.setFile("E:\\code\\qt_sophomore\\qFile_test");
    qDebug() << info.fileName();
    qDebug() << info.created().toString("yyyy-M-dd");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "打开一个Txt", "E:\\code\\qt_sophomore\\qFile_test", "TXT (*.txt)");
    ui->lineEdit->setText(fileName);

    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QByteArray array = file.readAll();
    QTextCodec* codec = QTextCodec::codecForName("gbk");
    QString text = codec->toUnicode(array);
    //QString text = QString(array);

    ui->plainTextEdit->setPlainText(text);
}

