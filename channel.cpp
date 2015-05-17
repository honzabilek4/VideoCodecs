#include "channel.h"
#include "ui_channel.h"
#include <QSettings>
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>

Channel::Channel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Channel)
{
    ui->setupUi(this);
    loadSettings();
}

Channel::~Channel()
{
    delete ui;
}

void Channel::loadSettings()
{
    QSettings settings;
    homeFolder=settings.value("workFolder","C:/").toString();
}

void Channel::on_browseButton_clicked()
{
    QString tempFile = QFileDialog::getOpenFileName(this,tr("Open file"),homeFolder);
    if(!tempFile.isEmpty())
    {
        fileStr=tempFile;
        QFileInfo file(fileStr);
        ui->openLabel->setText(file.fileName());
    }

}

void Channel::on_saveButton_clicked()
{
    QString folder;
    QString filter;
    if(saveFileStr.isEmpty())
    {
        if(!fileStr.isEmpty())
        {
            QFileInfo file(fileStr);
            QString suffix="." + file.suffix();
            folder=file.baseName() + "_noised" + suffix;
            filter="*"+suffix;
        }
        else
        {
            folder=homeFolder;
        }
    }
    else
    {
        folder=saveFileStr;
    }
    QString tempFileName = QFileDialog::getSaveFileName(this,tr("Save As"),folder,filter);
    if(!tempFileName.isEmpty())
    {
        saveFileStr=tempFileName;
        QFileInfo file(saveFileStr);
        ui->saveLabel->setText(file.fileName());
    }
}

void Channel::on_runButton_clicked()
{
    if(fileStr.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString("Please select file."));
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
        return;
    }
    if(saveFileStr.isEmpty())
    {
        QFileInfo file(fileStr);
        QString suffix="." + file.suffix();
        saveFileStr=file.absolutePath()+"/"+file.baseName() + "_noised" + suffix;
    }

    if(ui->radioButton_SER->isChecked())
    {
        this->hide();
        ffmpeg = new QProcess(this);
        QString program ="ffmpeg.exe";
        connect(ffmpeg,SIGNAL(started()),this,SLOT(processStarted()));
        connect(ffmpeg,SIGNAL(readyReadStandardError()),this,SLOT(readyReadStandardError()));
        connect(ffmpeg,SIGNAL(readyReadStandardOutput()),this,SLOT(readyReadStandardOutput()));
        connect(ffmpeg, SIGNAL(finished(int)), this, SLOT(processFinished()));
        ffmpeg->start(program,getArguments());

    }
    else
    {
        bc=new BerClass();
        double ber = (ui->doubleSpinBox_2->value())*(pow(10,ui->spinBox_2->value()));
        std::string open=fileStr.toStdString();
        std::string save=saveFileStr.toStdString();

        connect(&watcher,SIGNAL(finished()),this,SLOT(berFinished()));
        QFuture<int> future=QtConcurrent::run(bc,&BerClass::simulateBer,open.c_str(),save.c_str(),ber);
        watcher.setFuture(future);
        this->hide();

        emit updateText("BER started");

    }
}

QStringList Channel::getArguments()
{
    QStringList arguments;
    double ber=(ui->doubleSpinBox->value())*pow(10,ui->spinBox->value()*(-1));
    QString noise="noise=" + QString::number(ber,'g',99);
    arguments <<"-y"<<"-i"<<fileStr<<"-c:v"<<"copy"<<"-bsf"<<noise<<saveFileStr;

    return arguments;
}

void Channel::processStarted()
{

}

void Channel::readyReadStandardOutput()
{
    ffmpegOutput.append(ffmpeg->readAllStandardOutput());
    emit updateTextOutput(ffmpegOutput);
}

void Channel::readyReadStandardError()
{
    ffmpegOutput.append(ffmpeg->readAllStandardError());
    emit updateTextOutput(ffmpegOutput);
}

void Channel::processFinished()
{
    this->close();
}

void Channel::on_cancelButton_clicked()
{
    this->close();
}

void Channel::berFinished()
{
    int result=watcher.future().result();
    if(result<0)
    {
        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString(bc->error));
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
    }
    else
    {
       emit updateText("Output file created: " + saveFileStr);

    }
    emit updateText("BER finished");
    this->close();
}
