#include "settings.h"
#include "ui_settings.h"
#include <QFileDialog>
#include <QSettings>

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    loadSettings();
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_toolButton_clicked()
{
    QString file=QFileDialog::getExistingDirectory(this,tr("Select folder"),"C:/",QFileDialog::ShowDirsOnly);
    if(!file.isEmpty())
    {
        folderName=file;
        ui->lineEdit->setText(folderName);
    }
}

void Settings::on_toolButton_2_clicked()
{
    QString file=QFileDialog::getExistingDirectory(this,tr("Select folder"),"C:/",QFileDialog::ShowDirsOnly);
    if(!file.isEmpty())
    {
    testFolderName=file;
    ui->lineEdit_2->setText(testFolderName);
    }
}


void Settings::on_buttonBox_accepted()
{
    QSettings settings;
    settings.setValue("workFolder",folderName);
    settings.setValue("testFolder",testFolderName);
}

void Settings::loadSettings()
{
    QSettings settings;
    folderName=settings.value("workFolder","C:/").toString();
    ui->lineEdit->setText(folderName);
    testFolderName=settings.value("testFolder","C:/").toString();
    ui->lineEdit_2->setText(testFolderName);
}


