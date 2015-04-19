#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void setOutputText(const QString);

    void setStandardOutputText(const QString);

    void setPsnr(QList<double>);
    void setSsim(QList<double>);
    void setMsvd(QList<double>);

    void on_actionEncode_triggered();

    void on_actionDecode_triggered();

    void on_actionTest_triggered();

    void on_actionExit_triggered();


    void on_actionExport_CSV_triggered();

private:
    Ui::MainWindow *ui;

    double getAverage(QList<double>);
    double getMax(QList<double>);
    double getMin(QList<double>);

    QList<double> psnrRes;
    QList<double> ssimRes;
    QList<double> msvdRes;

    double avgPsnr;
    double avgSsim;
    double avgMsvd;

};

#endif // MAINWINDOW_H
