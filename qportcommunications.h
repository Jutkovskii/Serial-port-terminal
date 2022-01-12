#ifndef QPORT_COMMUNICATIONS_H
#define QPORT_COMMUNICATIONS_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QSerialPortInfo>
#include <QMutex>
#include "unistd.h"
#include "portsettings.h"

//класс для передачи данных
class QPortTransmitter : public QObject
{
    Q_OBJECT
public:
    explicit QPortTransmitter( QSerialPort *getport, bool *getstatus,QMutex *getmutex, QObject *parent = nullptr);
    PortSettings settings;
    QSerialPort  *port;
    bool *status;
    QMutex *portMutex;

signals:
    //сигнал с состояние порта
void connected(bool status);
public slots:
//подключиться к порту с указанным  именем и скоростью
void connectPort(QString portName,int baud);
void disconnectPort();
//установить указанные настройки в порт
void settingsPort(PortSettings getSettings);
//получить данные для записи в порт
void sendPort(QByteArray command, int interval);
//получение сигнала о получении данных от порта
};

//------------------------------------------------------
//класс для приема данных
class QPortReciever : public QObject
{
    Q_OBJECT
public:
    explicit QPortReciever( QSerialPort *getPort, QMutex *getMutex, QObject *parent = nullptr);
    QSerialPort  *port;
    QMutex *portMutex;

signals:
    //сигнал с входными данными
void recieved(QByteArray data);
public slots:
//получение сигнала о получении данных от порта
    void recievePort();

};

#endif // QPORT_COMMUNICATIONS_H
