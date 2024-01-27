#include "mainwindow.h"
#include <QMenuBar>
#include <QFileDialog>
#include <QToolBar>
#include <QMessageBox>
#include <iostream>
#include <QDebug>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(800, 600);
    QMenuBar* menuBar = this->menuBar();
    QMenu* menuFile = menuBar->addMenu("文件");
    QMenu* menuEdit = menuBar->addMenu("编辑");
    QAction* actionOpen = menuFile->addAction("打开");
    QAction* actionClose = menuFile->addAction("关闭");

    menuFile->addSeparator();

    QMenu* menuRecent = menuFile->addMenu("最近打开的文件");


    connect(actionOpen, &QAction::triggered, [=](){
        QFileDialog::getOpenFileName(this, "打开文件", "E://code");
    });

    QAction* actionRecentFile = menuRecent->addAction("1.txt");//new QAction("1.txt");
    connect(actionRecentFile, &QAction::triggered, [=](){
        QFileDialog::getOpenFileName(this, "打开文件", "E://code");
    });


    QToolBar* toolBar = this->addToolBar("");
    toolBar->addAction(actionOpen);
    toolBar->setAllowedAreas(Qt::LeftToolBarArea);
    this->addToolBar(Qt::LeftToolBarArea, toolBar);
    toolBar->setFloatable(false);
    toolBar->setMovable(false);

    QAction* actionHaha = toolBar->addAction("彩蛋");
    connect(actionHaha, &QAction::triggered, [=](){
        if(QMessageBox::Yes == QMessageBox::question(this, "一个小问题", "Are you ok?"))
        {
            //std::cout << "那挺好" << std::endl;
            qDebug() << "那挺好";
        }
    });

    QStatusBar* statusBar = this->statusBar();
    QLabel* labelBegin = new QLabel("开始", this);
    QLabel* labelEnd = new QLabel("结束", this);
    statusBar->addWidget(labelBegin);
    statusBar->addPermanentWidget(labelEnd);

    QDockWidget* dockWidget = new QDockWidget("停靠部件", this);
    this->addDockWidget(Qt::BottomDockWidgetArea, dockWidget);

    dockWidget->setFloating(false);

    QTextEdit* edit = new QTextEdit(this);
    this->setCentralWidget(edit);
}

MainWindow::~MainWindow() {}
