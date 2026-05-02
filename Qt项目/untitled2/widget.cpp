#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QLabel* label =new QLabel(this);
    label->setText("这是一段文本");

    //先创建一个字体对象
    QFont font("仿宋");
    font.setPixelSize(30);
    font.setBold(true);
    font.setItalic(true);
    font.setUnderline(true);
    font.setStrikeOut(true);
    label->setFont(font);


    ui->pushButtonNo->setToolTip("否");
    ui->pushButtonNo->setToolTipDuration(10000);
    ui->pushButtonYes->setToolTip("是");
    ui->pushButtonYes->setToolTipDuration(10000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_light_clicked()
{
    this->setStyleSheet("background-color:grb(240,240,240);");
    ui->plainTextEdit->setStyleSheet("background-color:white,color:black;");
    ui->pushButton_light->setStyleSheet("color:black;");
    ui->pushButton_dark->setStyleSheet("color:black;");
}


void Widget::on_pushButton_dark_clicked()
{
    this->setStyleSheet("background-color:rgb(30,30,30);");
    ui->plainTextEdit->setStyleSheet("background-color:black,color:white;");
    ui->pushButton_light->setStyleSheet("color:white;");
    ui->pushButton_dark->setStyleSheet("color:white;");
}

