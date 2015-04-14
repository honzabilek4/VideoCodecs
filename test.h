#ifndef TEST_H
#define TEST_H

#include <QDialog>
#include "PsnrClass.h"
#include "SsimClass.h"
#include "MsvdClass.h"
#include <QFutureWatcher>
namespace Ui {
class Test;
}

class Test : public QDialog
{
    Q_OBJECT

public:
    explicit Test(QWidget *parent = 0);
    ~Test();

private slots:


    void on_openButton_clicked();

    void on_openButton_2_clicked();

    void on_runButton_clicked();

    void on_cancelButton_clicked();

    void psnrResultReady();

    void ssimResultReady();

    void msvdResultReady();

private:
    Ui::Test *ui;
    std::string file1;
    std::string file2;
    PsnrClass* psnr;
    SsimClass* ssim;
    MsvdClass* msvd;
    QThread* psnrThread;
    QFutureWatcher<double**>watcher;
    QFutureWatcher<double*>watcher_2;
    QFutureWatcher<double*>watcher_3;
};

#endif // TEST_H
