#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "encode.h"
#include <QFileDialog>
#include <QLabel>
#include <QFileInfo>
#include <QApplication>
#include <QList>
#include <QScrollBar>
#include "PsnrClass.h"
#include "SsimClass.h"
#include "MsvdClass.h"

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

   try{
        PsnrClass* psnr = new PsnrClass();
        psnrArray=psnr->computePSNR(file1.c_str(),file2.c_str(),352,288,260);
        QString numbers;

        for(int i=0;i<260;i++)
        {
         numbers.append(QString::number(psnrArray[i][0])+ "; ");
         ui->textBrowser->setText(numbers);
        }

    }
    catch(const char* message) {
        ui->statusBar->showMessage(QString(message));
    }

}


void MainWindow::on_ssimButton_clicked()
{

    try{
        SsimClass* ssimMan = new SsimClass();
        ssimResults = ssimMan->computeSsim(file1.c_str(),file2.c_str(),352,288,260,16,8);

        QString numbers;
        for(int i=0;i<260;i++)
        {
         numbers.append(QString::number(ssimResults[i])+ "; ");
         ui->textBrowser_2->setText(numbers);
        }

    }
    catch(const char* message){
        ui->statusBar->showMessage(QString(message));
    }
}

void MainWindow::on_msvdButton_clicked()
{
    try{
        MsvdClass* msvdMan=new MsvdClass();
        msvdResults=msvdMan->computeMsvd(file1.c_str(),file2.c_str(),352,288,260);
        QString numbers;
        for(int i=0;i<260;i++)
        {
         numbers.append(QString::number(msvdResults[i])+ "; ");
         ui->textBrowser_3->setText(numbers);
        }
    }
    catch(const char* message){
        ui->statusBar->showMessage(QString(message));
    }

}



void MainWindow::on_encodeButton_clicked()
{
    Encode* e= new Encode();
    e->show();

    connect(e,SIGNAL(updateTextOutput(const QString)),this,SLOT(setOutputText(const QString)));

}

void MainWindow::setOutputText(const QString text)
{
    ui->textOutput->setText(text);
    ui->textOutput->verticalScrollBar()->setSliderPosition(
                ui->textOutput->verticalScrollBar()->maximum());
}
