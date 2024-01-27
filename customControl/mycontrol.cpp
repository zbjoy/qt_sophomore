#include "mycontrol.h"
#include "ui_mycontrol.h"

myControl::myControl(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::myControl)
{
    ui->setupUi(this);



    connect(ui->spinBox, static_cast<void (QSpinBox::*)(int)>(QSpinBox::valueChanged), [=](int value){
        ui->horizontalSlider->setValue(value);
    });
}

int myControl::value()
{
    return ui->spinBox->value();
}

void myControl::setValue(int value)
{
    // this->setValue(value);
    ui->spinBox->setValue(value);
}

myControl::~myControl()
{
    delete ui;
}

void myControl::on_horizontalSlider_valueChanged(int value)
{
    ui->spinBox->setValue(value);
}

