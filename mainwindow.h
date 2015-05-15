#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QVector>
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

    void setPsnr(QVector<double>);

    void setSsim(QVector<double>);

    void setMsvd(QVector<double>);

    void on_actionEncode_triggered();

    void on_actionDecode_triggered();

    void on_actionTest_triggered();

    void on_actionExit_triggered();

    void on_actionExport_CSV_triggered();

    void on_actionGeneral_settings_triggered();

    void toggleUi();

    void on_actionShow_Graph_triggered();

    void resetResults();


    void on_actionChannel_triggered();

signals:
    void sendPsnrResults(QVector<double>);

    void sendSsimResults(QVector<double>);

    void sendMsvdResults(QVector<double>);

private:
    Ui::MainWindow *ui;

    double getAverage(QVector<double>);
    double getMax(QVector<double>);
    double getMin(QVector<double>);

    QVector<double> psnrRes;
    QVector<double> ssimRes;
    QVector<double> msvdRes;

    double avgPsnr;
    double avgSsim;
    double avgMsvd;

};

#endif // MAINWINDOW_H
