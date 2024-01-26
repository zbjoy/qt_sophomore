#ifndef WIDGET1_H
#define WIDGET1_H

#include <QWidget>
#include "widget2.h"

class Widget1 : public QWidget
{
    Q_OBJECT

public:
    Widget1(QWidget *parent = nullptr);
    ~Widget1();
private:
    Widget2* widget2;
};
#endif // WIDGET1_H
