#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>
#include "../../console/PSXMSFS.h"

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
    this->close();
}


void MainWindow::on_pushButton_2_clicked()
{
    maingui(1,NULL,0);
}


void MainWindow::on_B_quit_clicked()
{
     this->close();
}


void MainWindow::on_B_connect_clicked()
{
    QString tmpstring = ui->E_MAINIP->text();

    ui->E_Boost->setText(tmpstring);

     ui->E_MSFS->setText(QString::number(sPSX));
     ui->E_MAINIP->setText(QStringLiteral("127.0.0.1"));
     ui->E_Boost->setText(QStringLiteral("127.0.0.1"));
     ui->E_MSFS->setText(QStringLiteral("127.0.0.1"));

open_connections();
}

