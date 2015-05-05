/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Test
{
public:
    QFrame *line;
    QLabel *label_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *psnrBox;
    QCheckBox *ssimBox;
    QCheckBox *msvdBox;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *originalLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *openButton;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *decodedLabel;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *openButton_2;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QSpinBox *frameBox;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *runButton;
    QPushButton *cancelButton;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QSpinBox *widthBox;
    QLabel *label_4;
    QSpinBox *heightBox;
    QGroupBox *groupBox;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QSpinBox *windowSizeBox;
    QLabel *label_6;
    QSpinBox *stepSizeBox;

    void setupUi(QDialog *Test)
    {
        if (Test->objectName().isEmpty())
            Test->setObjectName(QStringLiteral("Test"));
        Test->setEnabled(true);
        Test->resize(404, 383);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Test->sizePolicy().hasHeightForWidth());
        Test->setSizePolicy(sizePolicy);
        Test->setMinimumSize(QSize(404, 383));
        Test->setMaximumSize(QSize(404, 383));
        line = new QFrame(Test);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(30, 100, 341, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(Test);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 300, 47, 13));
        layoutWidget = new QWidget(Test);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 300, 281, 21));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        psnrBox = new QCheckBox(layoutWidget);
        psnrBox->setObjectName(QStringLiteral("psnrBox"));

        horizontalLayout_3->addWidget(psnrBox);

        ssimBox = new QCheckBox(layoutWidget);
        ssimBox->setObjectName(QStringLiteral("ssimBox"));

        horizontalLayout_3->addWidget(ssimBox);

        msvdBox = new QCheckBox(layoutWidget);
        msvdBox->setObjectName(QStringLiteral("msvdBox"));

        horizontalLayout_3->addWidget(msvdBox);

        layoutWidget1 = new QWidget(Test);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 20, 341, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        originalLabel = new QLabel(layoutWidget1);
        originalLabel->setObjectName(QStringLiteral("originalLabel"));

        horizontalLayout->addWidget(originalLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        openButton = new QPushButton(layoutWidget1);
        openButton->setObjectName(QStringLiteral("openButton"));

        horizontalLayout->addWidget(openButton);

        layoutWidget2 = new QWidget(Test);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(30, 60, 341, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        decodedLabel = new QLabel(layoutWidget2);
        decodedLabel->setObjectName(QStringLiteral("decodedLabel"));

        horizontalLayout_2->addWidget(decodedLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        openButton_2 = new QPushButton(layoutWidget2);
        openButton_2->setObjectName(QStringLiteral("openButton_2"));

        horizontalLayout_2->addWidget(openButton_2);

        layoutWidget3 = new QWidget(Test);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(30, 170, 331, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget3);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        frameBox = new QSpinBox(layoutWidget3);
        frameBox->setObjectName(QStringLiteral("frameBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frameBox->sizePolicy().hasHeightForWidth());
        frameBox->setSizePolicy(sizePolicy1);
        frameBox->setMinimumSize(QSize(78, 0));
        frameBox->setMinimum(1);
        frameBox->setMaximum(999999);
        frameBox->setValue(100);

        horizontalLayout_4->addWidget(frameBox);

        layoutWidget4 = new QWidget(Test);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(100, 340, 221, 31));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        runButton = new QPushButton(layoutWidget4);
        runButton->setObjectName(QStringLiteral("runButton"));
        runButton->setEnabled(true);

        horizontalLayout_5->addWidget(runButton);

        cancelButton = new QPushButton(layoutWidget4);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout_5->addWidget(cancelButton);

        layoutWidget5 = new QWidget(Test);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(32, 121, 331, 22));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget5);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_6->addWidget(label_3);

        widthBox = new QSpinBox(layoutWidget5);
        widthBox->setObjectName(QStringLiteral("widthBox"));
        widthBox->setMinimumSize(QSize(70, 0));
        widthBox->setMinimum(1);
        widthBox->setMaximum(99999);
        widthBox->setValue(352);

        horizontalLayout_6->addWidget(widthBox);

        label_4 = new QLabel(layoutWidget5);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_6->addWidget(label_4);

        heightBox = new QSpinBox(layoutWidget5);
        heightBox->setObjectName(QStringLiteral("heightBox"));
        heightBox->setMinimumSize(QSize(70, 0));
        heightBox->setMinimum(1);
        heightBox->setMaximum(99999);
        heightBox->setValue(288);

        horizontalLayout_6->addWidget(heightBox);

        groupBox = new QGroupBox(Test);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(false);
        groupBox->setGeometry(QRect(20, 220, 351, 51));
        layoutWidget6 = new QWidget(groupBox);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(10, 20, 331, 22));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget6);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_8->addWidget(label_5);

        windowSizeBox = new QSpinBox(layoutWidget6);
        windowSizeBox->setObjectName(QStringLiteral("windowSizeBox"));
        windowSizeBox->setMinimumSize(QSize(70, 0));
        windowSizeBox->setMaximum(999);
        windowSizeBox->setValue(16);

        horizontalLayout_8->addWidget(windowSizeBox);

        label_6 = new QLabel(layoutWidget6);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_8->addWidget(label_6);

        stepSizeBox = new QSpinBox(layoutWidget6);
        stepSizeBox->setObjectName(QStringLiteral("stepSizeBox"));
        stepSizeBox->setMinimumSize(QSize(70, 0));
        stepSizeBox->setMaximum(999);
        stepSizeBox->setValue(8);

        horizontalLayout_8->addWidget(stepSizeBox);

        QWidget::setTabOrder(openButton, openButton_2);
        QWidget::setTabOrder(openButton_2, widthBox);
        QWidget::setTabOrder(widthBox, heightBox);
        QWidget::setTabOrder(heightBox, frameBox);
        QWidget::setTabOrder(frameBox, windowSizeBox);
        QWidget::setTabOrder(windowSizeBox, stepSizeBox);
        QWidget::setTabOrder(stepSizeBox, psnrBox);
        QWidget::setTabOrder(psnrBox, ssimBox);
        QWidget::setTabOrder(ssimBox, msvdBox);
        QWidget::setTabOrder(msvdBox, runButton);
        QWidget::setTabOrder(runButton, cancelButton);

        retranslateUi(Test);
        QObject::connect(ssimBox, SIGNAL(toggled(bool)), groupBox, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(Test);
    } // setupUi

    void retranslateUi(QDialog *Test)
    {
        Test->setWindowTitle(QApplication::translate("Test", "Test", 0));
        label_2->setText(QApplication::translate("Test", "Method:", 0));
        psnrBox->setText(QApplication::translate("Test", "PSNR", 0));
        ssimBox->setText(QApplication::translate("Test", "SSIM", 0));
        msvdBox->setText(QApplication::translate("Test", "M-SVD", 0));
        originalLabel->setText(QApplication::translate("Test", " Open Original File   ", 0));
        openButton->setText(QApplication::translate("Test", "Open File", 0));
        decodedLabel->setText(QApplication::translate("Test", " Open Decoded File ", 0));
        openButton_2->setText(QApplication::translate("Test", "Open File", 0));
        label->setText(QApplication::translate("Test", "Number of frames:", 0));
        runButton->setText(QApplication::translate("Test", "Run", 0));
        cancelButton->setText(QApplication::translate("Test", "Cancel", 0));
        label_3->setText(QApplication::translate("Test", "Width:", 0));
        label_4->setText(QApplication::translate("Test", "Height:", 0));
        groupBox->setTitle(QApplication::translate("Test", "SSIM:", 0));
        label_5->setText(QApplication::translate("Test", "Window size:", 0));
        label_6->setText(QApplication::translate("Test", " Step size:", 0));
    } // retranslateUi

};

namespace Ui {
    class Test: public Ui_Test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
