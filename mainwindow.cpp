#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QLabel>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}



void MainWindow::on_openFile1_clicked()
{
    QUrl file = QFileDialog::getOpenFileUrl(this,tr("Open file"));
    ui->statusBar->showMessage(file.toString());
    ui->label->setText(file.fileName());
}

void MainWindow::on_openFile2_clicked()
{
    QUrl file = QFileDialog::getOpenFileUrl(this,tr("Open file"));
    ui->statusBar->showMessage(file.toString());
    ui->label_2->setText(file.fileName());
}

void MainWindow::on_psnrButton_clicked()
{

}
