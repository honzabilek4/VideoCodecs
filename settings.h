#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QString>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

    void setFolderName(QString);
    void setTestFolderName(QString);


private slots:
    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_buttonBox_accepted();

signals:
    void setFolders(const QString, const QString);

private:
    Ui::Settings *ui;
    QString folderName;
    QString testFolderName;

};

#endif // SETTINGS_H
