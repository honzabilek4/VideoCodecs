/********************************************************************************
** Form generated from reading UI file 'decode.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DECODE_H
#define UI_DECODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Decode
{
public:
    QPushButton *browseButton;
    QLabel *label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *runButton;
    QPushButton *cancelButton;
    QPushButton *saveButton;
    QLabel *label_2;
    QGroupBox *groupBox;
    QRadioButton *radioYUV;
    QRadioButton *radioY4M;

    void setupUi(QDialog *Decode)
    {
        if (Decode->objectName().isEmpty())
            Decode->setObjectName(QStringLiteral("Decode"));
        Decode->resize(390, 160);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Decode->sizePolicy().hasHeightForWidth());
        Decode->setSizePolicy(sizePolicy);
        Decode->setMinimumSize(QSize(390, 160));
        Decode->setMaximumSize(QSize(390, 160));
        browseButton = new QPushButton(Decode);
        browseButton->setObjectName(QStringLiteral("browseButton"));
        browseButton->setGeometry(QRect(290, 20, 75, 23));
        label = new QLabel(Decode);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 251, 16));
        layoutWidget = new QWidget(Decode);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 120, 201, 25));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        runButton = new QPushButton(layoutWidget);
        runButton->setObjectName(QStringLiteral("runButton"));

        gridLayout->addWidget(runButton, 0, 0, 1, 1);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        gridLayout->addWidget(cancelButton, 0, 1, 1, 1);

        saveButton = new QPushButton(Decode);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(290, 50, 75, 23));
        label_2 = new QLabel(Decode);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 50, 251, 16));
        groupBox = new QGroupBox(Decode);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(true);
        groupBox->setGeometry(QRect(20, 80, 341, 31));
        groupBox->setCheckable(false);
        radioYUV = new QRadioButton(groupBox);
        radioYUV->setObjectName(QStringLiteral("radioYUV"));
        radioYUV->setGeometry(QRect(100, 10, 101, 16));
        radioYUV->setChecked(true);
        radioY4M = new QRadioButton(groupBox);
        radioY4M->setObjectName(QStringLiteral("radioY4M"));
        radioY4M->setGeometry(QRect(220, 10, 111, 17));
        layoutWidget->raise();
        browseButton->raise();
        label->raise();
        saveButton->raise();
        label_2->raise();
        groupBox->raise();

        retranslateUi(Decode);

        QMetaObject::connectSlotsByName(Decode);
    } // setupUi

    void retranslateUi(QDialog *Decode)
    {
        Decode->setWindowTitle(QApplication::translate("Decode", "Decode", 0));
        browseButton->setText(QApplication::translate("Decode", "Browse", 0));
        label->setText(QApplication::translate("Decode", "Open file for decoding", 0));
        runButton->setText(QApplication::translate("Decode", "Run", 0));
        cancelButton->setText(QApplication::translate("Decode", "Cancel", 0));
        saveButton->setText(QApplication::translate("Decode", "Save As", 0));
        label_2->setText(QApplication::translate("Decode", "*_decoded.yuv", 0));
        groupBox->setTitle(QApplication::translate("Decode", "Output format:", 0));
        radioYUV->setText(QApplication::translate("Decode", "YUV", 0));
        radioY4M->setText(QApplication::translate("Decode", "Y4M", 0));
    } // retranslateUi

};

namespace Ui {
    class Decode: public Ui_Decode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DECODE_H
