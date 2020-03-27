#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include "method1.h"
#include "method2.h"

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr, QString filename = "", QString xml = "");
    ~SecondWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::SecondWindow *ui;
    Method1 *method1;
    Method2 *method2;
    QString filename;
    QString xml;
};

#endif // SECONDWINDOW_H
