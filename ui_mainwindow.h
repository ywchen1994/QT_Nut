/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QWidget *tab_2;
    QLabel *label_2;
    QGroupBox *groupBox;
    QPushButton *btn_Capture;
    QPushButton *btn_Connect;
    QPushButton *btn_DisConnect;
    QComboBox *cBox_Camera;
    QGroupBox *groupBox_2;
    QCheckBox *ckBox_CW;
    QCheckBox *ckBox_CCW;
    QPushButton *btn_Start;
    QPushButton *btn_Stop;
    QComboBox *cBox_PortName;
    QPushButton *btn_RefreshCom;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1366, 1080);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1024, 1024));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1024, 1024));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 1024, 1024));
        tabWidget->addTab(tab_2, QString());
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(1040, 20, 291, 171));
        btn_Capture = new QPushButton(groupBox);
        btn_Capture->setObjectName(QString::fromUtf8("btn_Capture"));
        btn_Capture->setGeometry(QRect(120, 70, 161, 91));
        btn_Connect = new QPushButton(groupBox);
        btn_Connect->setObjectName(QString::fromUtf8("btn_Connect"));
        btn_Connect->setGeometry(QRect(10, 70, 101, 41));
        btn_DisConnect = new QPushButton(groupBox);
        btn_DisConnect->setObjectName(QString::fromUtf8("btn_DisConnect"));
        btn_DisConnect->setGeometry(QRect(10, 120, 101, 41));
        cBox_Camera = new QComboBox(groupBox);
        cBox_Camera->setObjectName(QString::fromUtf8("cBox_Camera"));
        cBox_Camera->setGeometry(QRect(10, 30, 261, 22));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(1060, 210, 271, 101));
        ckBox_CW = new QCheckBox(groupBox_2);
        ckBox_CW->setObjectName(QString::fromUtf8("ckBox_CW"));
        ckBox_CW->setEnabled(true);
        ckBox_CW->setGeometry(QRect(190, 70, 73, 16));
        ckBox_CW->setChecked(true);
        ckBox_CCW = new QCheckBox(groupBox_2);
        ckBox_CCW->setObjectName(QString::fromUtf8("ckBox_CCW"));
        ckBox_CCW->setGeometry(QRect(110, 70, 73, 16));
        btn_Start = new QPushButton(groupBox_2);
        btn_Start->setObjectName(QString::fromUtf8("btn_Start"));
        btn_Start->setGeometry(QRect(110, 30, 75, 23));
        btn_Stop = new QPushButton(groupBox_2);
        btn_Stop->setObjectName(QString::fromUtf8("btn_Stop"));
        btn_Stop->setGeometry(QRect(190, 30, 75, 23));
        cBox_PortName = new QComboBox(groupBox_2);
        cBox_PortName->setObjectName(QString::fromUtf8("cBox_PortName"));
        cBox_PortName->setGeometry(QRect(10, 50, 91, 22));
        btn_RefreshCom = new QPushButton(centralWidget);
        btn_RefreshCom->setObjectName(QString::fromUtf8("btn_RefreshCom"));
        btn_RefreshCom->setGeometry(QRect(1060, 320, 151, 101));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Monitor", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Moniteor2", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Camera", nullptr));
        btn_Capture->setText(QApplication::translate("MainWindow", "Capture", nullptr));
        btn_Connect->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        btn_DisConnect->setText(QApplication::translate("MainWindow", "Disconnect", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "StepMotor", nullptr));
        ckBox_CW->setText(QApplication::translate("MainWindow", "CW", nullptr));
        ckBox_CCW->setText(QApplication::translate("MainWindow", "CCW", nullptr));
        btn_Start->setText(QApplication::translate("MainWindow", "Start", nullptr));
        btn_Stop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        btn_RefreshCom->setText(QApplication::translate("MainWindow", "Refresh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
