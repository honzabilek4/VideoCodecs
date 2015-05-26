#include "test.h"
#include "ui_test.h"
#include <QFileInfo>
#include <QFileDialog>
#include <QDebug>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QMessageBox>
#include <QSettings>
#include "y4mparser.h"

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
    delete ssim;
    delete psnr;
    delete msvd;
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
    QString fileStr = QFileDialog::getOpenFileName(this,tr("Open file"),homeFolder,tr("rawvideo(*.yuv;*.y4m)"));
    QFileInfo file(fileStr);
    if(!fileStr.isEmpty())
    {
        ui->originalLabel->setText(file.fileName());
        file1=fileStr.toStdString();
        if(file.suffix()=="y4m")
        {
            Y4mParser parser;
            ui->widthBox->setValue(parser.getWidth(fileStr));
            ui->heightBox->setValue(parser.getHeight(fileStr));

        }
    }
}

void Test::on_openButton_2_clicked()
{
    QStringList tempList = QFileDialog::getOpenFileNames(this,tr("Open files"),homeFolder,tr("rawvideo(*.yuv;*.y4m)"));

    if(!tempList.isEmpty())
     {
        fileList=tempList;
        QString fileStr=fileList.first();
        fileIndex=0;
        QFileInfo file(fileStr);
        QString label="("+ QString::number(fileList.length())+") " + file.fileName();
        ui->decodedLabel->setText(label);
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

    maxFrame=ui->frameBox->value();
    QFileInfo file(QString::fromStdString(file1));
    if(file.suffix()=="y4m")
    {
        ffmpeg = new QProcess(this);
        QString program ="ffmpeg.exe";
        ffmpeg->start(program,getArguments(1));
        ffmpeg->waitForFinished();
    }
    file.setFile(QString::fromStdString(file2));

    if(file.suffix()=="y4m")
    {
        ffmpeg = new QProcess(this);
        QString program ="ffmpeg.exe";
        ffmpeg->start(program,getArguments(2));
        ffmpeg->waitForFinished();
    }
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
    if(!(ui->ssimBox->isChecked()|| ui->psnrBox->isChecked()|| ui->msvdBox->isChecked()))
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

void Test::runTest()
{
    QFileInfo file(QString::fromStdString(file1));
    if(file.suffix()=="y4m")
    {
        ffmpeg = new QProcess(this);
        QString program ="ffmpeg.exe";
        ffmpeg->start(program,getArguments(1));
        ffmpeg->waitForFinished();
    }
    file.setFile(QString::fromStdString(file2));

    if(file.suffix()=="y4m")
    {
        ffmpeg = new QProcess(this);
        QString program ="ffmpeg.exe";
        ffmpeg->start(program,getArguments(2));
        ffmpeg->waitForFinished();
    }
    if(ui->psnrBox->isChecked())
    {
//        psnr=new PsnrClass();
//        connect(&watcher,SIGNAL(finished()),SLOT(psnrResultReady()));
        QFuture<double**> future=QtConcurrent::run(psnr,&PsnrClass::computePSNR,file1.c_str(),file2.c_str(),ui->widthBox->text().toInt(),ui->heightBox->text().toInt(),maxFrame);
        watcher.setFuture(future);

        emit updateOutput("PSNR started");

    }
    if(ui->ssimBox->isChecked())
    {

//        ssim=new SsimClass(ui->windowSizeBox->value(),ui->stepSizeBox->value());
//        connect (&watcher_2,SIGNAL(finished()),SLOT(ssimResultReady()));
        QFuture<double*> future = QtConcurrent::run(ssim,&SsimClass::computeSsim,file1.c_str(),file2.c_str(),ui->widthBox->text().toInt(),ui->heightBox->text().toInt(),maxFrame);

        watcher_2.setFuture(future);

        emit updateOutput("SSIM started");

    }
    if(ui->msvdBox->isChecked())
    {

//        msvd = new MsvdClass();
//        connect (&watcher_3,SIGNAL(finished()),SLOT(msvdResultReady()));
        QFuture<double*> future = QtConcurrent::run(msvd,&MsvdClass::computeMsvd,file1.c_str(),file2.c_str(),ui->widthBox->text().toInt(),ui->heightBox->text().toInt(),maxFrame);
        watcher_3.setFuture(future);

        emit updateOutput("MSVD started");
    }
    if(!(ui->ssimBox->isChecked()|| ui->psnrBox->isChecked()|| ui->msvdBox->isChecked()))
    {
        QMessageBox message;
        message.setText(QString::fromStdString("Please select method."));
        message.setIcon(QMessageBox::Critical);
        message.exec();
        ui->runButton->setEnabled(true);
    }
}

QStringList Test::getArguments(int fileNo)
{
    QStringList arguments;
    QFileInfo file;
    std::string* s;
    if(fileNo==1)
    {
        file.setFile(QString::fromStdString(file1));
        s=&file1;
    }
    else
    {
        file.setFile(QString::fromStdString(file2));
        s=&file2;
    }
    QString outfile=file.absoluteFilePath() + "."+ "yuv";

    arguments<<"-y"<<"-i"<<QString::fromStdString(*s)<<"-pix_fmt"<<"yuv420p"<<outfile;
    *s=outfile.toStdString();  /*set file path to yuv file*/
    return arguments;
}

void Test::on_cancelButton_clicked()
{
    if(watcher.isRunning()|| watcher_2.isRunning()|| watcher_3.isRunning())
    {
        if (psnr != NULL)
        {
            psnr->_abort = true;
            emit updateOutput("PSNR canceled");
        }
        if (ssim != NULL)
        {
            ssim->_abort = true;
            emit updateOutput("SSIM canceled");
        }
        if (msvd != NULL)
        {
            msvd->_abort = true;
            emit updateOutput("MSVD canceled");
        }
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
           // delete[] array[i];
        }

        if(!psnrVector.isEmpty())
            emit psnrReady(psnrVector);
    }

    //delete[] array;

    if((!watcher.isRunning()) && (!watcher_2.isRunning())&& (!watcher_3.isRunning()))
    {
        QString exportFileName=QString::fromStdString(file2)+".csv";
        emit exportResults(exportFileName);
        if (fileIndex<fileList.length()-1) {
            ++fileIndex;
            file2=fileList.at(fileIndex).toStdString();
            runTest();
        } else {
            this->close();
        }

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

   // free(array);

    if((!watcher.isRunning()) && (!watcher_2.isRunning())&& (!watcher_3.isRunning()))
    {
        QString exportFileName=QString::fromStdString(file2)+".csv";
        emit exportResults(exportFileName);
        if (fileIndex<fileList.length()-1) {
            ++fileIndex;
            file2=fileList.at(fileIndex).toStdString();
            runTest();

        } else {
            this->close();
        }
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

    //free(array);

    if((!watcher.isRunning()) && (!watcher_2.isRunning())&& (!watcher_3.isRunning()))
    {
        QString exportFileName=QString::fromStdString(file2)+".csv";
        emit exportResults(exportFileName);
        if (fileIndex<fileList.length()-1) {
            ++fileIndex;
            file2=fileList.at(fileIndex).toStdString();
            runTest();
        } else {
            this->close();
        }
    }

}


