/********************************************************************************
** Form generated from reading UI file 'method2.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_METHOD2_H
#define UI_METHOD2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Method2
{
public:
    QLabel *label_5;
    QLabel *label_8;
    QLabel *label_6;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_3;
    QLabel *label_4;
    QLabel *label_7;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Method2)
    {
        if (Method2->objectName().isEmpty())
            Method2->setObjectName(QString::fromUtf8("Method2"));
        Method2->resize(942, 644);
        label_5 = new QLabel(Method2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(120, 60, 303, 341));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_8 = new QLabel(Method2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(500, 60, 303, 341));
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_6 = new QLabel(Method2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(500, 60, 303, 341));
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label = new QLabel(Method2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 10, 551, 34));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier 10 Pitch"));
        font.setPointSize(14);
        label->setFont(font);
        label_2 = new QLabel(Method2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 470, 741, 141));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_3 = new QLabel(Method2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 420, 171, 34));
        label_3->setFont(font);
        pushButton_3 = new QPushButton(Method2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(620, 410, 141, 31));
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 157, 241);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius: 15px;"));
        label_4 = new QLabel(Method2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 470, 741, 141));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_7 = new QLabel(Method2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(120, 60, 303, 341));
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_2 = new QPushButton(Method2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(780, 410, 141, 31));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 157, 241);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius: 15px;"));
        label_6->raise();
        label_5->raise();
        label_8->raise();
        label->raise();
        label_3->raise();
        pushButton_3->raise();
        label_4->raise();
        label_7->raise();
        pushButton_2->raise();
        label_2->raise();

        retranslateUi(Method2);

        QMetaObject::connectSlotsByName(Method2);
    } // setupUi

    void retranslateUi(QDialog *Method2)
    {
        Method2->setWindowTitle(QApplication::translate("Method2", "Dialog", nullptr));
        label_5->setText(QString());
        label_8->setText(QString());
        label_6->setText(QString());
        label->setText(QApplication::translate("Method2", "<html><head/><body><h2 style=\" margin-top:16px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:x-large; font-weight:600;\">M\303\251thode 2 : Balayage Horizontale</span></h2></body></html>", nullptr));
        label_2->setText(QString());
        label_3->setText(QApplication::translate("Method2", "<html><head/><body><h2 style=\" margin-top:16px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:x-large; font-weight:600;\">Resultats:</span></h2></body></html>", nullptr));
        pushButton_3->setText(QApplication::translate("Method2", "Sans Preprocessing", nullptr));
        label_4->setText(QString());
        label_7->setText(QString());
        pushButton_2->setText(QApplication::translate("Method2", "Avec Preprocessing", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Method2: public Ui_Method2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_METHOD2_H
