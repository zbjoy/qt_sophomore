#ifndef WIDGET2_H
#define WIDGET2_H

#include <QWidget>

class Widget2 : public QWidget
{
    Q_OBJECT
public:
    explicit Widget2(QWidget *parent = nullptr);

signals:
    void openWidget1();
};

#endif // WIDGET2_H
