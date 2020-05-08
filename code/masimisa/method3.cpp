#include "method3.h"
#include "ui_method3.h"

#include <iostream>
#include <fstream>

Method3::Method3(QWidget *parent, string path_) :
    QDialog(parent),
    ui(new Ui::Method3),
    path(path_)
{
    ui->setupUi(this);

    /********* Interface Graphique *********/

    // Premier Label
    QPixmap pix(QString::fromStdString(path+"/.tmp/sp/th.jpg"));
    int w = ui->label_5->width();
    int h = ui->label_5->height();
    ui->label_5->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

    // Second Label
    QPixmap pix_(QString::fromStdString(path+"/.tmp/sp/cannyed_img.jpg"));
    w = ui->label_6->width();
    h = ui->label_6->height();
    ui->label_6->setPixmap(pix_.scaled(w, h, Qt::KeepAspectRatio));

    // Troisieme Label
    QPixmap pix__(QString::fromStdString(path+"/.tmp/sp/black.jpg"));
    w = ui->label_7->width();
    h = ui->label_7->height();
    ui->label_7->setPixmap(pix__.scaled(w, h, Qt::KeepAspectRatio));

    // Quatrieme Label
    QPixmap pix___(QString::fromStdString(path+"/.tmp/sp/line_img.jpg"));
    w = ui->label_8->width();
    h = ui->label_8->height();
    ui->label_8->setPixmap(pix___.scaled(w, h, Qt::KeepAspectRatio));

    // Cinquieme Label
    QPixmap pix____(QString::fromStdString(path+"/.tmp/sp/imgV.jpg"));
    w = ui->label_9->width();
    h = ui->label_9->height();
    ui->label_9->setPixmap(pix____.scaled(w, h, Qt::KeepAspectRatio));

    // Sixieme Label
    QPixmap pix_____(QString::fromStdString(path+"/.tmp/sp/imgH.jpg"));
    w = ui->label_10->width();
    h = ui->label_10->height();
    ui->label_10->setPixmap(pix_____.scaled(w, h, Qt::KeepAspectRatio));



    ifstream sp(path+"/.tmp/txt/sp");
    string ligne; //A variable to store the read lines
    string text;  //A variable to store all the text, we will make the regular expression on this variable
    if (sp){
        while (getline(sp, ligne))//As long as we are not at the end we continue to read
           text += ligne + '\n';
        sp.close();

    }
    ui->label_2->setText(QString::fromStdString(text));


}

Method3::~Method3()
{
    delete ui;
}

// A Gauche
void Method3::on_pushButton_3_clicked()
{
    if(!ui->label_7->isHidden()){
        ui->label_5->setHidden(false);
        ui->label_6->setHidden(false);
        ui->label_7->setHidden(true);
        ui->label_8->setHidden(true);
        ui->label_9->setHidden(true);
        ui->label_10->setHidden(true);
    }else if(!ui->label_9->isHidden()){
        ui->label_5->setHidden(true);
        ui->label_6->setHidden(true);
        ui->label_7->setHidden(false);
        ui->label_8->setHidden(false);
        ui->label_9->setHidden(true);
        ui->label_10->setHidden(true);
    }
}

// A Droite
void Method3::on_pushButton_2_clicked()
{
    if(!ui->label_5->isHidden()){
        ui->label_5->setHidden(true);
        ui->label_6->setHidden(true);
        ui->label_7->setHidden(false);
        ui->label_8->setHidden(false);
        ui->label_9->setHidden(true);
        ui->label_10->setHidden(true);
    }else if(!ui->label_7->isHidden()){
        ui->label_5->setHidden(true);
        ui->label_6->setHidden(true);
        ui->label_7->setHidden(true);
        ui->label_8->setHidden(true);
        ui->label_9->setHidden(false);
        ui->label_10->setHidden(false);
    }
}
