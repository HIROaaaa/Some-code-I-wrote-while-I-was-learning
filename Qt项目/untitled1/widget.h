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
    void HandleClicked();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

signals:
    void mySignal(const QString& text,const QString& text2);
public:
    void HandlMySignal(const QString& text);
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
