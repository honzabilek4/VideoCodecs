#include "graph.h"
#include "ui_graph.h"

Graph::Graph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graph)
{
    ui->setupUi(this);
    //setPlot(ui->customPlot);

}

Graph::~Graph()
{
    delete ui;
}

void Graph::setPlot(QCustomPlot* customPlot)
{
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    customPlot->xAxis->setRange(-1, 1);
    customPlot->yAxis->setRange(0, 1);
    customPlot->replot();
}

void Graph::showGraph(QVector<double> vector,QString method)
{
    QVector<double> x(vector.length());
    for(int i=1;i<vector.length();i++)
    {
        x[i]=i;
    }
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCross,6));
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->customPlot->graph(0)->setData(x,vector);

    if(method=="psnr")
    {
        ui->customPlot->xAxis->setLabel("x");
        ui->customPlot->yAxis->setLabel("y");
        ui->customPlot->xAxis->setRange(1,x.length());
        ui->customPlot->yAxis->setRange(30,50);
    }
    else if (method=="ssim")
    {

    }
    else if (method=="msvd")
    {

    }


    ui->customPlot->replot();

}

