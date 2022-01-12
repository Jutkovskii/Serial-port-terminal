#ifndef INTERFACE_H
#define INTERFACE_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include "portsettings.h"
#include "settingsinterface.h"
#include "hexstringvalidator.h"

class interface : public QObject
{
    Q_OBJECT
public:
    MainWindow window;
    explicit interface(bool *getstatus1, bool *getstatus2,QObject *parent = nullptr);
    QStringList availablePortsList;
    QVector <int> baudrate;
    //ввод только шестнадцатеричных значений
    //restricts input data by hex values
    HexStringValidator hexVal;
    //ввод только вешественных чисел
    //restricts input data by float values
    QDoubleValidator delayPort1,delayPort2;
    //флаг для ввода только шестнадцатеричных значений
    bool hexSymPort1,hexSymPort2;
    void getAvailablePortsList();
    //влаг циклической отправки
    bool cyclePort1,cyclePort2;
    //флаг состояния порта (подключен/отключен)
    bool *statusPort1, *statusPort2;



signals:
    void connectPort1(QString portName, int baud);
    void connectPort2(QString portName, int baud);
    void sendPort1(QByteArray command, int interval);
    void sendPort2(QByteArray command, int interval);
    void disconnectPort1();
    void disconnectPort2();
    void showSettingsPort1();
    void showSettingsPort2();

public slots:
    //получить сигнал на подключение к порту из диалогового окна
    void getSignalToConnectPort1();
    void getSignalToConnectPort2();
    //получить сигнал на отключение от порта из диалогового окна
    void getSignalToDisconnectPort1();
    void getSignalToDisconnectPort2();
    //получить сигнал на передачу данных в порт из диалогового окна
    void getSignalToSendPort1();
    void getSignalToSendPort2();

    void recieveDataFromPort1(QByteArray data);
    void recieveDataFromPort2(QByteArray data);
    //получить сигнал о состоянии подключения от порта
    //get signal from port about connection
    void connectedToPort1(bool status);
    void connectedToPort2(bool status);
    //получить сигнал о вызове параметров порта
    void settingsOfPort1();
    void settingsOfPort2();
    //получение сигнала о вводе только шестнадцатеричных значений
    void hexCheckPort1();
    void hexCheckPort2();
    //получение сигнала о вводе символов
    //get singal about input symbols
    void symCheckPort1();
    void symCheckPort2();
    //получение сигнала о смене режима отправки (циклический/одиночный)
    void cycleCheckPort1();
    void cycleCheckPort2();
    //очистить поле ввода
    //clear a field of input data
    void clearInputPort1();
    void clearInputPort2();
    //очистить поле вывода
    void clearOutputPort1();
    void clearOutputPort2();

    void addPort();
    void delPort();
};

#endif // INTERFACE_H
