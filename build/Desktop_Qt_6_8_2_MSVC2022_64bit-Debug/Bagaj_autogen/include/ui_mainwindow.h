/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow1
{
public:
    QWidget *centralwidget;
    QPushButton *addPassenger;
    QListWidget *BaggageWidget;
    QPushButton *loadData;
    QPushButton *startSimulation;
    QListWidget *PassengerWidget;
    QListWidget *BlacklistWidget;
    QTextBrowser *logPanel;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QCheckBox *checkBoxManual;
    QPushButton *resetButton;
    QSpinBox *spinBox;
    QPushButton *checkPassengerButton;
    QPushButton *checkItemButton;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow1)
    {
        if (MainWindow1->objectName().isEmpty())
            MainWindow1->setObjectName("MainWindow1");
        MainWindow1->resize(1053, 597);
        centralwidget = new QWidget(MainWindow1);
        centralwidget->setObjectName("centralwidget");
        addPassenger = new QPushButton(centralwidget);
        addPassenger->setObjectName("addPassenger");
        addPassenger->setGeometry(QRect(140, 500, 121, 24));
        BaggageWidget = new QListWidget(centralwidget);
        BaggageWidget->setObjectName("BaggageWidget");
        BaggageWidget->setGeometry(QRect(400, 40, 256, 192));
        loadData = new QPushButton(centralwidget);
        loadData->setObjectName("loadData");
        loadData->setGeometry(QRect(360, 500, 111, 24));
        startSimulation = new QPushButton(centralwidget);
        startSimulation->setObjectName("startSimulation");
        startSimulation->setGeometry(QRect(580, 500, 121, 24));
        PassengerWidget = new QListWidget(centralwidget);
        PassengerWidget->setObjectName("PassengerWidget");
        PassengerWidget->setGeometry(QRect(90, 40, 256, 192));
        BlacklistWidget = new QListWidget(centralwidget);
        BlacklistWidget->setObjectName("BlacklistWidget");
        BlacklistWidget->setGeometry(QRect(710, 40, 256, 192));
        logPanel = new QTextBrowser(centralwidget);
        logPanel->setObjectName("logPanel");
        logPanel->setGeometry(QRect(220, 280, 621, 192));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 10, 251, 20));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(400, 10, 251, 20));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(720, 10, 241, 20));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(230, 250, 601, 16));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        checkBoxManual = new QCheckBox(centralwidget);
        checkBoxManual->setObjectName("checkBoxManual");
        checkBoxManual->setGeometry(QRect(170, 530, 61, 22));
        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName("resetButton");
        resetButton->setGeometry(QRect(790, 500, 121, 24));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(360, 530, 41, 25));
        spinBox->setMinimum(1);
        spinBox->setMaximum(30);
        checkPassengerButton = new QPushButton(centralwidget);
        checkPassengerButton->setObjectName("checkPassengerButton");
        checkPassengerButton->setGeometry(QRect(90, 250, 101, 24));
        checkItemButton = new QPushButton(centralwidget);
        checkItemButton->setObjectName("checkItemButton");
        checkItemButton->setGeometry(QRect(250, 250, 101, 24));
        MainWindow1->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow1);
        statusbar->setObjectName("statusbar");
        MainWindow1->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow1);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1053, 21));
        MainWindow1->setMenuBar(menubar);

        retranslateUi(MainWindow1);

        QMetaObject::connectSlotsByName(MainWindow1);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow1)
    {
        MainWindow1->setWindowTitle(QCoreApplication::translate("MainWindow1", "MainWindow", nullptr));
        addPassenger->setText(QCoreApplication::translate("MainWindow1", "New Passenger", nullptr));
        loadData->setText(QCoreApplication::translate("MainWindow1", "Load Data", nullptr));
        startSimulation->setText(QCoreApplication::translate("MainWindow1", "Start Simulation", nullptr));
        label->setText(QCoreApplication::translate("MainWindow1", "Passenger Queue", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow1", "Baggage Stack", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow1", "Blacklist", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow1", "Log Panel", nullptr));
        checkBoxManual->setText(QCoreApplication::translate("MainWindow1", "Manual", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow1", "Reset", nullptr));
        checkPassengerButton->setText(QCoreApplication::translate("MainWindow1", "Check Passenger", nullptr));
        checkItemButton->setText(QCoreApplication::translate("MainWindow1", "Check Item", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow1: public Ui_MainWindow1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
