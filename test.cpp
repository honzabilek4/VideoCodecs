#include "test.h"
#include "ui_test.h"
#include <QFileInfo>
#include <QFileDialog>
#include <QDebug>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QThread>

Test::Test(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Test)
{
    ui->setupUi(this);
    psnr=NULL;
    msvd=NULL;
    ssim=NULL;
    msgBoxErr=false;
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

    //ui->runButton->setEnabled(false);

    msgBoxErr=false;

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

        ssim=new SsimClass(ui->windowSizeBox->value(),ui->stepSizeBox->value());
        connect (&watcher_2,SIGNAL(finished()),SLOT(ssimResultReady()));
        QFuture<double*> future = QtConcurrent::run(ssim,&SsimClass::computeSsim,file1.c_str(),file2.c_str(),ui->widthBox->text().toInt(),ui->heightBox->text().toInt(),maxFrame);

        watcher_2.setFuture(future);

    }
    if(ui->msvdBox->isChecked())
    {

        msvd = new MsvdClass();
        connect (&watcher_3,SIGNAL(finished()),SLOT(msvdResultReady()));
        QFuture<double*> future = QtConcurrent::run(msvd,&MsvdClass::computeMsvd,file1.c_str(),file2.c_str(),ui->widthBox->text().toInt(),ui->heightBox->text().toInt(),maxFrame);
        watcher_3.setFuture(future);
    }
    if(!(watcher.isRunning()|| watcher_2.isRunning()|| watcher_3.isRunning()))
    {
        QMessageBox message;
        message.setText(QString::fromStdString("Please select method."));
        message.setIcon(QMessageBox::Critical);
        message.exec();
    }

}

void Test::on_cancelButton_clicked()
{
    if(watcher.isRunning()|| watcher_2.isRunning()|| watcher_3.isRunning())
    {
        if(psnr!=NULL)
            psnr->_abort=true;
        if(ssim!=NULL)
            ssim->_abort=true;
        if(msvd!=NULL)
            msvd->_abort=true;
        ui->runButton->setEnabled(true);
    }
    else
    {
        this->close();
    }


}

void Test::psnrResultReady()
{
    if(!psnr->error.empty()&& msgBoxErr==false)
    {
        msgBoxErr=true;
        if(ssim!=NULL)
            ssim->_abort=true;
        if(msvd!=NULL)
            msvd->_abort=true;

        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString(psnr->error));
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
    }
}
void Test::ssimResultReady()
{
    if(!ssim->error.empty()&& msgBoxErr==false)
    {
        msgBoxErr=true;
        if(psnr!=NULL)
            psnr->_abort=true;
        if(msvd!=NULL)
            msvd->_abort=true;

        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString(ssim->error));
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();


    }
}
void Test::msvdResultReady()
{
    if(!msvd->error.empty()&& msgBoxErr==false)
    {
        msgBoxErr=true;
        if(psnr!=NULL)
            psnr->_abort=true;
        if(ssim!=NULL)
            ssim->_abort=true;

        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString(msvd->error));
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();

    }
}
