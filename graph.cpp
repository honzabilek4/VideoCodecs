#include "graph.h"
#include "ui_graph.h"
#include <QDebug>

Graph::Graph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graph)
{
    ui->setupUi(this);

}

Graph::~Graph()
{
    delete ui;
}


void Graph::showPsnrGraph(QVector<double> vector)
{
    QWidget::setWindowTitle("PSNR");
    QVector<double> x(vector.length());
    for(int i=1;i<vector.length();i++)
    {
        x[i]=i;
    }
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCross,6));
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->customPlot->graph(0)->setData(x,vector);
    ui->customPlot->xAxis->setLabel("frame number[-]");
    ui->customPlot->xAxis->setRange(1,x.length());
    ui->customPlot->yAxis->setRangeUpper(getMax(vector)+5.0);
    ui->customPlot->yAxis->setRangeLower(getMin(vector)-5.0);
    ui->customPlot->yAxis->setLabel("PSNR[dB]");
    ui->customPlot->replot();

    disconnect(parentWidget(),SIGNAL(sendPsnrResults(QVector<double>)),this,SLOT(showPsnrGraph(QVector<double>)));

}

void Graph::showSsimGraph(QVector<double> vector)
{
    QWidget::setWindowTitle("SSIM");
    QVector<double> x(vector.length());
    for(int i=1;i<vector.length();i++)
    {
        x[i]=i;
    }
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCross,6));
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->customPlot->graph(0)->setData(x,vector);
    ui->customPlot->xAxis->setLabel("frame number[-]");
    ui->customPlot->xAxis->setRange(1,x.length());
    ui->customPlot->yAxis->setRangeLower(getMin(vector)-0.01);
    ui->customPlot->yAxis->setRangeUpper(1);
    ui->customPlot->yAxis->setLabel("SSIM[-]");
    ui->customPlot->replot();

    disconnect(parentWidget(),SIGNAL(sendSsimResults(QVector<double>)),this,SLOT(showSsimGraph(QVector<double>)));
}
void Graph::showMsvdGraph(QVector<double> vector)
{
    QWidget::setWindowTitle("MSVD");
    QVector<double> x(vector.length());
    for(int i=1;i<vector.length();i++)
    {
        x[i]=i;
    }
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCross,6));
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->customPlot->graph(0)->setData(x,vector);
    ui->customPlot->xAxis->setLabel("frame number[-]");
    ui->customPlot->yAxis->setRangeLower(0);
    ui->customPlot->yAxis->setRangeUpper(getMax(vector)+1.0);
    ui->customPlot->xAxis->setRange(1,x.length());
    ui->customPlot->yAxis->setLabel("MSVD[-]");
    ui->customPlot->replot();

    disconnect(parentWidget(),SIGNAL(sendMsvdResults(QVector<double>)),this,SLOT(showMsvdGraph(QVector<double>)));
}


double Graph::getMax(QVector<double> vector)
{

    double max = *std::max_element(vector.begin(), vector.end());
    return max;
}
double Graph::getMin(QVector<double> vector)
{
    double min = *std::min_element(vector.begin(), vector.end());
    return min;
}
