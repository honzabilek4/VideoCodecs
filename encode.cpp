#include "encode.h"
#include "ui_encode.h"
#include <QDebug>
#include <QFileInfo>
#include <QFileDialog>

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
    connect(ffmpeg, SIGNAL(started()), this, SLOT(processStarted()));
    connect(ffmpeg,SIGNAL(readyReadStandardOutput()),this,SLOT(readyReadStandardOutput()));
    connect(ffmpeg,SIGNAL(readyReadStandardError()),this,SLOT(readyReadStandardError()));
    connect(ffmpeg, SIGNAL(finished(int)), this, SLOT(encodingFinished()));
    ffmpeg->start(program,getArguments());
    this->hide();
    //ffmpeg->waitForFinished();

}

void Encode::processStarted(){

    qDebug() << "ffmpeg process started()";

}
void Encode::readyReadStandardOutput(){

    ffmpegOutput.append(ffmpeg->readAllStandardOutput());

    emit updateTextOutput(ffmpegOutput);

}
void Encode::readyReadStandardError(){
    ffmpegOutput.append(ffmpeg->readAllStandardError());

    emit updateTextOutput(ffmpegOutput);
}
void Encode::encodingFinished(){
    this->close();
    qDebug()<<"ffmpeg process finished()";

}


void Encode::on_browseButton_clicked()
{
    fileStr = QFileDialog::getOpenFileName(this,tr("Open file"));
    QFileInfo file(fileStr);
    if(!fileStr.isEmpty()){
        ui->fileLabel->setText(file.fileName());
    }

}

QStringList Encode::getArguments(){
    QStringList arguments;

    QString dimensions = ui->widthEdit->text()+ "x" + ui->heightEdit->text();
    QString codec;
    int value=ui->comboBox_Codec->currentIndex();
    switch (value) {
    case 0:
        codec="libx264";
        break;
    case 1:
        codec="libx265";
    case 2:
        codec="libvpx";
        break;
    case 3:
        codec="libvpx-vp9";
        break;
    default:
        codec="libx264";
        break;
    }

    arguments<<"-y"<<"-f"<<"rawvideo"<<"-pix_fmt"<<"yuv420p"<<"-s:v"<<dimensions<<"-r"<<"25"<<"-i"<<fileStr<<"-c:v"<<codec<<"-f"<<"rawvideo"<<"output.264";
    return arguments;
}
/*
    QStringList arguments;
    QFileInfo file(fileStr);
    QString fileName = file.absoluteFilePath() + "_decoded.yuv";
    arguments<<"-i"<<fileStr<<"-c:v"<<"rawvideo"<<"-pix_fmt"<<"yuv420p"<<fileName;
    return arguments;
*/
