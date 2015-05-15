#ifndef CHANNEL_H
#define CHANNEL_H

#include <QDialog>

namespace Ui {
class Channel;
}

class Channel : public QDialog
{
    Q_OBJECT

public:
    explicit Channel(QWidget *parent = 0);
    ~Channel();

private slots:


    void on_browseButton_clicked();

    void on_saveButton_clicked();

    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::Channel *ui;
};

#endif // CHANNEL_H
