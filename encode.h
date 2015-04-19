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
    void setHomeFolder(QString);

private slots:


    void on_cancelButton_clicked();

    void on_runButton_clicked();

    void processStarted();

    void readyReadStandardOutput();

    void readyReadStandardError();

    void encodingFinished();

    void on_browseButton_clicked();

    QStringList getArguments();

    void on_saveButton_clicked();

    void on_comboBox_Codec_currentIndexChanged(int index);

signals:

    void updateTextOutput(const QString text);

private:
    Ui::Encode *ui;
    QProcess* ffmpeg;
    QString ffmpegOutput;
    QString fileStr;
    QString saveDir;
    QString fileName;
    QString homeFolder;


};

#endif // ENCODE_H
