#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QPropertyAnimation>
#include <QMouseEvent>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);

    void zoomDown();
    void zoomUp();

    void setPixmap(QString str1, QString str2 = "");

protected:
    void paintEvent(QPaintEvent *);

    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent* e);


private:

    enum buttonStatus
    {
        Normal,
        Pressed
    };

    buttonStatus mStatus;
    // QString pixmapPath;
    QString normalImagePath;
    QString pressedImagePath;

signals:
};

#endif // MYPUSHBUTTON_H
