#include "test.h"
#include "ui_test.h"
#include <QFileInfo>
#include <QFileDialog>
#include <QDebug>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QMessageBox>

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
    int maxFrame=ui->spinBox->value();

    if(ui->psnrBox->isChecked())
    {

        psnr=new PsnrClass();
        connect(&watcher,SIGNAL(finished()),SLOT(psnrResultReady()));
        QFuture<double**> future=QtConcurrent::run(psnr,&PsnrClass::computePSNR,file1.c_str(),file2.c_str(),ui->widthBox->text().toInt(),ui->heightBox->text().toInt(),maxFrame);
        watcher.setFuture(future);

    }
    if(ui->ssimBox->isChecked())
    {

        SsimClass* ssim=new SsimClass(ui->windowSizeBox->value(),ui->stepSizeBox->value());
        connect (&watcher_2,SIGNAL(finished()),SLOT(ssimResultReady()));
        QFuture<double*> future = QtConcurrent::run(ssim,&SsimClass::computeSsim,file1.c_str(),file2.c_str(),ui->widthBox->text().toInt(),ui->heightBox->text().toInt(),maxFrame);
        watcher_2.setFuture(future);

    }
    if(ui->msvdBox->isChecked())
    {

        MsvdClass* msvd =new MsvdClass();
        QFuture<double*> future = QtConcurrent::run(msvd,&MsvdClass::computeMsvd,file1.c_str(),file2.c_str(),ui->widthBox->text().toInt(),ui->heightBox->text().toInt(),maxFrame);
        connect (&watcher_3,SIGNAL(finished()),SLOT(msvdResultReady()));
        watcher_3.setFuture(future);
    }

}

void Test::on_cancelButton_clicked()
{
    this->close();
}

void Test::psnrResultReady()
{
    if(!psnr->error.empty())
    {
        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString(psnr->error));
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();

    }
}
void Test::ssimResultReady()
{
    if(!ssim->error.empty())
    {   QMessageBox msgBox;
        msgBox.setText(QString::fromStdString(psnr->error));
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
        this->close();
    }
}
void Test::msvdResultReady()
{
    if(!msvd->error.empty())
    {   QMessageBox msgBox;
        msgBox.setText(QString::fromStdString(psnr->error));
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
        this->close();
    }
}
