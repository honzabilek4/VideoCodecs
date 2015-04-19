#include "settings.h"
#include "ui_settings.h"
#include <QFileDialog>

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_toolButton_clicked()
{
    folderName=QFileDialog::getExistingDirectory(this,tr("Select folder"),"C:/",QFileDialog::ShowDirsOnly);
    ui->lineEdit->setText(folderName);
}

void Settings::on_toolButton_2_clicked()
{
    testFolderName=QFileDialog::getExistingDirectory(this,tr("Select folder"),"C:/",QFileDialog::ShowDirsOnly);
    ui->lineEdit_2->setText(testFolderName);
}

void Settings::setFolderName(QString folder)
{
    folderName=folder;
    ui->lineEdit->setText(folderName);
}
void Settings::setTestFolderName(QString folder)
{
    testFolderName=folder;
    ui->lineEdit_2->setText(testFolderName);
}

void Settings::on_buttonBox_accepted()
{
    emit setFolders(folderName,testFolderName);
}


