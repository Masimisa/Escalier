#include "method1.h"
#include "ui_method1.h"
#include <iostream>
#include <fstream>

using namespace cv;

Method1::Method1(QWidget *parent, string path_) :
    QDialog(parent),
    ui(new Ui::Method1),
    path(path_)
{
    ui->setupUi(this);

    /********* Interface Graphique *********/

    // Premier Label
    QPixmap pix(QString::fromStdString(path+"/.tmp/ap/preprocessing.jpg"));
    int w = ui->label_5->width();
    int h = ui->label_5->height();
    ui->label_5->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

    // Second Label
    QPixmap pix_(QString::fromStdString(path+"/.tmp/ap/final.jpg"));
    w = ui->label_6->width();
    h = ui->label_6->height();
    ui->label_6->setPixmap(pix_.scaled(w, h, Qt::KeepAspectRatio));

    // Troisieme Label
    QPixmap pix__(QString::fromStdString(path+"/.tmp/sp/preprocessing.jpg"));
    w = ui->label_7->width();
    h = ui->label_7->height();
    ui->label_7->setPixmap(pix__.scaled(w, h, Qt::KeepAspectRatio));

    // Quatrieme Label
    QPixmap pix___(QString::fromStdString(path+"/.tmp/sp/final.jpg"));
    w = ui->label_8->width();
    h = ui->label_8->height();
    ui->label_8->setPixmap(pix___.scaled(w, h, Qt::KeepAspectRatio));

    ifstream sp(path+"/.tmp/txt/sp");
    string ligne; //A variable to store the read lines
    string text;  //A variable to store all the text, we will make the regular expression on this variable
    if (sp){
        while (getline(sp, ligne))//As long as we are not at the end we continue to read
           text += ligne + '\n';
        sp.close();

    }
    ui->label_2->setText(QString::fromStdString(text));

    ligne = ""; text  = "";
    ifstream ap(path+"/.tmp/txt/ap");
    if (ap){
        while (getline(ap, ligne))//As long as we are not at the end we continue to read
           text += ligne + '\n';
        ap.close();
    }
    ui->label_4->setText(QString::fromStdString(text));
}

Method1::~Method1()
{
    delete ui;
}

// Sans Preprocessing
void Method1::on_pushButton_3_clicked()
{
    ui->label_2->setHidden(false);
    ui->label_4->setHidden(true);
    ui->label_5->setHidden(true);
    ui->label_6->setHidden(true);
    ui->label_7->setHidden(false);
    ui->label_8->setHidden(false);
}

// Avec Preprocessing
void Method1::on_pushButton_2_clicked()
{
    ui->label_2->setHidden(true);
    ui->label_4->setHidden(false);
    ui->label_5->setHidden(false);
    ui->label_6->setHidden(false);
    ui->label_7->setHidden(true);
    ui->label_8->setHidden(true);
}
