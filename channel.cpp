#include "channel.h"
#include "ui_channel.h"
#include <QSettings>
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>

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

    if(saveFileStr.isEmpty())
    {
        if(!fileStr.isEmpty())
        {
            QFileInfo file(fileStr);
            QString suffix="." + file.suffix();
            folder=file.baseName() + "_noised" + suffix;
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
    QString tempFileName = QFileDialog::getSaveFileName(this,tr("Save As"),folder);
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
        saveFileStr=file.baseName() + "_noised" + suffix;
    }

    ffmpeg = new QProcess(this);
    QString program ="ffmpeg.exe";
    connect(ffmpeg,SIGNAL(started()),this,SLOT(processStarted()));
    connect(ffmpeg,SIGNAL(readyReadStandardError()),this,SLOT(readyReadStandardError()));
    connect(ffmpeg, SIGNAL(finished(int)), this, SLOT(processFinished()));
    ffmpeg->start(program,getArguments());
    this->hide();
}

QStringList Channel::getArguments()
{
    QStringList arguments;
    double ber=1*pow(10,ui->spinBox->value()*(-1));
    QString berStr;
    berStr=QString::number(ber,'g',99);
    QString noise="noise=" + berStr;
    arguments <<"-y"<<"-i"<<fileStr<<"-c:v"<<"copy"<<"-bsf"<<noise<<saveFileStr;

    return arguments;
}

void Channel::processStarted()
{

}

void Channel::readyReadStandardError()
{

}

void Channel::processFinished()
{
    this->close();
}

void Channel::on_cancelButton_clicked()
{
    this->close();
}
