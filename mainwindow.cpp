#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QLabel>
#include <QApplication>
#include "PsnrClass.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}



void MainWindow::on_openFile1_clicked()
{
    QString fileStr = QFileDialog::getOpenFileName(this,tr("Open file"));
   // ui->label->setText(fileUrl.fileName());
    ui->statusBar->showMessage(fileStr);
    fileStdStr1=fileStr.toStdString();
    file1=fileStdStr1.c_str();
}

void MainWindow::on_openFile2_clicked()
{
   QString fileStr = QFileDialog::getOpenFileName(this,tr("Open file"));
   //ui->label_2->setText(fileUrl.fileName());
   ui->statusBar->showMessage(fileStr);
   fileStdStr2= fileStr.toStdString();
   file2=fileStdStr2.c_str();
}

void MainWindow::on_psnrButton_clicked()
{
    PsnrClass* psnr = new PsnrClass();
   try{
        double** array=psnr->computePSNR(file1,file2,352,288,260);
    }
    catch(const char* message) {
        ui->statusBar->showMessage((QString(message)));
    }
}
