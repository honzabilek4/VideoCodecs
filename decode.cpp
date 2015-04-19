#include "decode.h"
#include "ui_decode.h"
#include <QDebug>
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>

Decode::Decode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Decode)
{
    ui->setupUi(this);
}

Decode::~Decode()
{
    delete ui;
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
    ffmpeg = new QProcess(this);
    QString program ="ffmpeg.exe";
    connect(ffmpeg,SIGNAL(started()),this,SLOT(processStarted()));
    connect(ffmpeg,SIGNAL(readyReadStandardOutput()),this,SLOT(readyReadStandardOutput()));
    connect(ffmpeg,SIGNAL(readyReadStandardError()),this,SLOT(readyReadStandardError()));
    connect(ffmpeg, SIGNAL(finished(int)), this, SLOT(decodingFinished()));
    ffmpeg->start(program,getArguments());
    this->hide();

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

    qDebug()<<"ffmpeg process finished()";
    QMessageBox msgBox;
    msgBox.setText("Decoding has finished.");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
    this->close();
}


void Decode::on_browseButton_clicked()
{
    fileStr = QFileDialog::getOpenFileName(this,tr("Open file"),homeFolder);
    QFileInfo file(fileStr);
    if(!fileStr.isEmpty()){
        ui->label->setText(file.fileName());
    }
}

QStringList Decode::getArguments(){
    QStringList arguments;
    QFileInfo file(fileStr);
    QString fileName;
    if(!saveAsStr.isEmpty())
    {
        fileName=saveAsStr;
    }
    else
    {
        fileName=file.absoluteFilePath() + "_decoded.yuv";
    }
    arguments<<"-y"<<"-i"<<fileStr<<"-c:v"<<"rawvideo"<<"-pix_fmt"<<"yuv420p"<<fileName;
    return arguments;
}

void Decode::on_saveButton_clicked()
{
    saveAsStr = QFileDialog::getSaveFileName(this,tr("Save As"),homeFolder,tr("rawvideo(*.yuv)"));
    QFileInfo file(saveAsStr);
    if(!saveAsStr.isEmpty())
    {
        ui->label_2->setText(file.fileName());
    }
}

void Decode::setHomeFolder(QString folder)
{
    homeFolder=folder;
}
