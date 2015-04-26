#include "encode.h"
#include "ui_encode.h"
#include <QDebug>
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>
#include <QSettings>

Encode::Encode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Encode)
{
    ui->setupUi(this);
    loadSettings();
}

Encode::~Encode()
{
    delete ui;
}


void Encode::loadSettings()
{
    QSettings settings;
    homeFolder=settings.value("workFolder","C:/").toString();
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
    this->hide();
    emit toggleUi();
    ffmpeg=new QProcess(this);
    program ="ffmpeg.exe";      //program must be placed into same directory as VideoCodecs.exe
    connect(ffmpeg, SIGNAL(started()),this, SLOT(processStarted()));
    connect(ffmpeg,SIGNAL(readyReadStandardOutput()),this,SLOT(readyReadStandardOutput()));
    connect(ffmpeg,SIGNAL(readyReadStandardError()),this,SLOT(readyReadStandardError()));


    if(!ui->methodBox->isChecked())
    {
        connect(ffmpeg, SIGNAL(finished(int)), this, SLOT(encodingFinished()));
        ffmpeg->start(program,getArguments(0));
    }
    else
    {
        connect(ffmpeg,SIGNAL(finished(int)),this,SLOT(firstPassFinished()));
        ffmpeg->start(program,getArguments(1));
    }


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
    emit toggleUi();
    this->close();
}

void Encode::firstPassFinished(){
    disconnect(ffmpeg, SIGNAL(finished(int)), this, SLOT(firstPassFinished()));
    connect(ffmpeg, SIGNAL(finished(int)), this, SLOT(encodingFinished()));

    ffmpeg->start(program,getArguments(2));
}

void Encode::on_browseButton_clicked()
{
    fileStr = QFileDialog::getOpenFileName(this,tr("Open file"),homeFolder,tr("rawvideo(*.yuv)"));
    QFileInfo file(fileStr);
    if(!fileStr.isEmpty()){
        ui->fileLabel->setText(file.fileName());
    }

}

QStringList Encode::getArguments(int pass){

    if(pass<2)

    {
        dimensions= ui->widthEdit->text()+ "x" + ui->heightEdit->text();
        int value=ui->comboBox_Codec->currentIndex();
        switch (value) {
        case 0:
            codec="libx264";
            break;
        case 1:
            codec="libx265";
            break;
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
        if(saveFileName.isEmpty())
        {
            QFileInfo file(fileStr);
            saveFileName=file.absoluteFilePath();
            switch(value)
            {
            case 0:
                saveFileName.append("_encoded.h264");
                break;
            case 1:
                saveFileName.append("_encoded.h265");
                break;
            case 2:
                saveFileName.append("_encoded_vp8.webm");
                break;
            case 3:
                saveFileName.append("_encoded_vp9.webm");
                break;
            }

        }

        if(ui->radioButton_CBR->isChecked())
        {
            QString value=QString::number(ui->cbrEdit->value())+"k";
            QString value2=QString::number(ui->cbrEdit->value()*2)+"k";
            quality.append("-b:v");
            quality.append(value);
            quality.append("-minrate");
            quality.append(value);
            quality.append("-maxrate");
            quality.append(value);
            quality.append("-bufsize");
            quality.append(value2);
        }
        else if(ui->radioButton_AVG->isChecked())
        {
            quality.append("-b:v");
            QString value=QString::number(ui->avgBox->value())+"k";
            quality.append(value);
            quality.append("-minrate");
            value=QString::number(ui->minBox->value())+"k";
            quality.append(value);
            quality.append("-maxrate");
            value=QString::number(ui->maxBox->value())+"k";
            quality.append(value);
            quality.append("-bufsize");
            value=QString::number(ui->avgBox->value()*2)+"k";
            quality.append(value);
        }
        else{
            quality.append("-crf");
            quality.append(QString::number(ui->crfEdit->value()));
        }

        framerate=QString::number(ui->fpsBox->value());

        if(ui->presetBox->isEnabled())
        {
            ui->presetBox->currentIndex()==3 ? preset="medium" : preset=ui->presetBox->currentText();

        }
    }

    switch(pass) {

    case 0:
        (codec=="libx264"||codec=="libx265")? arguments<<"-y"<<"-f"<<"rawvideo"<<"-pix_fmt"<<"yuv420p"<<"-s:v"<<dimensions<<"-r"<<framerate<<"-i"<<fileStr<<"-c:v"<<codec<<"-preset"<<preset<<quality<<"-f"<<"rawvideo"<<saveFileName\
                                                         : arguments<<"-y"<<"-f"<<"rawvideo"<<"-pix_fmt"<<"yuv420p"<<"-s:v"<<dimensions<<"-r"<<framerate<<"-i"<<fileStr<<"-c:v"<<codec<<quality<<saveFileName;
        break;
    case 1:
        (codec=="libx264"||codec=="libx265")? arguments<<"-y"<<"-f"<<"rawvideo"<<"-pix_fmt"<<"yuv420p"<<"-s:v"<<dimensions<<"-r"<<framerate<<"-i"<<fileStr<<"-c:v"<<codec<<"-preset"<<preset<<quality<<"-pass"<<"1"<<"-f"<<"rawvideo"<<"NUL"\
                                                         : arguments<<"-y"<<"-f"<<"rawvideo"<<"-pix_fmt"<<"yuv420p"<<"-s:v"<<dimensions<<"-r"<<framerate<<"-i"<<fileStr<<"-c:v"<<codec<<quality<<"-pass"<<"1"<<saveFileName;
        break;
    case 2:
        arguments.clear();
        (codec=="libx264"||codec=="libx265")? arguments<<"-y"<<"-f"<<"rawvideo"<<"-pix_fmt"<<"yuv420p"<<"-s:v"<<dimensions<<"-r"<<framerate<<"-i"<<fileStr<<"-c:v"<<codec<<"-preset"<<preset<<quality<<"-pass"<<"2"<<"-f"<<"rawvideo"<<saveFileName\
                                                         : arguments<<"-y"<<"-f"<<"rawvideo"<<"-pix_fmt"<<"yuv420p"<<"-s:v"<<dimensions<<"-r"<<framerate<<"-i"<<fileStr<<"-c:v"<<codec<<quality<<"-pass"<<"2"<<saveFileName;
        break;


    }
    return arguments;
}


void Encode::on_saveButton_clicked()
{
    QString folder;
    QString filter;

    switch (ui->comboBox_Codec->currentIndex())
    {
    case 0:
        filter="H.264 video(*.h264)";
        break;
    case 1:
        filter="H.265 video(*.h265)";
        break;
    case 2:
        filter="WEBM video(*.webm)";
        break;
    case 3:
        filter="WEBM video(*.webm)";
        break;
    }

    if(saveFileName.isEmpty())
    {
        if(!fileStr.isEmpty())
        {
            switch (ui->comboBox_Codec->currentIndex())
            {
            case 0:
                folder=fileStr + "_encoded.h264";
                break;
            case 1:
                folder=fileStr + "_encoded.h265";
                break;
            case 2:
                folder=fileStr + "_encoded_vp8.webm";
                break;
            case 3:
                folder=fileStr + "_encoded_vp9.webm";
                break;
            }
        }
        else
        {
            folder=homeFolder;
        }
    }
    else
    {
        folder=saveFileName;
    }
    saveFileName = QFileDialog::getSaveFileName(this,tr("Save To"),folder,filter);
    if(!saveFileName.isEmpty())
    {
        QFileInfo file(saveFileName);
        ui->saveFileLabel->setText(file.fileName());
    }

}

void Encode::on_comboBox_Codec_currentIndexChanged(int index)
{
    switch (index){

    case 0:
        ui->saveFileLabel->setText("*_encoded.h264");
        ui->presetBox->setEnabled(true);
        saveFileName.clear();
        break;
    case 1:
        ui->saveFileLabel->setText("*_encoded.h265");
        ui->presetBox->setEnabled(true);
        saveFileName.clear();
        break;
    case 2:
        ui->saveFileLabel->setText("*_encoded_vp8.webm");
        ui->presetBox->setEnabled(false);
        saveFileName.clear();
        break;
    case 3:
        ui->saveFileLabel->setText("*_encoded_vp9.webm");
        ui->presetBox->setEnabled(false);
        saveFileName.clear();
        break;

    }
}

