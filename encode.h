#ifndef ENCODE_H
#define ENCODE_H

#include <QDialog>
#include <QProcess>

namespace Ui {
class Encode;
}

class Encode : public QDialog
{
    Q_OBJECT

public:
    explicit Encode(QWidget *parent = 0);
    ~Encode();

private slots:


    void on_cancelButton_clicked();

    void on_runButton_clicked();

    void processStarted();

    void readyReadStandardOutput();

    void readyReadStandardError();

    void encodingFinished();

    void on_browseButton_clicked();

    QStringList getArguments();

signals:

    void updateTextOutput(const QString text);

private:
    Ui::Encode *ui;
    QProcess* ffmpeg;
    QString ffmpegOutput;
    QString fileStr;


};

#endif // ENCODE_H
