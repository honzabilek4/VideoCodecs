#include "decode.h"
#include "ui_decode.h"
#include <QDebug>
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>
#include <QSettings>

Decode::Decode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Decode)
{
    ui->setupUi(this);
    loadSettings();
    ui->groupBox->setVisible(false);
}

Decode::~Decode()
{
    delete ui;
}

void Decode::loadSettings()
{
    QSettings settings;
    homeFolder=settings.value("workFolder","C:/").toString();
}


void Decode::on_cancelButton_clicked()
{
    this-> close();
}


void Decode::on_runButton_clicked()
{
    if(fileStr.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("Please select file.");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
        return;
    }
    this->hide();
    emit toggleUi();

    startFfmpeg();

}
void Decode::startFfmpeg()
{

    ffmpeg = new QProcess(this);
    QString program ="ffmpeg.exe";
    connect(ffmpeg,SIGNAL(started()),this,SLOT(processStarted()));
    connect(ffmpeg,SIGNAL(readyReadStandardOutput()),this,SLOT(readyReadStandardOutput()));
    connect(ffmpeg,SIGNAL(readyReadStandardError()),this,SLOT(readyReadStandardError()));
    connect(ffmpeg, SIGNAL(finished(int)), this, SLOT(decodingFinished()));
    ffmpeg->start(program,getArguments());
}
void Decode::processStarted(){

    qDebug() << "ffmpeg process started()";

}
void Decode::readyReadStandardOutput(){

    ffmpegOutput.append(ffmpeg->readAllStandardOutput());

    emit updateTextOutput(ffmpegOutput);

}
void Decode::readyReadStandardError(){
    ffmpegOutput.append(ffmpeg->readAllStandardError());

    emit updateTextOutput(ffmpegOutput);
}

void Decode::decodingFinished(){

    if(currentItem<(fileList.length()-1))
    {   ++currentItem;
        fileStr=fileList.at(currentItem);
        startFfmpeg();
    }
    else
    {
        qDebug()<<"ffmpeg process finished()";
        QMessageBox msgBox;
        msgBox.setText("Decoding has finished.");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
        this->close();
        emit toggleUi();
    }
}


void Decode::on_browseButton_clicked()
{
    QStringList tempFileName=QFileDialog::getOpenFileNames(this,tr("Open files"),homeFolder);

    if(!tempFileName.isEmpty())
    {
        fileList=tempFileName;
        fileStr=tempFileName.first();
        currentItem=0;
        QFileInfo file(fileStr);
        QString text="(" + QString::number(fileList.length())+") " + file.fileName();
        ui->label->setText(text);
        if(fileList.length()>1)
        {
            ui->groupBox->setVisible(true);
            ui->saveButton->setText("Save To");
        }
        else
        {
            ui->groupBox->setVisible(false);
            ui->saveButton->setText("Save As");
            saveAsStr.clear();
            ui->label_2->setText("*_decoded.yuv");
        }
    }
}

void Decode::on_saveButton_clicked()
{   QString folder;
    if(saveAsStr.isEmpty())
    {
        fileStr.isEmpty() ? folder=homeFolder : folder=homeFolder+"/"+fileStr+"_decoded.yuv";
    }
    else
    {
        folder=saveAsStr;

    }
    if(fileList.length()>1)
    {
        QString tempDirectory=QFileDialog::getExistingDirectory(this,tr("Save To"),folder);
        if(!tempDirectory.isEmpty())
        {
            saveAsStr=tempDirectory+"/";
            QString label=saveAsStr;
            ui->label_2->setText(label);

        }
    }
    else
    {
        QString tempFileName = QFileDialog::getSaveFileName(this,tr("Save As"),folder,tr("rawvideo(*.yuv);;rawvideo(*.y4m)"));

        if(!tempFileName.isEmpty())
        {
            saveAsStr=tempFileName;
            QFileInfo file(saveAsStr);
            ui->label_2->setText(file.fileName());
        }
    }
}

QStringList Decode::getArguments(){
    QStringList arguments;
    QFileInfo file(fileStr);
    QString fileName;
    if(!saveAsStr.isEmpty())
    {
        if(fileList.length()>1)
        {
           fileName=saveAsStr + file.fileName();
           ui->radioYUV->isChecked()? fileName.append("_decoded.yuv") : fileName.append("_decoded.y4m");
        }
        else
        {
            fileName=saveAsStr;
        }

    }
    else
    {
        fileName=file.absoluteFilePath();
         ui->radioYUV->isChecked()? fileName.append("_decoded.yuv") : fileName.append("_decoded.y4m");
    }

    if (file.suffix()=="y4m") {
        arguments<<"-y"<<"-i"<<fileStr<<"-c:v"<<"y4m"<<fileName;
        return arguments;

    } else {
        arguments<<"-y"<<"-i"<<fileStr<<"-c:v"<<"rawvideo"<<"-pix_fmt"<<"yuv420p"<<fileName;
        qDebug() << arguments;
        return arguments;
    }

}

