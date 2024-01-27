#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QKeyEvent>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *ev);

    void keyPressEvent(QKeyEvent *ev);

    bool event(QEvent *e);

    bool eventFilter(QObject *watched, QEvent *event);

signals:
};

#endif // MYLABEL_H
