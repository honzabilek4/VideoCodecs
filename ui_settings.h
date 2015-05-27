/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QLabel *label;
    QLabel *label_2;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QToolButton *toolButton_3;
    QLineEdit *lineEdit_3;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QStringLiteral("Settings"));
        Settings->resize(359, 245);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Settings->sizePolicy().hasHeightForWidth());
        Settings->setSizePolicy(sizePolicy);
        Settings->setMinimumSize(QSize(359, 245));
        Settings->setMaximumSize(QSize(359, 245));
        buttonBox = new QDialogButtonBox(Settings);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 210, 311, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(Settings);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 50, 271, 20));
        lineEdit_2 = new QLineEdit(Settings);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(20, 100, 271, 20));
        toolButton = new QToolButton(Settings);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(310, 50, 25, 19));
        toolButton_2 = new QToolButton(Settings);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(310, 100, 25, 19));
        label = new QLabel(Settings);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 151, 16));
        label_2 = new QLabel(Settings);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 80, 121, 16));
        groupBox = new QGroupBox(Settings);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 331, 121));
        groupBox_2 = new QGroupBox(Settings);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 140, 331, 61));
        groupBox_2->setCheckable(true);
        groupBox_2->setChecked(false);
        toolButton_3 = new QToolButton(groupBox_2);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setGeometry(QRect(300, 30, 25, 19));
        lineEdit_3 = new QLineEdit(groupBox_2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(10, 30, 271, 20));
        QWidget::setTabOrder(lineEdit, toolButton);
        QWidget::setTabOrder(toolButton, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, toolButton_2);

        retranslateUi(Settings);
        QObject::connect(buttonBox, SIGNAL(accepted()), Settings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Settings, SLOT(reject()));
        QObject::connect(groupBox_2, SIGNAL(toggled(bool)), lineEdit_3, SLOT(setEnabled(bool)));
        QObject::connect(groupBox_2, SIGNAL(toggled(bool)), toolButton_3, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "General Settings", 0));
        toolButton->setText(QApplication::translate("Settings", "...", 0));
        toolButton_2->setText(QApplication::translate("Settings", "...", 0));
        label->setText(QApplication::translate("Settings", "Encode/ Decode home folder:", 0));
        label_2->setText(QApplication::translate("Settings", "Test home folder:", 0));
        groupBox->setTitle(QApplication::translate("Settings", "Default folders", 0));
        groupBox_2->setTitle(QApplication::translate("Settings", "Use CSV results folder", 0));
        toolButton_3->setText(QApplication::translate("Settings", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
