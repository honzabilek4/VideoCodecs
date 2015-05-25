/********************************************************************************
** Form generated from reading UI file 'channel.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANNEL_H
#define UI_CHANNEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Channel
{
public:
    QPushButton *browseButton;
    QLabel *openLabel;
    QPushButton *saveButton;
    QLabel *saveLabel;
    QFrame *line;
    QSpinBox *spinBox;
    QLabel *label_4;
    QPushButton *runButton;
    QPushButton *cancelButton;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox;
    QSpinBox *spinBox_2;
    QLabel *label_6;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_2;
    QRadioButton *radioButton_SER;
    QRadioButton *radioButton_BER;

    void setupUi(QDialog *Channel)
    {
        if (Channel->objectName().isEmpty())
            Channel->setObjectName(QStringLiteral("Channel"));
        Channel->resize(400, 259);
        browseButton = new QPushButton(Channel);
        browseButton->setObjectName(QStringLiteral("browseButton"));
        browseButton->setGeometry(QRect(300, 30, 75, 23));
        openLabel = new QLabel(Channel);
        openLabel->setObjectName(QStringLiteral("openLabel"));
        openLabel->setGeometry(QRect(20, 30, 211, 16));
        saveButton = new QPushButton(Channel);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(300, 60, 75, 23));
        saveLabel = new QLabel(Channel);
        saveLabel->setObjectName(QStringLiteral("saveLabel"));
        saveLabel->setGeometry(QRect(20, 70, 251, 16));
        line = new QFrame(Channel);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 90, 351, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        spinBox = new QSpinBox(Channel);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(300, 130, 51, 21));
        spinBox->setMinimum(-99);
        spinBox->setMaximum(0);
        spinBox->setValue(-6);
        label_4 = new QLabel(Channel);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(260, 130, 31, 20));
        runButton = new QPushButton(Channel);
        runButton->setObjectName(QStringLiteral("runButton"));
        runButton->setGeometry(QRect(110, 210, 75, 23));
        cancelButton = new QPushButton(Channel);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(210, 210, 75, 23));
        label_5 = new QLabel(Channel);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(360, 130, 21, 16));
        doubleSpinBox = new QDoubleSpinBox(Channel);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(161, 130, 81, 22));
        doubleSpinBox->setDecimals(4);
        doubleSpinBox->setMinimum(1);
        doubleSpinBox->setMaximum(10);
        spinBox_2 = new QSpinBox(Channel);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setEnabled(false);
        spinBox_2->setGeometry(QRect(299, 170, 51, 21));
        spinBox_2->setMinimum(-99);
        spinBox_2->setMaximum(0);
        spinBox_2->setValue(-7);
        label_6 = new QLabel(Channel);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(259, 170, 31, 20));
        label_7 = new QLabel(Channel);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(359, 170, 21, 16));
        doubleSpinBox_2 = new QDoubleSpinBox(Channel);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setEnabled(false);
        doubleSpinBox_2->setGeometry(QRect(160, 170, 81, 22));
        doubleSpinBox_2->setDecimals(4);
        doubleSpinBox_2->setMinimum(1);
        doubleSpinBox_2->setMaximum(10);
        radioButton_SER = new QRadioButton(Channel);
        radioButton_SER->setObjectName(QStringLiteral("radioButton_SER"));
        radioButton_SER->setGeometry(QRect(30, 130, 121, 17));
        radioButton_SER->setChecked(true);
        radioButton_BER = new QRadioButton(Channel);
        radioButton_BER->setObjectName(QStringLiteral("radioButton_BER"));
        radioButton_BER->setGeometry(QRect(30, 170, 111, 17));

        retranslateUi(Channel);
        QObject::connect(radioButton_SER, SIGNAL(toggled(bool)), doubleSpinBox_2, SLOT(setDisabled(bool)));
        QObject::connect(radioButton_SER, SIGNAL(toggled(bool)), spinBox_2, SLOT(setDisabled(bool)));
        QObject::connect(radioButton_BER, SIGNAL(toggled(bool)), doubleSpinBox, SLOT(setDisabled(bool)));
        QObject::connect(radioButton_BER, SIGNAL(toggled(bool)), spinBox, SLOT(setDisabled(bool)));

        QMetaObject::connectSlotsByName(Channel);
    } // setupUi

    void retranslateUi(QDialog *Channel)
    {
        Channel->setWindowTitle(QApplication::translate("Channel", "Channel", 0));
        browseButton->setText(QApplication::translate("Channel", "Browse", 0));
        openLabel->setText(QApplication::translate("Channel", "Select File", 0));
        saveButton->setText(QApplication::translate("Channel", "Save As", 0));
        saveLabel->setText(QApplication::translate("Channel", "*_noised.*", 0));
        label_4->setText(QApplication::translate("Channel", "x 10^", 0));
        runButton->setText(QApplication::translate("Channel", "Run", 0));
        cancelButton->setText(QApplication::translate("Channel", "Cancel", 0));
        label_5->setText(QApplication::translate("Channel", "[-]", 0));
        label_6->setText(QApplication::translate("Channel", "x 10^", 0));
        label_7->setText(QApplication::translate("Channel", "[-]", 0));
        radioButton_SER->setText(QApplication::translate("Channel", "Symbol Error Rate:", 0));
        radioButton_BER->setText(QApplication::translate("Channel", "Bit Error Rate:", 0));
    } // retranslateUi

};

namespace Ui {
    class Channel: public Ui_Channel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANNEL_H
