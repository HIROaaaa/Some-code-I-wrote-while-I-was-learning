#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>
#include<QDebug>
#include<QIcon>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    srand(time(0));
    // QPushButton* button =new QPushButton(this);
    // button->setText("按钮");
    // button->setEnabled(true);
    //connect(button,&QPushButton::clicked,this,&Widget::handle);

    // QIcon icon("d:/title_base2.png");
    // this->setWindowIcon(icon);
    QIcon icon(":/title_base2.png");
    this->setWindowIcon(icon);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handle()
{
    qDebug()<<"handle";
}

void Widget::on_pushButton_clicked()
{
     qDebug()<<"执行了槽函数";
}

void Widget::on_pushButton_enable_clicked()
{
    bool enable=ui->pushButton->isEnabled();
    if(enable)
    {
        ui->pushButton->setEnabled(false);
    }
    else
    {
         ui->pushButton->setEnabled(true);
    }
}


void Widget::on_up_clicked()
{
    QRect rect = ui->pushButton->geometry();
    qDebug()<<rect;
    // rect.setY(rect.y() - 5);
    // ui->pushButton->setGeometry(rect);
    ui->pushButton->setGeometry(rect.x(),rect.y()-5,rect.width(),rect.height());
}


void Widget::on_left_clicked()
{
    QRect rect = ui->pushButton->geometry();
    qDebug()<<rect;
    // rect.setX(rect.x()-5);
    // ui->pushButton->setGeometry(rect);
    ui->pushButton->setGeometry(rect.x()-5,rect.y(),rect.width(),rect.height());
}


void Widget::on_right_clicked()
{
    QRect rect = ui->pushButton->geometry();
    qDebug()<<rect;
    // rect.setX(rect.x()+5);
    // ui->pushButton->setGeometry(rect);
    ui->pushButton->setGeometry(rect.x()+5,rect.y(),rect.width(),rect.height());
}


void Widget::on_down_clicked()
{
    QRect rect = ui->pushButton->geometry();
    qDebug()<<rect;
    // rect.setY(rect.y() + 5);
    // ui->pushButton->setGeometry(rect);
    ui->pushButton->setGeometry(rect.x(),rect.y()+5,rect.width(),rect.height());
}


void Widget::on_pushButton_2_clicked()
{

}


void Widget::on_pushButton_2_pressed()
{
    int width= this->geometry().width();
    int height= this->geometry().height();
    int x=rand()%width;
    int y=rand()%height;
    ui->pushButton_2->move(x,y);
}


void Widget::on_pushButton_pressed()
{

}


void Widget::on_pushButton_3_clicked()
{
    float opacity=this->windowOpacity();
    if(opacity>=1.0)
    {
        return;
    }
    qDebug()<<opacity;
    opacity+=0.1;
    this->setWindowOpacity(opacity);
}


void Widget::on_pushButton_4_clicked()
{
    float opacity=this->windowOpacity();
    if(opacity<=0.0)
    {
        return;
    }
    qDebug()<<opacity;
    opacity-=0.1;
    this->setWindowOpacity(opacity);
}

