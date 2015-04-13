#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "encode.h"
#include "decode.h"
#include "test.h"
#include <QLabel>
#include <QApplication>
#include <QList>
#include <QScrollBar>


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


void MainWindow::setOutputText(const QString text)
{
    ui->textOutput->setText(text);
    ui->textOutput->verticalScrollBar()->setSliderPosition(
                ui->textOutput->verticalScrollBar()->maximum());
}



void MainWindow::on_actionEncode_triggered()
{
    Encode* e= new Encode(this);
    e->show();

    connect(e,SIGNAL(updateTextOutput(const QString)),this,SLOT(setOutputText(const QString)));

}

void MainWindow::on_actionDecode_triggered()
{
    Decode* d = new Decode(this);
    d->show();
    connect(d,SIGNAL(updateTextOutput(const QString)),this,SLOT(setOutputText(const QString)));
}

void MainWindow::on_actionTest_triggered()
{
    Test* t = new Test(this);
    t->show();
}
