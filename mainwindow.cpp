#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "encode.h"
#include "decode.h"
#include "test.h"
#include "settings.h"
#include <QLabel>
#include <QApplication>
#include <QScrollBar>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QSettings>
#include <graph.h>



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
    connect(e,SIGNAL(updateTextOutput(const QString)),this,SLOT(setStandardOutputText(const QString)));
    connect(e,SIGNAL(toggleUi()),this,SLOT(toggleUi()));
    e->exec();
}

void MainWindow::on_actionDecode_triggered()
{
    Decode* d = new Decode(this);
    connect(d,SIGNAL(updateTextOutput(const QString)),this,SLOT(setStandardOutputText(const QString)));
    connect(d,SIGNAL(toggleUi()),this,SLOT(toggleUi()));

    d->exec();
}

void MainWindow::on_actionTest_triggered()
{
    Test* t = new Test(this);

    connect(t,SIGNAL(psnrReady(QList<double>)),this,SLOT(setPsnr(QList<double>)));
    connect(t,SIGNAL(ssimReady(QList<double>)),this,SLOT(setSsim(QList<double>)));
    connect(t,SIGNAL(msvdReady(QList<double>)),this,SLOT(setMsvd(QList<double>)));
    connect(t,SIGNAL(updateOutput(const QString)),this,SLOT(setOutputText(const QString)));

    psnrRes.clear();
    ssimRes.clear();
    msvdRes.clear();

    avgPsnr=NULL;
    avgSsim=NULL;
    avgMsvd=NULL;

    ui->label_7->setText("-");
    ui->label_8->setText("-");
    ui->label_9->setText("-");
    ui->label_10->setText("-");
    ui->label_11->setText("-");
    ui->label_12->setText("-");
    ui->label_13->setText("-");
    ui->label_14->setText("-");
    ui->label_15->setText("-");

    t->exec();
}

void MainWindow::setOutputText(const QString text)
{
    ui->textOutput->append(text);

}
void MainWindow::setStandardOutputText(const QString text)
{
    ui->textOutput->setText(text);
    ui->textOutput->verticalScrollBar()->setSliderPosition(
               ui->textOutput->verticalScrollBar()->maximum());
}

void MainWindow::setPsnr(QList<double> psnrList)
{
    avgPsnr=getAverage(psnrList);
    ui->label_7->setText(QString::number(avgPsnr));
    double maxPsnr=getMax(psnrList);
    ui->label_10->setText(QString::number(maxPsnr));
    double minPsnr=getMin(psnrList);
    ui->label_13->setText(QString::number(minPsnr));

    psnrRes=psnrList;
    psnrRes.prepend(avgPsnr);
    ui->textOutput->append("PSNR finished");


}
void MainWindow::setSsim(QList<double> ssimList)
{
    avgSsim=getAverage(ssimList);
    ui->label_8->setText(QString::number(avgSsim));
    double maxSsim=getMax(ssimList);
    ui->label_11->setText(QString::number(maxSsim));
    double minSsim=getMin(ssimList);
    ui->label_14->setText(QString::number(minSsim));

    ssimRes=ssimList;
    ssimRes.prepend(avgSsim);

    ui->textOutput->append("SSIM finished");
}

void MainWindow::setMsvd(QList<double> msvdList)
{
    avgMsvd=getAverage(msvdList);
    ui->label_9->setText(QString::number(avgMsvd));
    double maxMsvd=getMax(msvdList);
    ui->label_15->setText(QString::number(maxMsvd));
    double minMsvd=getMin(msvdList);
    ui->label_12->setText(QString::number(minMsvd));

    msvdRes=msvdList;
    msvdRes.prepend(avgMsvd);

    ui->textOutput->append("MSVD finished");
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

void MainWindow::on_actionExport_CSV_triggered()
{
    if(psnrRes.isEmpty()&&ssimRes.isEmpty()&&msvdRes.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("No results.");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
    }
    else
    {
        QString exportFileName=QFileDialog::getSaveFileName(this,tr("Export CSV"),"C:/",tr("Comma Separated Value(*.csv)"));
        QFile file(exportFileName);

        int length=psnrRes.length();
        if(psnrRes.isEmpty())
            length=ssimRes.length();
        if(ssimRes.isEmpty())
            length=msvdRes.length();
        if(file.open(QIODevice::WriteOnly|QIODevice::Text))
        {
            QTextStream stream(&file);
            QString line;

            stream<<"frame;PSNR;SSIM;MSVD"<<endl;
            line="avg;";
            line.append( avgPsnr==NULL?"-":(QString::number(avgPsnr))+";");
            line.append(avgSsim==NULL?"-":(QString::number(avgSsim))+";");
            line.append(avgMsvd==NULL?"-":(QString::number(avgMsvd))+";");
            stream<<line<<endl;

            for(int i=1;i<length;i++)
            {
                line=QString::number(i)+": ";
                psnrRes.isEmpty()?line.append("-"):line.append(QString::number(psnrRes.value(i)));
                line.append(";");
                ssimRes.isEmpty()?line.append("-"):line.append(QString::number(ssimRes.value(i)));
                line.append(";");
                msvdRes.isEmpty()?line.append("-"):line.append(QString::number(msvdRes.value(i)));
                line.append(";");
                stream<<line<<endl;
                line.clear();

            }

        }
        file.close();
        ui->textOutput->append("File "+ exportFileName +" was created");
    }
}

void MainWindow::on_actionGeneral_settings_triggered()
{
    Settings* s = new Settings(this);
    s->exec();
}

void MainWindow::toggleUi()
{
   ui->menuBar->setEnabled(!ui->menuBar->isEnabled());
   ui->mainToolBar->setEnabled(!ui->mainToolBar->isEnabled());
}

void MainWindow::on_actionShow_Graph_triggered()
{
  Graph* g  = new Graph(this);

  g->show();
}
