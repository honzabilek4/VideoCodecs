#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "encode.h"
#include "decode.h"
#include "test.h"
#include "settings.h"
#include "channel.h"
#include <QLabel>
#include <QApplication>
#include <QScrollBar>
#include <QFileDialog>
#include <QFileInfo>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QSettings>
#include <graph.h>

//#include <vld.h> //Visual Studio only



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFileInfo ffmpegFile("ffmpeg.exe");
    if(!ffmpegFile.exists())
    {
        QMessageBox msgBox;
        msgBox.setText("Cannot start program because ffmpeg.exe is missing.");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
        exit(-1);
    }
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

    connect(t,SIGNAL(psnrReady(QVector<double>)),this,SLOT(setPsnr(QVector<double>)));
    connect(t,SIGNAL(ssimReady(QVector<double>)),this,SLOT(setSsim(QVector<double>)));
    connect(t,SIGNAL(msvdReady(QVector<double>)),this,SLOT(setMsvd(QVector<double>)));
    connect(t,SIGNAL(updateOutput(const QString)),this,SLOT(setOutputText(const QString)));
    connect(t,SIGNAL(resetResults()),this,SLOT(resetResults()));
    connect(t,SIGNAL(exportResults(QString)),this,SLOT(exportCSV(QString)));

    t->exec();
}

void MainWindow::resetResults()
{
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

void MainWindow::setPsnr(QVector<double> psnrVector)
{
    avgPsnr=getAverage(psnrVector);
    ui->label_7->setText(QString::number(avgPsnr));
    double minPsnr=getMin(psnrVector);
    ui->label_10->setText(QString::number(minPsnr));
    double maxPsnr=getMax(psnrVector);
    ui->label_13->setText(QString::number(maxPsnr));

    psnrRes=psnrVector;
    psnrRes.prepend(avgPsnr);
    ui->textOutput->append("PSNR finished");


}
void MainWindow::setSsim(QVector<double> ssimVector)
{
    avgSsim=getAverage(ssimVector);
    ui->label_8->setText(QString::number(avgSsim));
    double minSsim=getMin(ssimVector);
    ui->label_11->setText(QString::number(minSsim));
    double maxSsim=getMax(ssimVector);
    ui->label_14->setText(QString::number(maxSsim));

    ssimRes=ssimVector;
    ssimRes.prepend(avgSsim);

    ui->textOutput->append("SSIM finished");
}

void MainWindow::setMsvd(QVector<double> msvdVector)
{
    avgMsvd=getAverage(msvdVector);
    ui->label_9->setText(QString::number(avgMsvd));
    double maxMsvd=getMax(msvdVector);
    ui->label_15->setText(QString::number(maxMsvd));
    double minMsvd=getMin(msvdVector);
    ui->label_12->setText(QString::number(minMsvd));

    msvdRes=msvdVector;
    msvdRes.prepend(avgMsvd);

    ui->textOutput->append("MSVD finished");
}

double MainWindow::getAverage(QVector<double> vector)
{
    double avg=0;
    foreach (double d, vector)
    {
        avg+=d;
    }
    avg=avg/vector.length();
    return avg;
}

double MainWindow::getMax(QVector<double> vector)
{

    double max = *std::max_element(vector.begin(), vector.end());
    return max;
}
double MainWindow::getMin(QVector<double> vector)
{
    double min = *std::min_element(vector.begin(), vector.end());
    return min;
}

void MainWindow::on_actionExport_CSV_triggered()
{
    if(psnrRes.isEmpty()&&ssimRes.isEmpty()&&msvdRes.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("There are no results.");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
    }
    else
    {
        QString exportFileName=QFileDialog::getSaveFileName(this,tr("Export CSV"),"C:/",tr("Comma Separated Value(*.csv)"));

        exportCSV(exportFileName);

    }
}

void MainWindow::exportCSV(QString exportFileName)
{
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
        line.append( avgPsnr==NULL?"-;":(QString::number(avgPsnr))+";");
        line.append(avgSsim==NULL?"-;":(QString::number(avgSsim))+";");
        line.append(avgMsvd==NULL?"-;":(QString::number(avgMsvd))+";");
        stream<<line<<endl;

        for(int i=1;i<length;i++)
        {
            line=QString::number(i)+";";
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

    if(psnrRes.isEmpty()&&ssimRes.isEmpty()&&msvdRes.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("There are no results.");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
    }

    if(!psnrRes.isEmpty())
    {
        Graph* g_psnr  = new Graph(this);
        connect(this,SIGNAL(sendPsnrResults(QVector<double>)),g_psnr,SLOT(showPsnrGraph(QVector<double>)));
        emit sendPsnrResults(psnrRes);
        g_psnr->move(50,100);
        g_psnr->show();
    }
    if(!ssimRes.isEmpty())
    {
        Graph* g_ssim  = new Graph(this);
        connect(this,SIGNAL(sendSsimResults(QVector<double>)),g_ssim,SLOT(showSsimGraph(QVector<double>)));
        emit sendSsimResults(ssimRes);
        g_ssim->move(75,125);
        g_ssim->show();
    }
    if(!msvdRes.isEmpty())
    {
        Graph* g_msvd  = new Graph(this);
        connect(this,SIGNAL(sendMsvdResults(QVector<double>)),g_msvd,SLOT(showMsvdGraph(QVector<double>)));
        emit sendMsvdResults(msvdRes);
        g_msvd->move(100,150);
        g_msvd->show();
    }

}




void MainWindow::on_actionChannel_triggered()
{
    Channel* ch = new Channel(this);
    connect(ch,SIGNAL(updateTextOutput(const QString)),this,SLOT(setStandardOutputText(const QString)));
    connect(ch,SIGNAL(updateText(const QString)),this,SLOT(setOutputText(const QString)));
    ch->exec();
}
