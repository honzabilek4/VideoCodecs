#include "decode.h"
#include "ui_decode.h"
#include <QDebug>
#include <QFileInfo>
#include <QFileDialog>

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
    this->close();
    qDebug()<<"ffmpeg process finished()";

}


void Decode::on_browseButton_clicked()
{
    fileStr = QFileDialog::getOpenFileName(this,tr("Open file"));
    QFileInfo file(fileStr);
    if(!fileStr.isEmpty()){
        ui->label->setText(file.fileName());
    }
}

QStringList Decode::getArguments(){
    QStringList arguments;

    arguments<<"-y"<<"-i"<<fileStr<<"-c:v"<<"rawvideo"<<"-pix_fmt"<<"yuv420p"<<"output.yuv";
    return arguments;
}