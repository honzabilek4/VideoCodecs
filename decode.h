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

    void on_saveButton_clicked();

    void loadSettings();

    void startFfmpeg();


    void on_radioYUV_toggled(bool checked);

signals:

    void updateTextOutput(const QString text);

    void toggleUi();

private:
    Ui::Decode *ui;
    QProcess* ffmpeg;
    QString ffmpegOutput;
    QString fileStr;
    QString saveAsStr;
    QString homeFolder;
    QStringList fileList;
    int currentItem;
    bool label_2_changeable;

};

#endif // DECODE_H
