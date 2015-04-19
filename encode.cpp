#include "encode.h"
#include "ui_encode.h"
#include <QDebug>
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>

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
    if(fileStr.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString("Please select file."));
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
        return;
    }
    if(fileName.isEmpty())
    {
        QFileInfo file(fileStr);
        fileName=file.absolutePath()+"/";
    }
    ffmpeg=new QProcess(this);
    QString program ="ffmpeg.exe";      //program must be placed into same directory as VideoCodecs.exe
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
    qDebug()<<"ffmpeg process finished()";
    QMessageBox msgBox;
    msgBox.setText("Encoding has finished.");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
    this->close();
}


void Encode::on_browseButton_clicked()
{
    fileStr = QFileDialog::getOpenFileName(this,tr("Open file"),homeFolder,tr("rawvideo(*.yuv)"));
    QFileInfo file(fileStr);
    if(!fileStr.isEmpty()){
        ui->fileLabel->setText(file.fileName());
    }

}

QStringList Encode::getArguments(){
    QStringList arguments;
    QString codec;
    QString dimensions;
    QStringList quality;
    QString framerate;

    dimensions= ui->widthEdit->text()+ "x" + ui->heightEdit->text();
    QFileInfo file(fileStr);
    fileName.append(file.fileName());
    int value=ui->comboBox_Codec->currentIndex();
    switch (value) {
    case 0:
        codec="libx264";
        fileName.append("_"+QString::number(ui->cbrEdit->value())+"k" + "_encoded.h264");
        break;
    case 1:
        codec="libx265";
        fileName.append("_"+QString::number(ui->cbrEdit->value())+"k"+"_encoded.h265");
        break;
    case 2:
        codec="libvpx";
        fileName.append("_"+QString::number(ui->cbrEdit->value())+"k"+"_encoded_vp8.webm");
        break;
    case 3:
        codec="libvpx-vp9";
        fileName.append("_"+QString::number(ui->cbrEdit->value())+"k"+"_encoded_vp9.webm");
        break;
    default:
        codec="libx264";
        fileName.append("_"+QString::number(ui->cbrEdit->value())+"k"+"_encoded.h264");
        break;
    }
    if(ui->radioButton_CBR->isChecked())
    {
        QString value=QString::number(ui->cbrEdit->value())+"k";
        QString value2=QString::number(ui->cbrEdit->value()/2)+"k";
        quality.append("-b:v");
        quality.append(value);
        quality.append("-minrate");
        quality.append(value);
        quality.append("-maxrate");
        quality.append(value);
        quality.append("-bufsize");
        quality.append(value2);
    }
    else{
        quality.append("-crf");
        quality.append(QString::number(ui->crfEdit->value()));
    }

    framerate=QString::number(ui->fpsBox->value());

    if(codec=="libx264"||codec=="libx265")
    {
    arguments<<"-y"<<"-f"<<"rawvideo"<<"-pix_fmt"<<"yuv420p"<<"-s:v"<<dimensions<<"-r"<<framerate<<"-i"<<fileStr<<"-c:v"<<codec<<quality<<"-f"<<"rawvideo"<<fileName;
    }
    else
    {
       arguments<<"-y"<<"-f"<<"rawvideo"<<"-pix_fmt"<<"yuv420p"<<"-s:v"<<dimensions<<"-r"<<framerate<<"-i"<<fileStr<<"-c:v"<<codec<<quality<<"-c:a"<<"libavorbis"<<fileName;
    }

    return arguments;
}


void Encode::on_saveButton_clicked()
{
    fileName= QFileDialog::getExistingDirectory(this,tr("Save To"),homeFolder);
    if(!fileName.isEmpty())
    {
        fileName.append("/");
    }

}

void Encode::setHomeFolder(QString folder)
{
    homeFolder=folder;
}

void Encode::on_comboBox_Codec_currentIndexChanged(int index)
{
    switch (index){

    case 0:
        ui->saveFileLabel->setText("*_encoded.h264");
        break;
    case 1:
        ui->saveFileLabel->setText("*_encoded.h265");
        break;
    case 2:
        ui->saveFileLabel->setText("*_encoded_vp8.webm");
        break;
    case 3:
        ui->saveFileLabel->setText("*_encoded_vp9.webm");
        break;

    }
}
