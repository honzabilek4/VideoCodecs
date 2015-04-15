#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "encode.h"
#include "decode.h"
#include "test.h"
#include <QLabel>
#include <QApplication>
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
    connect(t,SIGNAL(psnrReady(QList<double>)),this,SLOT(setPsnr(QList<double>)));
    connect(t,SIGNAL(ssimReady(QList<double>)),this,SLOT(setSsim(QList<double>)));
    connect(t,SIGNAL(msvdReady(QList<double>)),this,SLOT(setMsvd(QList<double>)));
}

void MainWindow::setOutputText(const QString text)
{
    ui->textOutput->setText(text);
    ui->textOutput->verticalScrollBar()->setSliderPosition(
                ui->textOutput->verticalScrollBar()->maximum());
}

void MainWindow::setPsnr(QList<double> psnrList)
{
    double avgPsnr=getAverage(psnrList);
    ui->label_7->setText(QString::number(avgPsnr));
    double maxPsnr=getMax(psnrList);
    ui->label_10->setText(QString::number(maxPsnr));
    double minPsnr=getMin(psnrList);
    ui->label_13->setText(QString::number(minPsnr));


}
void MainWindow::setSsim(QList<double> ssimList)
{
    double avgSsim=getAverage(ssimList);
    ui->label_8->setText(QString::number(avgSsim));
    double maxSsim=getMax(ssimList);
    ui->label_11->setText(QString::number(maxSsim));
    double minSsim=getMin(ssimList);
    ui->label_14->setText(QString::number(minSsim));
}

void MainWindow::setMsvd(QList<double> msvdList)
{
    double avgMsvd=getAverage(msvdList);
    ui->label_9->setText(QString::number(avgMsvd));
    double maxMsvd=getMax(msvdList);
    ui->label_15->setText(QString::number(maxMsvd));
    double minMsvd=getMin(msvdList);
    ui->label_12->setText(QString::number(minMsvd));
}

double MainWindow::getAverage(QList<double> list)
{
    double avg=0;
    foreach (double d, list)
    {
        avg+=d;
    }
    avg=avg/list.length();
    return avg;
}

double MainWindow::getMax(QList<double> list)
{

    double max = *std::max_element(list.begin(), list.end());
    return max;
}
double MainWindow::getMin(QList<double> list)
{
    double min = *std::min_element(list.begin(), list.end());
    return min;
}
