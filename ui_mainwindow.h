/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionDecode;
    QAction *actionEncode;
    QAction *actionTest;
    QAction *actionExport_CSV;
    QAction *actionGeneral_settings;
    QAction *actionShow_Graph;
    QAction *actionChannel;
    QWidget *centralWidget;
    QTextBrowser *textOutput;
    QLabel *label_16;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_7;
    QLabel *label_10;
    QLabel *label_13;
    QLabel *label_2;
    QLabel *label_8;
    QLabel *label_11;
    QLabel *label_14;
    QLabel *label_3;
    QLabel *label_9;
    QLabel *label_12;
    QLabel *label_15;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_5;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QMenu *menuResults;
    QMenu *menuSettings;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(430, 468);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(430, 468));
        MainWindow->setMaximumSize(QSize(430, 468));
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionDecode = new QAction(MainWindow);
        actionDecode->setObjectName(QStringLiteral("actionDecode"));
        actionEncode = new QAction(MainWindow);
        actionEncode->setObjectName(QStringLiteral("actionEncode"));
        actionTest = new QAction(MainWindow);
        actionTest->setObjectName(QStringLiteral("actionTest"));
        actionExport_CSV = new QAction(MainWindow);
        actionExport_CSV->setObjectName(QStringLiteral("actionExport_CSV"));
        actionGeneral_settings = new QAction(MainWindow);
        actionGeneral_settings->setObjectName(QStringLiteral("actionGeneral_settings"));
        actionShow_Graph = new QAction(MainWindow);
        actionShow_Graph->setObjectName(QStringLiteral("actionShow_Graph"));
        actionChannel = new QAction(MainWindow);
        actionChannel->setObjectName(QStringLiteral("actionChannel"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textOutput = new QTextBrowser(centralWidget);
        textOutput->setObjectName(QStringLiteral("textOutput"));
        textOutput->setGeometry(QRect(20, 260, 381, 131));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 10, 101, 81));
        label_16->setPixmap(QPixmap(QString::fromUtf8(":/main/logo.png")));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(21, 95, 381, 151));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setLayoutDirection(Qt::LeftToRight);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 0, 1, 1, 1);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setLayoutDirection(Qt::LeftToRight);
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_10, 0, 2, 1, 1);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setLayoutDirection(Qt::LeftToRight);
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_13, 0, 3, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setLayoutDirection(Qt::LeftToRight);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 1, 1, 1, 1);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setLayoutDirection(Qt::LeftToRight);
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_11, 1, 2, 1, 1);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setLayoutDirection(Qt::LeftToRight);
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_14, 1, 3, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setLayoutDirection(Qt::LeftToRight);
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_9, 2, 1, 1, 1);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setLayoutDirection(Qt::LeftToRight);
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_12, 2, 2, 1, 1);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setLayoutDirection(Qt::LeftToRight);
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_15, 2, 3, 1, 1);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(120, 70, 281, 20));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_4);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_6);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_5);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 430, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        menuResults = new QMenu(menuBar);
        menuResults->setObjectName(QStringLiteral("menuResults"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mainToolBar->sizePolicy().hasHeightForWidth());
        mainToolBar->setSizePolicy(sizePolicy1);
        mainToolBar->setMovable(false);
        mainToolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuResults->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionDecode);
        menuFile->addAction(actionEncode);
        menuFile->addAction(actionTest);
        menuFile->addAction(actionChannel);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuResults->addAction(actionExport_CSV);
        menuResults->addAction(actionShow_Graph);
        menuSettings->addAction(actionGeneral_settings);
        mainToolBar->addAction(actionEncode);
        mainToolBar->addAction(actionDecode);
        mainToolBar->addAction(actionTest);
        mainToolBar->addAction(actionChannel);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Video Codecs", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionDecode->setText(QApplication::translate("MainWindow", "Decode", 0));
        actionEncode->setText(QApplication::translate("MainWindow", "Encode", 0));
        actionTest->setText(QApplication::translate("MainWindow", "Test", 0));
#ifndef QT_NO_TOOLTIP
        actionTest->setToolTip(QApplication::translate("MainWindow", "Test", 0));
#endif // QT_NO_TOOLTIP
        actionExport_CSV->setText(QApplication::translate("MainWindow", "Export CSV", 0));
        actionGeneral_settings->setText(QApplication::translate("MainWindow", "General...", 0));
        actionShow_Graph->setText(QApplication::translate("MainWindow", "Show Graph", 0));
        actionChannel->setText(QApplication::translate("MainWindow", "Channel", 0));
        label_16->setText(QString());
        label->setText(QApplication::translate("MainWindow", "PSNR:", 0));
        label_7->setText(QApplication::translate("MainWindow", "-", 0));
        label_10->setText(QApplication::translate("MainWindow", "-", 0));
        label_13->setText(QApplication::translate("MainWindow", "-", 0));
        label_2->setText(QApplication::translate("MainWindow", "SSIM:", 0));
        label_8->setText(QApplication::translate("MainWindow", "-", 0));
        label_11->setText(QApplication::translate("MainWindow", "-", 0));
        label_14->setText(QApplication::translate("MainWindow", "-", 0));
        label_3->setText(QApplication::translate("MainWindow", "MSVD:", 0));
        label_9->setText(QApplication::translate("MainWindow", "-", 0));
        label_12->setText(QApplication::translate("MainWindow", "-", 0));
        label_15->setText(QApplication::translate("MainWindow", "-", 0));
        label_4->setText(QApplication::translate("MainWindow", "Avg.", 0));
        label_6->setText(QApplication::translate("MainWindow", "Min", 0));
        label_5->setText(QApplication::translate("MainWindow", "Max", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0));
        menuResults->setTitle(QApplication::translate("MainWindow", "Results", 0));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Settings", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
