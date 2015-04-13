#ifndef DECODE_H
#define DECODE_H

#include <QDialog>
#include <QProcess>

namespace Ui {
class Decode;
}

class Decode : public QDialog
{
    Q_OBJECT

public:
    explicit Decode(QWidget *parent = 0);
    ~Decode();

private slots:
    void on_cancelButton_clicked();

    void on_runButton_clicked();

    void processStarted();

    void readyReadStandardOutput();

    void readyReadStandardError();

    void decodingFinished();

    void on_browseButton_clicked();

    QStringList getArguments();

signals:

    void updateTextOutput(const QString text);

private:
    Ui::Decode *ui;
    QProcess* ffmpeg;
    QString ffmpegOutput;
    QString fileStr;
};

#endif // DECODE_H