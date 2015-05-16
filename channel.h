#ifndef CHANNEL_H
#define CHANNEL_H

#include <QDialog>
#include <QString>
#include <QProcess>
#include <QStringList>

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

    void on_runButton_clicked();

    void on_cancelButton_clicked();

    void processStarted();

    void readyReadStandardError();

    void readyReadStandardOutput();

    void processFinished();

signals:
    void updateTextOutput(const QString text);

private:
    Ui::Channel *ui;
    QString homeFolder;
    QString fileStr;
    QString saveFileStr;
    QProcess* ffmpeg;
    QString ffmpegOutput;

    void loadSettings();
    QStringList getArguments();

};

#endif // CHANNEL_H
