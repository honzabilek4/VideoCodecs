#include "test.h"
#include "ui_test.h"
#include <QFileInfo>
#include <QFileDialog>
#include <QDebug>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include "PsnrClass.h"
#include "SsimClass.h"
#include "MsvdClass.h"

Test::Test(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Test)
{
    ui->setupUi(this);
}

Test::~Test()
{
    delete ui;
}



void Test::on_openButton_clicked()
{
    QString fileStr = QFileDialog::getOpenFileName(this,tr("Open file"));
    QFileInfo file(fileStr);
    if(!fileStr.isEmpty())
    {
        ui->originalLabel->setText(file.fileName());
        file1=fileStr.toStdString();

    }
}

void Test::on_openButton_2_clicked()
{
    QString fileStr = QFileDialog::getOpenFileName(this,tr("Open file"));
    QFileInfo file(fileStr);
    if(!fileStr.isEmpty())
    {
        ui->decodedLabel->setText(file.fileName());
        file2=fileStr.toStdString();

    }
}

void Test::on_runButton_clicked()
{
    int numberOfFrames=ui->spinBox->value();
    if(ui->psnrBox->isChecked())
    {
        PsnrClass* psnr=new PsnrClass();
        QFuture<double**> future=QtConcurrent::run(psnr,&PsnrClass::computePSNR,file1.c_str(),file2.c_str(),ui->lineEdit->text().toInt(),ui->lineEdit_2->text().toInt(),numberOfFrames);
        qDebug() << "Psnr has finished";
    }
    if(ui->ssimBox->isChecked())
    {

    }
    if(ui->msvdBox->isChecked())
    {

    }

}

void Test::on_cancelButton_clicked()
{
  this->close();
}
