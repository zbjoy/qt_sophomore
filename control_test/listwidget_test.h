#ifndef LISTWIDGET_TEST_H
#define LISTWIDGET_TEST_H

#include <QWidget>

namespace Ui {
class listWidget_test;
}

class listWidget_test : public QWidget
{
    Q_OBJECT

public:
    explicit listWidget_test(QWidget *parent = nullptr);
    ~listWidget_test();

private:
    Ui::listWidget_test *ui;

signals:
    void closeListWidget();
};

#endif // LISTWIDGET_TEST_H
