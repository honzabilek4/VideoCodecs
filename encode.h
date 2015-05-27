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

    void firstPassFinished();

    void on_browseButton_clicked();

    void loadSettings();

    void on_saveButton_clicked();

    void on_comboBox_Codec_currentIndexChanged(int index);

    QStringList getArguments(int pass);

    void on_profileBox_currentIndexChanged(int index);

    void startFfmpeg();

signals:

    void updateTextOutput(const QString text);
    void toggleUi();

private:
    Ui::Encode *ui;
    QProcess* ffmpeg;
    QString ffmpegOutput;
    QString fileStr;
    QString saveFileName;
    QString homeFolder;
    QString program;
    QStringList arguments;
    QString codec;
    QString dimensions;
    QStringList quality;
    QString framerate;
    QStringList presets; //holds profile and preset
    QString outfiletype;
    QStringList fileList;
    int fileIndex;
    QString saveFolder; //only used when encoding multiple files


};

#endif // ENCODE_H
