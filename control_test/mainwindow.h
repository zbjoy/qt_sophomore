#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "treewidget_test.h"
#include "listwidget_test.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    listWidget_test* listWidget;
    treeWidget_test* treeWidget;
};
#endif // MAINWINDOW_H
