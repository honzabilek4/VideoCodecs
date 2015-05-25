#include "encode.h"
#include "ui_encode.h"
#include "y4mparser.h"
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
    ui->widthEdit->setText(settings.value("encode/width","").toString());
    ui->heightEdit->setText(settings.value("encode/height","").toString());
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
    if(ui->radioButton_AVG->isEnabled()&& ((ui->avgBox->value() < ui->minBox->value())||(ui->avgBox->value()>ui->maxBox->value())))
    {
        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString("Wrong bitrate values."));
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


    if(ui->methodBox->isChecked()&&ui->methodBox->isEnabled())
    {
        connect(ffmpeg,SIGNAL(finished(int)),this,SLOT(firstPassFinished()));
        ffmpeg->start(program,getArguments(1));
    }
    else
    {
        connect(ffmpeg, SIGNAL(finished(int)), this, SLOT(encodingFinished()));
        ffmpeg->start(program,getArguments(0));
    }

    QSettings settings;
    settings.setValue("encode/width",ui->widthEdit->text());
    settings.setValue("encode/height",ui->heightEdit->text());

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
    QString tempFile = QFileDialog::getOpenFileName(this,tr("Open file"),homeFolder,tr("rawvideo(*.yuv;*.y4m)"));
    if(!tempFile.isEmpty())
    {
        fileStr=tempFile;
        QFileInfo file(fileStr);
        ui->fileLabel->setText(file.fileName());
        if(file.suffix()=="y4m")
        {
            Y4mParser parser;
            ui->widthEdit->setText(QString::number(parser.getWidth(fileStr)));
            ui->heightEdit->setText(QString::number(parser.getHeight(fileStr)));
            ui->fpsBox->setValue(parser.getFrameRate(fileStr));
        }

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
        case 4:
            codec="libschroedinger";
            break;
        case 5:
            codec="flv";
            break;
        case 6:
            codec="wmv2";
            break;
        }

        framerate=(QString::number(ui->fpsBox->value()));


        if(saveFileName.isEmpty())
        {
            QFileInfo file(fileStr);
            saveFileName=file.absoluteFilePath();
            switch(value)
            {
            case 0:
                saveFileName.append("_encoded_h264.mp4");
                break;
            case 1:
                saveFileName.append("_encoded_h265.mp4");
                break;
            case 2:
                saveFileName.append("_encoded_vp8.webm");
                break;
            case 3:
                saveFileName.append("_encoded_vp9.webm");
                break;
            case 4:
                saveFileName.append("_encoded_dirac.mkv");
                break;
            case 5:
                saveFileName.append("_encoded_flash.flv");
                break;
            case 6:
                saveFileName.append("_encoded_wmv8.wmv");
                break;

            }

        }

        if(ui->radioButton_CBR->isChecked())
        {
            QString value=QString::number(ui->cbrEdit->value())+"k";
            QString value2=QString::number(ui->cbrEdit->value()*2)+"k";


            quality.append("-minrate");
            quality.append(value);
            quality.append("-maxrate");
            quality.append(value);
            quality.append("-b:v");
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
            if(codec=="libvpx"||codec=="libvpx-vp9")
            {
                quality.append("-b:v");
                quality.append("0");
            }
            quality.append("-crf");
            quality.append(QString::number(ui->crfEdit->value()));
        }

        if(ui->speedBox->isEnabled())
        {
            quality.append("-threads");
            quality.append("4");
            quality.append("-speed");
            quality.append(QString::number(ui->speedBox->currentIndex()));

        }


        if(codec=="flv"||codec=="wmv2")
        {
            quality.append("-qmax");
            quality.append("255");
        }

        if(ui->testBox->isChecked())
        {
            quality.append("-frames");
            quality.append(QString::number(ui->testFramesBox->value()));
        }
        if(codec=="libvpx-vp9")
        {
            outfiletype.append("webm");
        }
        else
        {
            outfiletype.append("rawvideo");
        }

        if(ui->profileBox->isEnabled() && (ui->profileBox->currentIndex()!=0))
        {
            presets.append("-profile:v");
            presets.append(ui->profileBox->currentText().toLower());
            if(ui->levelBox->isEnabled())
            {
                presets.append("-level");
                presets.append(ui->levelBox->currentText());
            }
        }

        if(ui->presetBox->isEnabled())
        {
            presets.append("-preset");
            ui->presetBox->currentIndex()==3 ? presets.append("medium") : presets.append(ui->presetBox->currentText());

        }

    }

    QFileInfo file(fileStr);

    if(file.suffix()=="y4m")
    {
        switch(pass) {

        case 0:
            (codec=="libx264"||codec=="libx265")? arguments<<"-y"<<"-i"<<fileStr<<"-c:v"<<codec<<presets<<quality<<saveFileName\
                                                             : arguments<<"-y"<<"-i"<<fileStr<<"-c:v"<<codec<<quality<<saveFileName;
            break;
        case 1:
            (codec=="libx264"||codec=="libx265")? arguments<<"-y"<<"-s:v"<<"-i"<<fileStr<<"-c:v"<<codec<<presets<<quality<<"-pass"<<"1"<<"-f"<<outfiletype<<"NUL"\
                                                             : arguments<<"-y"<<"-i"<<fileStr<<"-c:v"<<codec<<quality<<"-pass"<<"1"<<"-f"<<outfiletype<<"NUL";
            break;
        case 2:
            arguments.clear();
            (codec=="libx264"||codec=="libx265")? arguments<<"-y"<<"-s:v"<<"-i"<<fileStr<<"-c:v"<<codec<<presets<<quality<<"-pass"<<"2"<<saveFileName\
                                                             : arguments<<"-y"<<"-i"<<fileStr<<"-c:v"<<codec<<quality<<"-pass"<<"2"<<saveFileName;
            break;


        }
    }

    else{

        switch(pass) {

        case 0:
            (codec=="libx264"||codec=="libx265")? arguments<<"-y"<<"-f"<<"rawvideo"<<"-pix_fmt"<<"yuv420p"<<"-s:v"<<dimensions<<"-r"<<framerate<<"-i"<<fileStr<<"-c:v"<<codec<<presets<<quality<<saveFileName\
                                                             : arguments<<"-y"<<"-f"<<"rawvideo"<<"-pix_fmt"<<"yuv420p"<<"-s:v"<<dimensions<<"-r"<<framerate<<"-i"<<fileStr<<"-c:v"<<codec<<quality<<saveFileName;
            break;
        case 1:
            (codec=="libx264"||codec=="libx265")? arguments<<"-y"<<"-f"<<"rawvideo"<<"-pix_fmt"<<"yuv420p"<<"-s:v"<<dimensions<<"-r"<<framerate<<"-i"<<fileStr<<"-c:v"<<codec<<presets<<quality<<"-pass"<<"1"<<"-f"<<outfiletype<<"NUL"\
                                                             : arguments<<"-y"<<"-f"<<"rawvideo"<<"-pix_fmt"<<"yuv420p"<<"-s:v"<<dimensions<<"-r"<<framerate<<"-i"<<fileStr<<"-c:v"<<codec<<quality<<"-pass"<<"1"<<"-f"<<outfiletype<<"NUL";
            break;
        case 2:
            arguments.clear();
            (codec=="libx264"||codec=="libx265")? arguments<<"-y"<<"-f"<<"rawvideo"<<"-pix_fmt"<<"yuv420p"<<"-s:v"<<dimensions<<"-r"<<framerate<<"-i"<<fileStr<<"-c:v"<<codec<<presets<<quality<<"-pass"<<"2"<<saveFileName\
                                                             : arguments<<"-y"<<"-f"<<"rawvideo"<<"-pix_fmt"<<"yuv420p"<<"-s:v"<<dimensions<<"-r"<<framerate<<"-i"<<fileStr<<"-c:v"<<codec<<quality<<"-pass"<<"2"<<saveFileName;
            break;

        }
    }

    qDebug()<<arguments;
    return arguments;
}


void Encode::on_saveButton_clicked()
{
    QString folder;
    QString filter;

    switch (ui->comboBox_Codec->currentIndex())
    {
    case 0:
        filter="MP4 video(*.mp4)";
        break;
    case 1:
        filter="MP4 video(*.mp4)";
        break;
    case 2:
        filter="WEBM video(*.webm)";
        break;
    case 3:
        filter="WEBM video(*.webm)";
        break;
    case 4:
        filter="MATROSKA video(*.mkv)";
        break;
    case 5:
        filter="Flash Video(*.flv)";
        break;
    case 6:
        filter="Windows Media Video(*.wmv)";
        break;
    }

    if(saveFileName.isEmpty())
    {
        if(!fileStr.isEmpty())
        {
            switch (ui->comboBox_Codec->currentIndex())
            {
            case 0:
                folder=fileStr + "_encoded_h264.mp4";
                break;
            case 1:
                folder=fileStr + "_encoded_h265.mp4";
                break;
            case 2:
                folder=fileStr + "_encoded_vp8.webm";
                break;
            case 3:
                folder=fileStr + "_encoded_vp9.webm";
                break;
            case 4:
                folder=fileStr + "_encoded_dirac.mkv";
                break;
            case 5:
                folder=fileStr + "_encoded_flash.flv";
                break;
            case 6:
                folder=fileStr + "_encoded_wmv8.wmv";
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
    QString tempFileName = QFileDialog::getSaveFileName(this,tr("Save As"),folder,filter);
    if(!tempFileName.isEmpty())
    {
        saveFileName=tempFileName;
        QFileInfo file(saveFileName);
        ui->saveFileLabel->setText(file.fileName());
    }

}

void Encode::on_comboBox_Codec_currentIndexChanged(int index)
{
    switch (index){

    case 0:
        ui->saveFileLabel->setText("*_encoded_h264.mp4");
        ui->presetBox->setEnabled(true);
        ui->profileBox->setEnabled(true);
        saveFileName.clear();
        ui->radioButton_CRF->setEnabled(true);
        ui->crfEdit->setMaximum(51);
        ui->speedBox->setEnabled(false);
        break;
    case 1:
        ui->saveFileLabel->setText("*_encoded_h265.mp4");
        ui->presetBox->setEnabled(true);
        ui->profileBox->setEnabled(false);
        saveFileName.clear();
        ui->radioButton_CRF->setEnabled(true);
        ui->crfEdit->setMaximum(51);
        ui->speedBox->setEnabled(false);
        break;
    case 2:
        ui->saveFileLabel->setText("*_encoded_vp8.webm");
        ui->presetBox->setEnabled(false);
        ui->profileBox->setEnabled(false);
        saveFileName.clear();
        ui->radioButton_CRF->setEnabled(true);
        ui->crfEdit->setMaximum(64);
        ui->speedBox->setEnabled(false);
        break;
    case 3:
        ui->saveFileLabel->setText("*_encoded_vp9.webm");
        ui->presetBox->setEnabled(false);
        ui->profileBox->setEnabled(false);
        saveFileName.clear();
        ui->radioButton_CRF->setEnabled(true);
        ui->crfEdit->setMaximum(64);
        ui->speedBox->setEnabled(true);
        break;
    case 4:
        ui->saveFileLabel->setText("*_encoded_dirac.mkv");
        ui->presetBox->setEnabled(false);
        ui->profileBox->setEnabled(false);
        saveFileName.clear();
        ui->radioButton_CRF->setEnabled(false);
        ui->speedBox->setEnabled(false);
        if(ui->radioButton_CRF->isChecked())
        {
            ui->radioButton_CBR->setChecked(true);
        }
        break;

    case 5:
        ui->saveFileLabel->setText("*_encoded_flash.flv");
        ui->presetBox->setEnabled(false);
        ui->profileBox->setEnabled(false);
        saveFileName.clear();
        ui->radioButton_CRF->setEnabled(false);
        ui->speedBox->setEnabled(false);
        if(ui->radioButton_CRF->isChecked())
        {
            ui->radioButton_CBR->setChecked(true);
        }
        break;
    case 6:
        ui->saveFileLabel->setText("*_encoded_wmv8.wmv");
        ui->presetBox->setEnabled(false);
        ui->profileBox->setEnabled(false);
        saveFileName.clear();
        ui->radioButton_CRF->setEnabled(false);
        ui->speedBox->setEnabled(false);
        if(ui->radioButton_CRF->isChecked())
        {
            ui->radioButton_CBR->setChecked(true);
        }
        break;

    }
}


void Encode::on_profileBox_currentIndexChanged(int index)
{
    if(index==0)
    {
        ui->levelBox->setEnabled(false);
        ui->presetBox->setEnabled(true);
    }
    else
    {
        ui->levelBox->setEnabled(true);
        ui->presetBox->setEnabled(false);
    }

}
