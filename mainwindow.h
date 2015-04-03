#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

    void on_actionExit_triggered();

    void on_openFile1_clicked();

    void on_openFile2_clicked();

    void on_psnrButton_clicked();

    void on_ssimButton_clicked();

    void on_msvdButton_clicked();

    void on_encodeButton_clicked();

    void setOutputText(const QString text);


private:
    Ui::MainWindow *ui;
    std::string file1;
    std::string file2;
    double** psnrArray;
    double* ssimResults;
    double* msvdResults;

};

#endif // MAINWINDOW_H
