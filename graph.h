#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>
#include <qcustomplot.h>
#include <QVector>

namespace Ui {
class Graph;
}

class Graph : public QDialog
{
    Q_OBJECT

public:
    explicit Graph(QWidget *parent = 0);
    ~Graph();

private slots:
    void showGraph(QVector<double>,QString method);


private:
    Ui::Graph *ui;
    void setPlot(QCustomPlot* customPlot);
};

#endif // GRAPH_H
