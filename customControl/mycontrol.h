#ifndef MYCONTROL_H
#define MYCONTROL_H

#include <QWidget>

namespace Ui {
class myControl;
}

class myControl : public QWidget
{
    Q_OBJECT

public:
    explicit myControl(QWidget *parent = nullptr);

    int value();

    void setValue(int value);

    ~myControl();

private slots:
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::myControl *ui;
};

#endif // MYCONTROL_H
