#include "test.h"
#include "ui_test.h"
#include <QFileInfo>
#include <QFileDialog>
#include <QDebug>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QMessageBox>
#include <QSettings>


Test::Test(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Test)
{
    ui->setupUi(this);
    loadSettings();
    psnr=NULL;
    msvd=NULL;
    ssim=NULL;
    msgBoxErr=false;
}

Test::~Test()
{
    delete ui;
}


void Test::loadSettings()
{
    QSettings settings;
    homeFolder=settings.value("testFolder","C:/").toString();
    ui->widthBox->setValue(settings.value("test/width").toInt());
    ui->heightBox->setValue(settings.value("test/height").toInt());
    ui->frameBox->setValue(settings.value("test/frames",100).toInt());
}

void Test::on_openButton_clicked()
{
    QString fileStr = QFileDialog::getOpenFileName(this,tr("Open file"),homeFolder,tr("rawvideo(*.yuv)"));
    QFileInfo file(fileStr);
    if(!fileStr.isEmpty())
    {
        ui->originalLabel->setText(file.fileName());
        file1=fileStr.toStdString();

    }
}

void Test::on_openButton_2_clicked()
{
    QString fileStr = QFileDialog::getOpenFileName(this,tr("Open file"),homeFolder,tr("rawvideo(*.yuv)"));
    QFileInfo file(fileStr);
    if(!fileStr.isEmpty())
    {
        ui->decodedLabel->setText(file.fileName());
        file2=fileStr.toStdString();

    }
}

void Test::on_runButton_clicked()
{


    ui->runButton->setEnabled(false);

    msgBoxErr=false;


    if(file1.empty()||file2.empty())
    {
        QMessageBox message;
        message.setText(QString::fromStdString("Please select files."));
        message.setIcon(QMessageBox::Critical);
        message.exec();
        ui->runButton->setEnabled(true);
        return;
    }
    if(ui->widthBox->value()==1||ui->heightBox->value()==1)
    {
        QMessageBox message;
        message.setText(QString::fromStdString("Please set dimensions."));
        message.setIcon(QMessageBox::Critical);
        message.exec();
        ui->runButton->setEnabled(true);
        return;
    }

    int maxFrame=ui->frameBox->value();

    if(ui->psnrBox->isChecked())
    {
        psnr=new PsnrClass();
        connect(&watcher,SIGNAL(finished()),SLOT(psnrResultReady()));
        QFuture<double**> future=QtConcurrent::run(psnr,&PsnrClass::computePSNR,file1.c_str(),file2.c_str(),ui->widthBox->text().toInt(),ui->heightBox->text().toInt(),maxFrame);
        watcher.setFuture(future);

        emit updateOutput("PSNR started");

    }
    if(ui->ssimBox->isChecked())
    {

        ssim=new SsimClass(ui->windowSizeBox->value(),ui->stepSizeBox->value());

        connect (&watcher_2,SIGNAL(finished()),SLOT(ssimResultReady()));
        QFuture<double*> future = QtConcurrent::run(ssim,&SsimClass::computeSsim,file1.c_str(),file2.c_str(),ui->widthBox->text().toInt(),ui->heightBox->text().toInt(),maxFrame);

        watcher_2.setFuture(future);

        emit updateOutput("SSIM started");

    }
    if(ui->msvdBox->isChecked())
    {

        msvd = new MsvdClass();
        connect (&watcher_3,SIGNAL(finished()),SLOT(msvdResultReady()));
        QFuture<double*> future = QtConcurrent::run(msvd,&MsvdClass::computeMsvd,file1.c_str(),file2.c_str(),ui->widthBox->text().toInt(),ui->heightBox->text().toInt(),maxFrame);
        watcher_3.setFuture(future);

        emit updateOutput("MSVD started");
    }
    if(!(watcher.isRunning()|| watcher_2.isRunning()|| watcher_3.isRunning()))
    {
        QMessageBox message;
        message.setText(QString::fromStdString("Please select method."));
        message.setIcon(QMessageBox::Critical);
        message.exec();
        ui->runButton->setEnabled(true);
    }

    emit resetResults();

    QSettings settings;
    settings.setValue("test/width",QString::number(ui->widthBox->value()));
    settings.setValue("test/height",QString::number(ui->heightBox->value()));
    settings.setValue("test/frames",QString::number(ui->frameBox->value()));


}

void Test::on_cancelButton_clicked()
{
    if(watcher.isRunning()|| watcher_2.isRunning()|| watcher_3.isRunning())
    {
        if(psnr!=NULL)
            psnr->_abort=true;
        emit updateOutput("PSNR canceled");
        if(ssim!=NULL)
            ssim->_abort=true;
        emit updateOutput("SSIM canceled");
        if(msvd!=NULL)
            msvd->_abort=true;
        ui->runButton->setEnabled(true);
        emit updateOutput("MSVD canceled");
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
        ui->runButton->setEnabled(true);
        return;
    }


        double** array=watcher.future().result();
        if((!psnr->error.empty())||psnr->_abort)
        {
            return;
        }
        else
        {
            QVector<double> psnrVector;
            for(int i=0;i<(ui->frameBox->value());i++)
            {
                psnrVector.append(array[i][0]);
            }

            if(!psnrVector.isEmpty())
                emit psnrReady(psnrVector);
        }

        if((!watcher.isRunning()) && (!watcher_2.isRunning())&& (!watcher_3.isRunning()))
        {
            this->close();
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
        ui->runButton->setEnabled(true);
        return;
    }

    double* array=watcher_2.future().result();
    if((!ssim->error.empty())||ssim->_abort)
    {
        return;
    }
    else
    {
        QVector<double> ssimVector;
    for(int i=0;i<(ui->frameBox->value());i++)
    {
        ssimVector.append(array[i]);
    }

    if(!ssimVector.isEmpty())
        emit ssimReady(ssimVector);
    }
    if((!watcher.isRunning()) && (!watcher_2.isRunning())&& (!watcher_3.isRunning()))
    {
        this->close();
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
        ui->runButton->setEnabled(true);
        return;
    }


    double* array=watcher_3.future().result();
    if((!msvd->error.empty())||msvd->_abort)
    {
        return;
    }
    else
    {
        QVector<double> msvdVector;
        for(int i=0;i<(ui->frameBox->value());i++)
        {
            msvdVector.append(array[i]);
        }

        if(!msvdVector.isEmpty())
            emit msvdReady(msvdVector);
    }
    if((!watcher.isRunning()) && (!watcher_2.isRunning())&& (!watcher_3.isRunning()))
    {
        this->close();
    }

}


