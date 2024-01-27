#ifndef TREEWIDGET_TEST_H
#define TREEWIDGET_TEST_H

#include <QWidget>

namespace Ui {
class treeWidget_test;
}

class treeWidget_test : public QWidget
{
    Q_OBJECT

public:
    explicit treeWidget_test(QWidget *parent = nullptr);
    ~treeWidget_test();

private:
    Ui::treeWidget_test *ui;

signals:
    void closeTreeWidget();
};

#endif // TREEWIDGET_TEST_H
