/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *stopBits;
    QComboBox *dataBits;
    QPushButton *OK;
    QComboBox *flowcontrol;
    QComboBox *parity;
    QLabel *label_2;

    void setupUi(QDialog *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName(QStringLiteral("SettingsWindow"));
        SettingsWindow->resize(317, 229);
        label = new QLabel(SettingsWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 101, 16));
        label_3 = new QLabel(SettingsWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 110, 81, 16));
        label_4 = new QLabel(SettingsWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(26, 150, 111, 20));
        stopBits = new QComboBox(SettingsWindow);
        stopBits->setObjectName(QStringLiteral("stopBits"));
        stopBits->setGeometry(QRect(180, 70, 111, 22));
        dataBits = new QComboBox(SettingsWindow);
        dataBits->setObjectName(QStringLiteral("dataBits"));
        dataBits->setGeometry(QRect(180, 30, 111, 22));
        OK = new QPushButton(SettingsWindow);
        OK->setObjectName(QStringLiteral("OK"));
        OK->setGeometry(QRect(180, 180, 80, 21));
        flowcontrol = new QComboBox(SettingsWindow);
        flowcontrol->setObjectName(QStringLiteral("flowcontrol"));
        flowcontrol->setGeometry(QRect(180, 150, 111, 22));
        parity = new QComboBox(SettingsWindow);
        parity->setObjectName(QStringLiteral("parity"));
        parity->setGeometry(QRect(180, 110, 111, 22));
        label_2 = new QLabel(SettingsWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 70, 91, 16));

        retranslateUi(SettingsWindow);

        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QDialog *SettingsWindow)
    {
        SettingsWindow->setWindowTitle(QApplication::translate("SettingsWindow", "Dialog", nullptr));
        label->setText(QApplication::translate("SettingsWindow", "\320\221\320\270\321\202\321\213 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        label_3->setText(QApplication::translate("SettingsWindow", "\320\221\320\270\321\202 \321\207\320\265\321\202\320\275\320\276\321\201\321\202\320\270", nullptr));
        label_4->setText(QApplication::translate("SettingsWindow", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\320\276\321\202\320\276\320\272\320\276\320\274", nullptr));
        OK->setText(QApplication::translate("SettingsWindow", "OK", nullptr));
        label_2->setText(QApplication::translate("SettingsWindow", "\320\241\321\202\320\276\320\277\320\276\320\262\321\213\320\271 \320\261\320\270\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
