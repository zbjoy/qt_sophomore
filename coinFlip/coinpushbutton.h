#ifndef COINPUSHBUTTON_H
#define COINPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QTimerEvent>
#include <QTimer>

class coinPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit coinPushButton(QWidget *parent = nullptr);


    int status() const;
    void setStatus(int newStatus);

    void flip();



protected:
    void paintEvent(QPaintEvent *);

    void timerEvent(QTimerEvent *e);

private:

    QTimer timer;
    int mStatus;

    int timerId;

    int mFrame;

signals:
};

#endif // COINPUSHBUTTON_H
