#ifndef COINPUSHBUTTON_H
#define COINPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>

class coinPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit coinPushButton(QWidget *parent = nullptr);


    int status() const;
    void setStatus(int newStatus);


protected:
    void paintEvent(QPaintEvent *);

private:
    int mStatus;

signals:
};

#endif // COINPUSHBUTTON_H
