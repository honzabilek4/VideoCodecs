#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
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
    file1 = QFileDialog::getOpenFileUrl(this,tr("Open file"));
    ui->statusBar->showMessage(file1.toString());
    ui->label->setText(file1.fileName());
}

void MainWindow::on_openFile2_clicked()
{
    file2 = QFileDialog::getOpenFileUrl(this,tr("Open file"));
    ui->statusBar->showMessage(file2.toString());
    ui->label_2->setText(file2.fileName());
}

void MainWindow::on_psnrButton_clicked()
{
    PsnrClass* psnr = new PsnrClass();
   try{
        double** array=psnr->computePSNR(file1.toString().toStdString().c_str(),file2.toString().toStdString().c_str(),352,288,1);
    }
    catch(const char* message) {
        ui->statusBar->showMessage((QString(message)));
    }
}
