#include "encode.h"
#include "ui_encode.h"
#include <QDebug>

Encode::Encode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Encode)
{
    ui->setupUi(this);
}

Encode::~Encode()
{
    delete ui;
}



void Encode::on_cancelButton_clicked()
{
   this->close();
}

void Encode::on_runButton_clicked()
{
    ffmpeg=new QProcess(this);
    QString program ="ffmpeg.exe";      //program must be placed into same directory as VC
    QStringList arguments;
    arguments << "-h";
    connect(ffmpeg, SIGNAL(started()), this, SLOT(processStarted()));
    connect(ffmpeg,SIGNAL(readyReadStandardOutput()),this,SLOT(readyReadStandardOutput()));
    connect(ffmpeg, SIGNAL(finished(int)), this, SLOT(encodingFinished()));
    ffmpeg->start(program,arguments);
    ffmpeg->waitForFinished();

}

void Encode::processStarted(){

    qDebug() << "ffmpeg process started()";

}
void Encode::readyReadStandardOutput(){

    ffmpegOutput.append(ffmpeg->readAllStandardOutput());
    emit updateTextOutput(ffmpegOutput);


}
void Encode::encodingFinished(){
    this->close();
    qDebug()<<"ffmpeg process finished()";

}

