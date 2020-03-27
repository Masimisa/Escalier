#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //SecondWindow secondwindow;
    //secondwindow.setModal(true);
    //secondwindow.exec();

    close();

    secondwindow = new SecondWindow(this);
    secondwindow->show();
}
