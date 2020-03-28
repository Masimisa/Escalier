/********************************************************************************
** Form generated from reading UI file 'secondwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDWINDOW_H
#define UI_SECONDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SecondWindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QPushButton *pushButton_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_6;

    void setupUi(QDialog *SecondWindow)
    {
        if (SecondWindow->objectName().isEmpty())
            SecondWindow->setObjectName(QString::fromUtf8("SecondWindow"));
        SecondWindow->resize(942, 612);
        SecondWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label = new QLabel(SecondWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 10, 657, 34));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier 10 Pitch"));
        font.setPointSize(14);
        label->setFont(font);
        label_2 = new QLabel(SecondWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 410, 181, 21));
        pushButton = new QPushButton(SecondWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 450, 111, 31));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 157, 241);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius: 15px;"));
        pushButton_2 = new QPushButton(SecondWindow);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(700, 450, 111, 31));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 157, 241);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius: 15px;"));
        label_3 = new QLabel(SecondWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(660, 410, 201, 21));
        pushButton_3 = new QPushButton(SecondWindow);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(190, 540, 111, 31));
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 157, 241);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius: 15px;"));
        label_4 = new QLabel(SecondWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 100, 321, 301));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_5 = new QLabel(SecondWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(590, 100, 351, 301));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_4 = new QPushButton(SecondWindow);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(410, 540, 111, 31));
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 157, 241);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius: 15px;"));
        pushButton_5 = new QPushButton(SecondWindow);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(620, 540, 111, 31));
        pushButton_5->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 157, 241);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius: 15px;"));
        label_6 = new QLabel(SecondWindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(320, 500, 297, 17));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(164, 0, 0);"));

        retranslateUi(SecondWindow);

        QMetaObject::connectSlotsByName(SecondWindow);
    } // setupUi

    void retranslateUi(QDialog *SecondWindow)
    {
        SecondWindow->setWindowTitle(QApplication::translate("SecondWindow", "Dialog", nullptr));
        label->setText(QApplication::translate("SecondWindow", "<html><head/><body><h2 style=\" margin-top:16px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:x-large; font-weight:600;\">Chargement de l'image et du fichier XML</span></h2></body></html>", nullptr));
        label_2->setText(QApplication::translate("SecondWindow", "Veuillez entrer une image", nullptr));
        pushButton->setText(QApplication::translate("SecondWindow", "Load File", nullptr));
        pushButton_2->setText(QApplication::translate("SecondWindow", "Load XML", nullptr));
        label_3->setText(QApplication::translate("SecondWindow", "Veuillez entrer le fichier XML", nullptr));
        pushButton_3->setText(QApplication::translate("SecondWindow", "Methode 1", nullptr));
        label_4->setText(QString());
        label_5->setText(QString());
        pushButton_4->setText(QApplication::translate("SecondWindow", "Methode 2", nullptr));
        pushButton_5->setText(QApplication::translate("SecondWindow", "Methode 3", nullptr));
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SecondWindow: public Ui_SecondWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWINDOW_H
