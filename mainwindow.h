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

    void setOutputText(const QString text);

    void on_actionEncode_triggered();

    void on_actionDecode_triggered();

    void on_actionTest_triggered();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
