/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *Port1;
    QComboBox *baudPort1;
    QLabel *label_2;
    QPushButton *connectPort1;
    QGroupBox *groupBox;
    QRadioButton *symPort1;
    QCheckBox *cyclePort1;
    QPushButton *sendPort1;
    QRadioButton *hexPort1;
    QLineEdit *intervalPort1;
    QPushButton *clearOutputPort1;
    QLabel *mcsLabel;
    QPushButton *disconnectPort1;
    QPushButton *settingsPort1;
    QComboBox *namePort1;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_6;
    QTextBrowser *inputPort1;
    QLineEdit *outputPort1;
    QPushButton *clearInputPort1;
    QPushButton *addPort;
    QFrame *line;
    QGroupBox *Port2;
    QComboBox *baudPort2;
    QLabel *label_3;
    QPushButton *connectPort2;
    QGroupBox *groupBox_2;
    QRadioButton *symPort2;
    QCheckBox *cyclePort2;
    QPushButton *sendPort2;
    QRadioButton *hexPort2;
    QLineEdit *intervalPort2;
    QPushButton *clearOutputPort2;
    QLabel *mcsLabel_2;
    QPushButton *disconnectPort2;
    QPushButton *settingsPort2;
    QComboBox *namePort2;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_8;
    QTextBrowser *inputPort2;
    QLineEdit *outputPort2;
    QPushButton *clearInputPort2;
    QPushButton *delPort;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1004, 734);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(1004, 734));
        MainWindow->setWindowTitle(QString::fromUtf8("Serial port terminal"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Port1 = new QGroupBox(centralWidget);
        Port1->setObjectName(QString::fromUtf8("Port1"));
        baudPort1 = new QComboBox(Port1);
        baudPort1->setObjectName(QString::fromUtf8("baudPort1"));
        baudPort1->setGeometry(QRect(60, 60, 72, 22));
        label_2 = new QLabel(Port1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 47, 13));
        connectPort1 = new QPushButton(Port1);
        connectPort1->setObjectName(QString::fromUtf8("connectPort1"));
        connectPort1->setGeometry(QRect(10, 90, 91, 21));
        groupBox = new QGroupBox(Port1);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 570, 441, 101));
        symPort1 = new QRadioButton(groupBox);
        symPort1->setObjectName(QString::fromUtf8("symPort1"));
        symPort1->setGeometry(QRect(130, 30, 84, 19));
        cyclePort1 = new QCheckBox(groupBox);
        cyclePort1->setObjectName(QString::fromUtf8("cyclePort1"));
        cyclePort1->setGeometry(QRect(140, 60, 111, 19));
        sendPort1 = new QPushButton(groupBox);
        sendPort1->setObjectName(QString::fromUtf8("sendPort1"));
        sendPort1->setGeometry(QRect(20, 60, 91, 21));
        hexPort1 = new QRadioButton(groupBox);
        hexPort1->setObjectName(QString::fromUtf8("hexPort1"));
        hexPort1->setGeometry(QRect(20, 30, 84, 19));
        intervalPort1 = new QLineEdit(groupBox);
        intervalPort1->setObjectName(QString::fromUtf8("intervalPort1"));
        intervalPort1->setGeometry(QRect(270, 60, 113, 21));
        clearOutputPort1 = new QPushButton(groupBox);
        clearOutputPort1->setObjectName(QString::fromUtf8("clearOutputPort1"));
        clearOutputPort1->setGeometry(QRect(360, 20, 80, 21));
        mcsLabel = new QLabel(groupBox);
        mcsLabel->setObjectName(QString::fromUtf8("mcsLabel"));
        mcsLabel->setGeometry(QRect(390, 60, 47, 13));
        disconnectPort1 = new QPushButton(Port1);
        disconnectPort1->setObjectName(QString::fromUtf8("disconnectPort1"));
        disconnectPort1->setGeometry(QRect(120, 90, 91, 21));
        settingsPort1 = new QPushButton(Port1);
        settingsPort1->setObjectName(QString::fromUtf8("settingsPort1"));
        settingsPort1->setGeometry(QRect(140, 30, 71, 51));
        namePort1 = new QComboBox(Port1);
        namePort1->setObjectName(QString::fromUtf8("namePort1"));
        namePort1->setGeometry(QRect(60, 30, 72, 22));
        label = new QLabel(Port1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 21, 16));
        label_5 = new QLabel(Port1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(210, 130, 31, 16));
        label_6 = new QLabel(Port1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(220, 490, 41, 16));
        inputPort1 = new QTextBrowser(Port1);
        inputPort1->setObjectName(QString::fromUtf8("inputPort1"));
        inputPort1->setGeometry(QRect(30, 150, 441, 311));
        outputPort1 = new QLineEdit(Port1);
        outputPort1->setObjectName(QString::fromUtf8("outputPort1"));
        outputPort1->setGeometry(QRect(30, 530, 441, 31));
        outputPort1->setFocusPolicy(Qt::StrongFocus);
        outputPort1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        outputPort1->setCursorMoveStyle(Qt::VisualMoveStyle);
        clearInputPort1 = new QPushButton(Port1);
        clearInputPort1->setObjectName(QString::fromUtf8("clearInputPort1"));
        clearInputPort1->setGeometry(QRect(390, 470, 80, 21));
        addPort = new QPushButton(Port1);
        addPort->setObjectName(QString::fromUtf8("addPort"));
        addPort->setGeometry(QRect(370, 50, 80, 61));

        horizontalLayout->addWidget(Port1);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        Port2 = new QGroupBox(centralWidget);
        Port2->setObjectName(QString::fromUtf8("Port2"));
        baudPort2 = new QComboBox(Port2);
        baudPort2->setObjectName(QString::fromUtf8("baudPort2"));
        baudPort2->setGeometry(QRect(60, 60, 72, 22));
        label_3 = new QLabel(Port2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 60, 47, 13));
        connectPort2 = new QPushButton(Port2);
        connectPort2->setObjectName(QString::fromUtf8("connectPort2"));
        connectPort2->setGeometry(QRect(10, 90, 91, 21));
        groupBox_2 = new QGroupBox(Port2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 570, 441, 101));
        symPort2 = new QRadioButton(groupBox_2);
        symPort2->setObjectName(QString::fromUtf8("symPort2"));
        symPort2->setGeometry(QRect(130, 30, 84, 19));
        cyclePort2 = new QCheckBox(groupBox_2);
        cyclePort2->setObjectName(QString::fromUtf8("cyclePort2"));
        cyclePort2->setGeometry(QRect(140, 60, 111, 19));
        sendPort2 = new QPushButton(groupBox_2);
        sendPort2->setObjectName(QString::fromUtf8("sendPort2"));
        sendPort2->setGeometry(QRect(20, 60, 91, 21));
        hexPort2 = new QRadioButton(groupBox_2);
        hexPort2->setObjectName(QString::fromUtf8("hexPort2"));
        hexPort2->setGeometry(QRect(20, 30, 84, 19));
        intervalPort2 = new QLineEdit(groupBox_2);
        intervalPort2->setObjectName(QString::fromUtf8("intervalPort2"));
        intervalPort2->setGeometry(QRect(270, 60, 113, 21));
        clearOutputPort2 = new QPushButton(groupBox_2);
        clearOutputPort2->setObjectName(QString::fromUtf8("clearOutputPort2"));
        clearOutputPort2->setGeometry(QRect(360, 20, 80, 21));
        mcsLabel_2 = new QLabel(groupBox_2);
        mcsLabel_2->setObjectName(QString::fromUtf8("mcsLabel_2"));
        mcsLabel_2->setGeometry(QRect(390, 60, 47, 13));
        disconnectPort2 = new QPushButton(Port2);
        disconnectPort2->setObjectName(QString::fromUtf8("disconnectPort2"));
        disconnectPort2->setGeometry(QRect(120, 90, 91, 21));
        settingsPort2 = new QPushButton(Port2);
        settingsPort2->setObjectName(QString::fromUtf8("settingsPort2"));
        settingsPort2->setGeometry(QRect(140, 30, 71, 51));
        namePort2 = new QComboBox(Port2);
        namePort2->setObjectName(QString::fromUtf8("namePort2"));
        namePort2->setGeometry(QRect(60, 30, 72, 22));
        label_4 = new QLabel(Port2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 30, 21, 16));
        label_7 = new QLabel(Port2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(210, 130, 31, 16));
        label_8 = new QLabel(Port2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(230, 490, 41, 16));
        inputPort2 = new QTextBrowser(Port2);
        inputPort2->setObjectName(QString::fromUtf8("inputPort2"));
        inputPort2->setGeometry(QRect(30, 150, 441, 311));
        outputPort2 = new QLineEdit(Port2);
        outputPort2->setObjectName(QString::fromUtf8("outputPort2"));
        outputPort2->setGeometry(QRect(30, 530, 441, 31));
        outputPort2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        clearInputPort2 = new QPushButton(Port2);
        clearInputPort2->setObjectName(QString::fromUtf8("clearInputPort2"));
        clearInputPort2->setGeometry(QRect(390, 470, 80, 21));
        delPort = new QPushButton(Port2);
        delPort->setObjectName(QString::fromUtf8("delPort"));
        delPort->setGeometry(QRect(390, 30, 80, 61));

        horizontalLayout->addWidget(Port2);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        Port1->setTitle(QCoreApplication::translate("MainWindow", "Port 1", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Baudrate", nullptr));
        connectPort1->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        groupBox->setTitle(QString());
        symPort1->setText(QCoreApplication::translate("MainWindow", "Symbol", nullptr));
        cyclePort1->setText(QCoreApplication::translate("MainWindow", "Cyclical sending", nullptr));
        sendPort1->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        hexPort1->setText(QCoreApplication::translate("MainWindow", "Hex", nullptr));
        clearOutputPort1->setText(QCoreApplication::translate("MainWindow", "Clear Output", nullptr));
        mcsLabel->setText(QCoreApplication::translate("MainWindow", "mcs", nullptr));
        disconnectPort1->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        settingsPort1->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Input", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Output", nullptr));
        clearInputPort1->setText(QCoreApplication::translate("MainWindow", "Clear Input", nullptr));
        addPort->setText(QCoreApplication::translate("MainWindow", "Add port", nullptr));
        Port2->setTitle(QCoreApplication::translate("MainWindow", "Port 2", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Baudrate", nullptr));
        connectPort2->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        groupBox_2->setTitle(QString());
        symPort2->setText(QCoreApplication::translate("MainWindow", "Symbol", nullptr));
        cyclePort2->setText(QCoreApplication::translate("MainWindow", "Cyclical sending", nullptr));
        sendPort2->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        hexPort2->setText(QCoreApplication::translate("MainWindow", "Hex", nullptr));
        clearOutputPort2->setText(QCoreApplication::translate("MainWindow", "Clear Output", nullptr));
        mcsLabel_2->setText(QCoreApplication::translate("MainWindow", "mcs", nullptr));
        disconnectPort2->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        settingsPort2->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Input", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Output", nullptr));
        clearInputPort2->setText(QCoreApplication::translate("MainWindow", "Clear Input", nullptr));
        delPort->setText(QCoreApplication::translate("MainWindow", "Delete port", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
