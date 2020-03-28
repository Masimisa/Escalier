#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QTextStream>
#include <iostream>

SecondWindow::SecondWindow(QWidget *parent, QString filename, QString xml) :
    QDialog(parent),
    ui(new Ui::SecondWindow),
    filename(""),
    xml("")
{
    ui->setupUi(this);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

// Permet de load une image
void SecondWindow::on_pushButton_clicked()
{
    filename = QFileDialog::getOpenFileName(this, "Open a file", "/home/masimisa/Documents/Projet/Escalier/data/images");
    // QMessageBox::information(this, "..", filename); : Permet de faire un alert du path absolus

    ui->label_2->setText("Success : Image Loaded");
    QPixmap pix(filename);

    int w = ui->label_4->width();
    int h = ui->label_4->height();

    ui->label_4->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

}

// Permet de load un fichier XML
void SecondWindow::on_pushButton_2_clicked()
{
    xml = QFileDialog::getOpenFileName(this, "Open a XML File", "/home/masimisa/Documents/Projet/Escalier/data/xml");
    ui->label_3-> setText("Success : XML File Loaded");

    QFile file(xml);

    QString line;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while (!stream.atEnd()){

            line.append(stream.readLine()+"\n");
        }
        ui->label_5->setText(line);
    }
    file.close();
}

// Permet de lancer la premiere methode
void SecondWindow::on_pushButton_3_clicked()
{
    if(filename.size() == 0 || xml.size() == 0){
        ui->label_6->setText("Veuillez charger une image et un fichier xml.");
        return;
    }

    ui->label_6->setText("");

    string filename_ = filename.toStdString();
    string path = filename_.substr(0,filename_.length()-17)+"code/method1/";
    string exe_ = "./launcher.sh " + filename.toStdString() + " " + xml.toStdString();

    system(("cd " + path + " && " + exe_).c_str());

    method1 = new Method1(this, filename_.substr(0,filename_.length()-17)+"data");
    method1->show();
}

// Permet de lancer la deuxieme methode
void SecondWindow::on_pushButton_4_clicked()
{
    if(filename.size() == 0 || xml.size() == 0){
        ui->label_6->setText("Veuillez charger une image et un fichier xml.");
        return;
    }

    ui->label_6->setText("");

    string filename_ = filename.toStdString();
    string path = filename_.substr(0,filename_.length()-17)+"code/method2/";
    string exe_ = "./launcher.sh " + filename.toStdString() + " " + xml.toStdString();

    system(("cd " + path + " && " + exe_).c_str());

    method2 = new Method2(this, filename_.substr(0,filename_.length()-17)+"data");
    method2->show();
}

// Permet de lancer la troisieme methode
void SecondWindow::on_pushButton_5_clicked()
{
    if(filename.size() == 0 || xml.size() == 0){
        ui->label_6->setText("Veuillez charger une image et un fichier xml.");
        return;
    }

    ui->label_6->setText("");

    string filename_ = filename.toStdString();
    string path = filename_.substr(0,filename_.length()-17)+"code/method3/";
    string exe_ = "./launcher.sh " + filename.toStdString() + " " + xml.toStdString();

    system(("cd " + path + " && " + exe_).c_str());

    cout << "Dans la methode 3" << endl;
    cout << path << endl;
    method3 = new Method3(this, filename_.substr(0,filename_.length()-17)+"data");
    method3->show();
}
