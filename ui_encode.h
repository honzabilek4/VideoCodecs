/********************************************************************************
** Form generated from reading UI file 'encode.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENCODE_H
#define UI_ENCODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Encode
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *runButton;
    QPushButton *cancelButton;
    QLabel *fileLabel;
    QPushButton *browseButton;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *widthEdit;
    QComboBox *presetBox;
    QLabel *label_3;
    QComboBox *comboBox_Codec;
    QLabel *label_4;
    QComboBox *speedBox;
    QLabel *label_17;
    QPushButton *saveButton;
    QLabel *saveFileLabel;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_3;
    QLabel *label_7;
    QComboBox *profileBox;
    QLineEdit *heightEdit;
    QComboBox *levelBox;
    QLabel *label_16;
    QLabel *label_2;
    QSpinBox *fpsBox;
    QLabel *label_9;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout;
    QRadioButton *radioButton_CBR;
    QSpinBox *cbrEdit;
    QLabel *label_11;
    QSpinBox *avgBox;
    QLabel *label_10;
    QLabel *label_12;
    QRadioButton *radioButton_AVG;
    QLabel *label_6;
    QSpinBox *minBox;
    QLabel *label_14;
    QLabel *label_13;
    QSpinBox *maxBox;
    QLabel *label_15;
    QLabel *label_5;
    QLabel *label_8;
    QRadioButton *radioButton_CRF;
    QSpinBox *crfEdit;
    QCheckBox *methodBox;
    QFrame *line;
    QFrame *line_2;
    QCheckBox *testBox;
    QSpinBox *testFramesBox;
    QLabel *label_18;

    void setupUi(QDialog *Encode)
    {
        if (Encode->objectName().isEmpty())
            Encode->setObjectName(QStringLiteral("Encode"));
        Encode->resize(445, 499);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Encode->sizePolicy().hasHeightForWidth());
        Encode->setSizePolicy(sizePolicy);
        Encode->setMinimumSize(QSize(445, 499));
        Encode->setMaximumSize(QSize(445, 499));
        layoutWidget = new QWidget(Encode);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 450, 221, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        runButton = new QPushButton(layoutWidget);
        runButton->setObjectName(QStringLiteral("runButton"));

        horizontalLayout->addWidget(runButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        fileLabel = new QLabel(Encode);
        fileLabel->setObjectName(QStringLiteral("fileLabel"));
        fileLabel->setGeometry(QRect(20, 20, 241, 16));
        browseButton = new QPushButton(Encode);
        browseButton->setObjectName(QStringLiteral("browseButton"));
        browseButton->setGeometry(QRect(350, 20, 75, 23));
        layoutWidget1 = new QWidget(Encode);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 80, 191, 111));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(50, 0));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        widthEdit = new QLineEdit(layoutWidget1);
        widthEdit->setObjectName(QStringLiteral("widthEdit"));

        gridLayout_2->addWidget(widthEdit, 0, 1, 1, 1);

        presetBox = new QComboBox(layoutWidget1);
        presetBox->setObjectName(QStringLiteral("presetBox"));

        gridLayout_2->addWidget(presetBox, 2, 1, 1, 1);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        comboBox_Codec = new QComboBox(layoutWidget1);
        comboBox_Codec->setObjectName(QStringLiteral("comboBox_Codec"));

        gridLayout_2->addWidget(comboBox_Codec, 1, 1, 1, 1);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        speedBox = new QComboBox(layoutWidget1);
        speedBox->setObjectName(QStringLiteral("speedBox"));
        speedBox->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(speedBox->sizePolicy().hasHeightForWidth());
        speedBox->setSizePolicy(sizePolicy1);
        speedBox->setMinimumSize(QSize(80, 0));

        gridLayout_2->addWidget(speedBox, 3, 1, 1, 1);

        label_17 = new QLabel(layoutWidget1);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_2->addWidget(label_17, 3, 0, 1, 1);

        saveButton = new QPushButton(Encode);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(350, 420, 75, 23));
        saveFileLabel = new QLabel(Encode);
        saveFileLabel->setObjectName(QStringLiteral("saveFileLabel"));
        saveFileLabel->setGeometry(QRect(20, 420, 221, 16));
        layoutWidget2 = new QWidget(Encode);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(240, 80, 171, 111));
        gridLayout_3 = new QGridLayout(layoutWidget2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 1, 0, 1, 1);

        profileBox = new QComboBox(layoutWidget2);
        profileBox->setObjectName(QStringLiteral("profileBox"));
        profileBox->setEnabled(true);

        gridLayout_3->addWidget(profileBox, 1, 1, 1, 1);

        heightEdit = new QLineEdit(layoutWidget2);
        heightEdit->setObjectName(QStringLiteral("heightEdit"));

        gridLayout_3->addWidget(heightEdit, 0, 1, 1, 1);

        levelBox = new QComboBox(layoutWidget2);
        levelBox->setObjectName(QStringLiteral("levelBox"));
        levelBox->setEnabled(false);

        gridLayout_3->addWidget(levelBox, 2, 1, 1, 1);

        label_16 = new QLabel(layoutWidget2);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_3->addWidget(label_16, 2, 0, 1, 1);

        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(45, 0));

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        fpsBox = new QSpinBox(layoutWidget2);
        fpsBox->setObjectName(QStringLiteral("fpsBox"));
        sizePolicy.setHeightForWidth(fpsBox->sizePolicy().hasHeightForWidth());
        fpsBox->setSizePolicy(sizePolicy);
        fpsBox->setMinimumSize(QSize(60, 0));
        fpsBox->setMaximum(500);
        fpsBox->setValue(25);

        gridLayout_3->addWidget(fpsBox, 3, 1, 1, 1);

        label_9 = new QLabel(layoutWidget2);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_3->addWidget(label_9, 3, 0, 1, 1);

        layoutWidget3 = new QWidget(Encode);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(20, 200, 221, 168));
        gridLayout = new QGridLayout(layoutWidget3);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_CBR = new QRadioButton(layoutWidget3);
        radioButton_CBR->setObjectName(QStringLiteral("radioButton_CBR"));
        radioButton_CBR->setEnabled(true);
        radioButton_CBR->setChecked(true);

        gridLayout->addWidget(radioButton_CBR, 0, 1, 1, 1);

        cbrEdit = new QSpinBox(layoutWidget3);
        cbrEdit->setObjectName(QStringLiteral("cbrEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cbrEdit->sizePolicy().hasHeightForWidth());
        cbrEdit->setSizePolicy(sizePolicy2);
        cbrEdit->setMinimumSize(QSize(55, 0));
        cbrEdit->setMinimum(10);
        cbrEdit->setMaximum(999999);
        cbrEdit->setSingleStep(100);
        cbrEdit->setValue(1000);

        gridLayout->addWidget(cbrEdit, 0, 2, 1, 1);

        label_11 = new QLabel(layoutWidget3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMinimumSize(QSize(45, 0));

        gridLayout->addWidget(label_11, 0, 0, 1, 1);

        avgBox = new QSpinBox(layoutWidget3);
        avgBox->setObjectName(QStringLiteral("avgBox"));
        avgBox->setEnabled(false);
        avgBox->setMinimum(1);
        avgBox->setMaximum(99999);
        avgBox->setSingleStep(100);
        avgBox->setValue(1000);

        gridLayout->addWidget(avgBox, 1, 2, 1, 1);

        label_10 = new QLabel(layoutWidget3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(label_10, 1, 3, 1, 1);

        label_12 = new QLabel(layoutWidget3);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 2, 1, 1, 1);

        radioButton_AVG = new QRadioButton(layoutWidget3);
        radioButton_AVG->setObjectName(QStringLiteral("radioButton_AVG"));

        gridLayout->addWidget(radioButton_AVG, 1, 1, 1, 1);

        label_6 = new QLabel(layoutWidget3);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 3, 1, 1);

        minBox = new QSpinBox(layoutWidget3);
        minBox->setObjectName(QStringLiteral("minBox"));
        minBox->setEnabled(false);
        minBox->setMinimumSize(QSize(50, 0));
        minBox->setMinimum(1);
        minBox->setMaximum(99999);
        minBox->setSingleStep(100);
        minBox->setValue(500);

        gridLayout->addWidget(minBox, 2, 2, 1, 1);

        label_14 = new QLabel(layoutWidget3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(label_14, 2, 3, 1, 1);

        label_13 = new QLabel(layoutWidget3);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout->addWidget(label_13, 3, 1, 1, 1);

        maxBox = new QSpinBox(layoutWidget3);
        maxBox->setObjectName(QStringLiteral("maxBox"));
        maxBox->setEnabled(false);
        maxBox->setMinimumSize(QSize(50, 0));
        maxBox->setMinimum(1);
        maxBox->setMaximum(99999);
        maxBox->setSingleStep(100);
        maxBox->setValue(1500);

        gridLayout->addWidget(maxBox, 3, 2, 1, 1);

        label_15 = new QLabel(layoutWidget3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(label_15, 3, 3, 1, 1);

        label_5 = new QLabel(layoutWidget3);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_8 = new QLabel(layoutWidget3);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 5, 0, 1, 1);

        radioButton_CRF = new QRadioButton(layoutWidget3);
        radioButton_CRF->setObjectName(QStringLiteral("radioButton_CRF"));

        gridLayout->addWidget(radioButton_CRF, 4, 1, 1, 1);

        crfEdit = new QSpinBox(layoutWidget3);
        crfEdit->setObjectName(QStringLiteral("crfEdit"));
        crfEdit->setEnabled(false);
        crfEdit->setMinimumSize(QSize(50, 0));
        crfEdit->setMaximum(51);
        crfEdit->setValue(23);

        gridLayout->addWidget(crfEdit, 4, 2, 1, 1);

        methodBox = new QCheckBox(layoutWidget3);
        methodBox->setObjectName(QStringLiteral("methodBox"));

        gridLayout->addWidget(methodBox, 5, 2, 1, 1);

        line = new QFrame(Encode);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 40, 401, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(Encode);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(20, 400, 401, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        testBox = new QCheckBox(Encode);
        testBox->setObjectName(QStringLiteral("testBox"));
        testBox->setGeometry(QRect(20, 380, 151, 17));
        testFramesBox = new QSpinBox(Encode);
        testFramesBox->setObjectName(QStringLiteral("testFramesBox"));
        testFramesBox->setEnabled(false);
        testFramesBox->setGeometry(QRect(130, 380, 61, 22));
        testFramesBox->setMinimum(1);
        testFramesBox->setMaximum(500);
        testFramesBox->setValue(100);
        label_18 = new QLabel(Encode);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(200, 380, 47, 21));
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        fileLabel->raise();
        browseButton->raise();
        saveButton->raise();
        saveFileLabel->raise();
        line->raise();
        line_2->raise();
        testBox->raise();
        testFramesBox->raise();
        label_18->raise();
        QWidget::setTabOrder(browseButton, widthEdit);
        QWidget::setTabOrder(widthEdit, heightEdit);
        QWidget::setTabOrder(heightEdit, comboBox_Codec);
        QWidget::setTabOrder(comboBox_Codec, profileBox);
        QWidget::setTabOrder(profileBox, presetBox);
        QWidget::setTabOrder(presetBox, radioButton_CBR);
        QWidget::setTabOrder(radioButton_CBR, cbrEdit);
        QWidget::setTabOrder(cbrEdit, radioButton_AVG);
        QWidget::setTabOrder(radioButton_AVG, avgBox);
        QWidget::setTabOrder(avgBox, minBox);
        QWidget::setTabOrder(minBox, maxBox);
        QWidget::setTabOrder(maxBox, saveButton);
        QWidget::setTabOrder(saveButton, runButton);
        QWidget::setTabOrder(runButton, cancelButton);

        retranslateUi(Encode);
        QObject::connect(radioButton_CBR, SIGNAL(toggled(bool)), crfEdit, SLOT(setDisabled(bool)));
        QObject::connect(radioButton_CRF, SIGNAL(toggled(bool)), cbrEdit, SLOT(setDisabled(bool)));
        QObject::connect(radioButton_CBR, SIGNAL(toggled(bool)), avgBox, SLOT(setDisabled(bool)));
        QObject::connect(radioButton_CRF, SIGNAL(toggled(bool)), avgBox, SLOT(setDisabled(bool)));
        QObject::connect(radioButton_CBR, SIGNAL(toggled(bool)), minBox, SLOT(setDisabled(bool)));
        QObject::connect(radioButton_CBR, SIGNAL(toggled(bool)), maxBox, SLOT(setDisabled(bool)));
        QObject::connect(radioButton_CRF, SIGNAL(toggled(bool)), minBox, SLOT(setDisabled(bool)));
        QObject::connect(radioButton_CRF, SIGNAL(toggled(bool)), maxBox, SLOT(setDisabled(bool)));
        QObject::connect(radioButton_AVG, SIGNAL(toggled(bool)), crfEdit, SLOT(setDisabled(bool)));
        QObject::connect(radioButton_AVG, SIGNAL(toggled(bool)), cbrEdit, SLOT(setDisabled(bool)));
        QObject::connect(radioButton_CRF, SIGNAL(toggled(bool)), methodBox, SLOT(setDisabled(bool)));
        QObject::connect(testBox, SIGNAL(toggled(bool)), testFramesBox, SLOT(setEnabled(bool)));

        presetBox->setCurrentIndex(3);
        speedBox->setCurrentIndex(1);
        levelBox->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(Encode);
    } // setupUi

    void retranslateUi(QDialog *Encode)
    {
        Encode->setWindowTitle(QApplication::translate("Encode", "Encode", 0));
        runButton->setText(QApplication::translate("Encode", "Run", 0));
        cancelButton->setText(QApplication::translate("Encode", "Cancel", 0));
        fileLabel->setText(QApplication::translate("Encode", "Open File for encoding", 0));
        browseButton->setText(QApplication::translate("Encode", "Browse", 0));
        label->setText(QApplication::translate("Encode", "Width:", 0));
        presetBox->clear();
        presetBox->insertItems(0, QStringList()
         << QApplication::translate("Encode", "veryslow", 0)
         << QApplication::translate("Encode", "slower", 0)
         << QApplication::translate("Encode", "slow", 0)
         << QApplication::translate("Encode", "medium (default)", 0)
         << QApplication::translate("Encode", "fast", 0)
         << QApplication::translate("Encode", "faster", 0)
         << QApplication::translate("Encode", "veryfast", 0)
         << QApplication::translate("Encode", "superfast", 0)
         << QApplication::translate("Encode", "ultrafast", 0)
        );
        label_3->setText(QApplication::translate("Encode", "Preset:", 0));
        comboBox_Codec->clear();
        comboBox_Codec->insertItems(0, QStringList()
         << QApplication::translate("Encode", "H.264", 0)
         << QApplication::translate("Encode", "H.265", 0)
         << QApplication::translate("Encode", "VP8", 0)
         << QApplication::translate("Encode", "VP9", 0)
         << QApplication::translate("Encode", "Dirac 2.2", 0)
         << QApplication::translate("Encode", "Flash Video", 0)
         << QApplication::translate("Encode", "WMV8", 0)
        );
        label_4->setText(QApplication::translate("Encode", "Codec:", 0));
        speedBox->clear();
        speedBox->insertItems(0, QStringList()
         << QApplication::translate("Encode", "0", 0)
         << QApplication::translate("Encode", "1 (default)", 0)
         << QApplication::translate("Encode", "2", 0)
         << QApplication::translate("Encode", "3", 0)
         << QApplication::translate("Encode", "4", 0)
        );
        speedBox->setCurrentText(QApplication::translate("Encode", "1 (default)", 0));
        label_17->setText(QApplication::translate("Encode", "Speed:", 0));
        saveButton->setText(QApplication::translate("Encode", "Save As", 0));
        saveFileLabel->setText(QApplication::translate("Encode", "*_encoded.h264", 0));
        label_7->setText(QApplication::translate("Encode", "Profile:", 0));
        profileBox->clear();
        profileBox->insertItems(0, QStringList()
         << QApplication::translate("Encode", "Auto (default)", 0)
         << QApplication::translate("Encode", "High", 0)
         << QApplication::translate("Encode", "Main", 0)
         << QApplication::translate("Encode", "Baseline", 0)
        );
        levelBox->clear();
        levelBox->insertItems(0, QStringList()
         << QApplication::translate("Encode", "1.0", 0)
         << QApplication::translate("Encode", "1b", 0)
         << QApplication::translate("Encode", "1.1", 0)
         << QApplication::translate("Encode", "1.2", 0)
         << QApplication::translate("Encode", "1.3", 0)
         << QApplication::translate("Encode", "2.0", 0)
         << QApplication::translate("Encode", "2.1", 0)
         << QApplication::translate("Encode", "2.2", 0)
         << QApplication::translate("Encode", "3.0", 0)
         << QApplication::translate("Encode", "3.1", 0)
         << QApplication::translate("Encode", "3.2", 0)
         << QApplication::translate("Encode", "4.0", 0)
         << QApplication::translate("Encode", "4.1", 0)
         << QApplication::translate("Encode", "4.2", 0)
         << QApplication::translate("Encode", "5.0", 0)
         << QApplication::translate("Encode", "5.1", 0)
         << QApplication::translate("Encode", "5.2", 0)
        );
        label_16->setText(QApplication::translate("Encode", "Level:", 0));
        label_2->setText(QApplication::translate("Encode", "Height:", 0));
        label_9->setText(QApplication::translate("Encode", "fps:", 0));
        radioButton_CBR->setText(QApplication::translate("Encode", "CBR", 0));
        label_11->setText(QApplication::translate("Encode", "Bit Rate:", 0));
        label_10->setText(QApplication::translate("Encode", "kb/s", 0));
        label_12->setText(QApplication::translate("Encode", "      Min:", 0));
        radioButton_AVG->setText(QApplication::translate("Encode", "Avg:", 0));
        label_6->setText(QApplication::translate("Encode", "kb/s", 0));
        label_14->setText(QApplication::translate("Encode", "kb/s", 0));
        label_13->setText(QApplication::translate("Encode", "      Max:", 0));
        label_15->setText(QApplication::translate("Encode", "kb/s", 0));
        label_5->setText(QApplication::translate("Encode", "Quality:", 0));
        label_8->setText(QApplication::translate("Encode", "Method:", 0));
        radioButton_CRF->setText(QApplication::translate("Encode", "CRF:", 0));
        methodBox->setText(QApplication::translate("Encode", "Two-pass", 0));
        testBox->setText(QApplication::translate("Encode", "Test Sequence: ", 0));
        label_18->setText(QApplication::translate("Encode", "frames", 0));
    } // retranslateUi

};

namespace Ui {
    class Encode: public Ui_Encode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENCODE_H
