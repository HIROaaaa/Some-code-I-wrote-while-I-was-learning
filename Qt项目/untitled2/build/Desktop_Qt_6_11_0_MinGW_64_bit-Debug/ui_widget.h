/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QPushButton *pushButtonYes;
    QPushButton *pushButtonNo;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton_light;
    QPushButton *pushButton_dark;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1970, 1031);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(370, 360, 241, 91));
        QFont font;
        font.setFamilies({QString::fromUtf8("System")});
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(true);
        font.setUnderline(true);
        label->setFont(font);
        pushButtonYes = new QPushButton(Widget);
        pushButtonYes->setObjectName("pushButtonYes");
        pushButtonYes->setGeometry(QRect(210, 120, 131, 81));
        pushButtonNo = new QPushButton(Widget);
        pushButtonNo->setObjectName("pushButtonNo");
        pushButtonNo->setGeometry(QRect(820, 110, 181, 81));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(240, 320, 581, 71));
        lineEdit_2 = new QLineEdit(Widget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(240, 510, 581, 71));
        lineEdit_3 = new QLineEdit(Widget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(240, 410, 581, 71));
        lineEdit_3->setFocusPolicy(Qt::FocusPolicy::TabFocus);
        lineEdit_4 = new QLineEdit(Widget);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(240, 610, 581, 71));
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(850, 370, 221, 71));
        label_2->setStyleSheet(QString::fromUtf8("font-family: \"Microsoft YaHei UI\";\n"
"font-size: 30px;\n"
"color:green;\n"
"font-style:italic;"));
        plainTextEdit = new QPlainTextEdit(Widget);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(1130, 160, 771, 511));
        pushButton_light = new QPushButton(Widget);
        pushButton_light->setObjectName("pushButton_light");
        pushButton_light->setGeometry(QRect(1240, 700, 100, 29));
        pushButton_dark = new QPushButton(Widget);
        pushButton_dark->setObjectName("pushButton_dark");
        pushButton_dark->setGeometry(QRect(1580, 700, 100, 29));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QString());
        pushButtonYes->setText(QCoreApplication::translate("Widget", "YES", nullptr));
        pushButtonNo->setText(QCoreApplication::translate("Widget", "NO", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\345\227\241\345\227\241\345\227\241\345\227\241\345\227\241\345\227\241", nullptr));
        pushButton_light->setText(QCoreApplication::translate("Widget", "\346\227\245\351\227\264\346\250\241\345\274\217", nullptr));
        pushButton_dark->setText(QCoreApplication::translate("Widget", "\345\244\234\351\227\264\346\250\241\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
