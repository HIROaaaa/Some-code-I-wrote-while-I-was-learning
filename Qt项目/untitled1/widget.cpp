#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // QPushButton* button=new QPushButton(this);
    // button->setText("按钮");
    // button->move(100,100);
    // connect(button,&QPushButton::clicked,this,&Widget::HandleClicked);


    //connect(ui->pushButton,&QPushButton::clicked,this,&);
    connect(this,&Widget::mySignal,this,&Widget::HandlMySignal);

}

Widget::~Widget()
{
    delete ui;
}

// void Widget::HandleClicked()
// {
//     this->setWindowTitle("按钮已经按下");
// }

void Widget::on_pushButton_clicked()
{
   emit mySignal("把标题设置为标题1","");//信号的参数可以比槽要多，但是反过来不行
}

void Widget::on_pushButton_2_clicked()
{
    emit mySignal("把标题设置为标题2","");
}

void Widget::HandlMySignal(const QString& text)
{
    this->setWindowTitle(text);
}



