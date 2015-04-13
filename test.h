#ifndef TEST_H
#define TEST_H

#include <QDialog>

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

private:
    Ui::Test *ui;
    std::string file1;
    std::string file2;
};

#endif // TEST_H
