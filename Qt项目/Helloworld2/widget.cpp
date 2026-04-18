#include "widget.h"
#include "ui_widget.h"
#include<QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //这样更好
    QLabel* label=new QLabel(this);
    //QLabel label;
    label->setText(QString("hello world"));
    //不显式使用也可以
    //QSstring会包含在很多头文件里，很多时候不包含头文件也可以
    label->setText("hello world");
}

Widget::~Widget()
{
    delete ui;
}
