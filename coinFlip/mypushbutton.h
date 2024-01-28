#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QPropertyAnimation>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);

    void zoomDown();
    void zoomUp();

    void setPixmap(QString str);

protected:
    void paintEvent(QPaintEvent *);


private:
    QString pixmapPath;

signals:
};

#endif // MYPUSHBUTTON_H
