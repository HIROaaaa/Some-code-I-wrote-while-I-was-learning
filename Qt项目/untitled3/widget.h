#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;
    void handle();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_enable_clicked();

    void on_up_clicked();

    void on_left_clicked();

    void on_right_clicked();

    void on_down_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_pressed();

    void on_pushButton_2_pressed();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
