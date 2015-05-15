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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Channel
{
public:
    QPushButton *browseButton;
    QLabel *openLabel;
    QPushButton *saveButton;
    QLabel *saveLabel;
    QLabel *label_3;
    QFrame *line;
    QSpinBox *spinBox;
    QLabel *label_4;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *label_5;

    void setupUi(QDialog *Channel)
    {
        if (Channel->objectName().isEmpty())
            Channel->setObjectName(QStringLiteral("Channel"));
        Channel->resize(400, 238);
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
        label_3 = new QLabel(Channel);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 130, 81, 16));
        line = new QFrame(Channel);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 90, 351, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        spinBox = new QSpinBox(Channel);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(230, 130, 51, 21));
        spinBox->setMinimum(-99);
        spinBox->setMaximum(0);
        spinBox->setValue(-7);
        label_4 = new QLabel(Channel);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(180, 130, 41, 16));
        okButton = new QPushButton(Channel);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(110, 190, 75, 23));
        cancelButton = new QPushButton(Channel);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(210, 190, 75, 23));
        label_5 = new QLabel(Channel);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(300, 130, 21, 16));

        retranslateUi(Channel);

        QMetaObject::connectSlotsByName(Channel);
    } // setupUi

    void retranslateUi(QDialog *Channel)
    {
        Channel->setWindowTitle(QApplication::translate("Channel", "Dialog", 0));
        browseButton->setText(QApplication::translate("Channel", "Browse", 0));
        openLabel->setText(QApplication::translate("Channel", "Select File", 0));
        saveButton->setText(QApplication::translate("Channel", "Save As", 0));
        saveLabel->setText(QApplication::translate("Channel", "Select filename", 0));
        label_3->setText(QApplication::translate("Channel", "Bit Error Rate:", 0));
        label_4->setText(QApplication::translate("Channel", "1 x 10^", 0));
        okButton->setText(QApplication::translate("Channel", "OK", 0));
        cancelButton->setText(QApplication::translate("Channel", "Cancel", 0));
        label_5->setText(QApplication::translate("Channel", "[-]", 0));
    } // retranslateUi

};

namespace Ui {
    class Channel: public Ui_Channel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANNEL_H
