#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QLabel>
#include <QFileInfo>
#include <QApplication>
#include <QList>
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
    QFileInfo file(fileStr);
    ui->label->setText(file.fileName());
    ui->statusBar->showMessage(fileStr);
    file1=fileStr.toStdString();

}

void MainWindow::on_openFile2_clicked()
{
   QString fileStr = QFileDialog::getOpenFileName(this,tr("Open file"));
   QFileInfo file(fileStr);
   ui->label_2->setText(file.fileName());
   ui->statusBar->showMessage(fileStr);
   file2= fileStr.toStdString();
}

void MainWindow::on_psnrButton_clicked()
{
    PsnrClass* psnr = new PsnrClass();
   try{
        array=psnr->computePSNR(file1.c_str(),file2.c_str(),352,288,260);
    }
    catch(const char* message) {
        ui->statusBar->showMessage((QString(message)));
    }
    QString numbers;
    for(int i=0;i<260;i++){

         numbers.append(QString::number(array[i][0])+ "; ");

    }
    ui->textBrowser->setText(numbers);
}

