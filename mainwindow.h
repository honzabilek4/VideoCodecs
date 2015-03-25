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

private:
    Ui::MainWindow *ui;
    const char *file1;
    const char *file2;
    std::string fileStdStr1;
    std::string fileStdStr2;

};

#endif // MAINWINDOW_H
