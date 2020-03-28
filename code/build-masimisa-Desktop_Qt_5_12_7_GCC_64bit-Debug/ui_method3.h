/********************************************************************************
** Form generated from reading UI file 'method3.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_METHOD3_H
#define UI_METHOD3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Method3
{
public:
    QLabel *label;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_8;
    QLabel *label_6;
    QPushButton *pushButton_2;
    QLabel *label_7;
    QLabel *label_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Method3)
    {
        if (Method3->objectName().isEmpty())
            Method3->setObjectName(QString::fromUtf8("Method3"));
        Method3->resize(949, 644);
        label = new QLabel(Method3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 20, 711, 34));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier 10 Pitch"));
        font.setPointSize(14);
        label->setFont(font);
        label_3 = new QLabel(Method3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 430, 171, 34));
        label_3->setFont(font);
        label_5 = new QLabel(Method3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(120, 70, 303, 341));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_8 = new QLabel(Method3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(500, 70, 303, 341));
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_6 = new QLabel(Method3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(500, 70, 303, 341));
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_2 = new QPushButton(Method3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(780, 420, 141, 31));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 157, 241);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius: 15px;"));
        label_7 = new QLabel(Method3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(120, 70, 303, 341));
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_2 = new QLabel(Method3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 480, 741, 141));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_3 = new QPushButton(Method3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(620, 420, 141, 31));
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 157, 241);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius: 15px;"));

        retranslateUi(Method3);

        QMetaObject::connectSlotsByName(Method3);
    } // setupUi

    void retranslateUi(QDialog *Method3)
    {
        Method3->setWindowTitle(QApplication::translate("Method3", "Dialog", nullptr));
        label->setText(QApplication::translate("Method3", "<html><head/><body><h2 style=\" margin-top:16px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:x-large; font-weight:600;\">M\303\251thode 3 : Fonctions Predefinies - Opencv</span></h2></body></html>", nullptr));
        label_3->setText(QApplication::translate("Method3", "<html><head/><body><h2 style=\" margin-top:16px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:x-large; font-weight:600;\">Resultats:</span></h2></body></html>", nullptr));
        label_5->setText(QString());
        label_8->setText(QString());
        label_6->setText(QString());
        pushButton_2->setText(QApplication::translate("Method3", ">", nullptr));
        label_7->setText(QString());
        label_2->setText(QString());
        pushButton_3->setText(QApplication::translate("Method3", "<", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Method3: public Ui_Method3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_METHOD3_H
