#include "mainwindow.h"
#include <QtSerialPort/QSerialPort>
#include <QApplication>
#include "settingsinterface.h"
#include "interface.h"
#include "qportcommunications.h"
#include "mythread.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //установка флагов циклической/одиночной отправки
    bool cyclestatusPort1=0,cyclestatusPort2=0;

    //объект для работы с диалоговым окном
   interface window(&cyclestatusPort1,&cyclestatusPort2);

   QSerialPort port1,port2;
   MyThread threadPort1,threadPort2;
   QMutex mutexPort1, mutexPort2 ;

   //объекты для передачи данных
   QPortTransmitter Port1_T(&port1,&cyclestatusPort1,&mutexPort1);
   QPortTransmitter Port2_T(&port2,&cyclestatusPort2,&mutexPort2);
    //объекты для приема данных
   QPortReciever Port1_R(&port1,&mutexPort1);
   QPortReciever Port2_R(&port2,&mutexPort2);
    //настройки портов
   SettingsInterface settingsPort1, settingsPort2;


   QObject::connect(&window,SIGNAL(connectPort1(QString,int)),&Port1_T,SLOT(connectPort(QString,int)));
   QObject::connect(&window,SIGNAL(disconnectPort1()),&Port1_T,SLOT(disconnectPort()));
   QObject::connect(&window,SIGNAL(sendPort1(QByteArray,int)),&Port1_T,SLOT(sendPort(QByteArray,int)));

   QObject::connect(&Port1_T,SIGNAL(connected(bool)),&window,SLOT(connectedToPort1(bool)));
   QObject::connect(&Port1_R,SIGNAL(recieved(QByteArray)),&window,SLOT(recieveDataFromPort1(QByteArray)));

   QObject::connect(&window,SIGNAL(connectPort2(QString,int)),&Port2_T,SLOT(connectPort(QString,int)));
   QObject::connect(&window,SIGNAL(disconnectPort2()),&Port2_T,SLOT(disconnectPort()));
   QObject::connect(&window,SIGNAL(sendPort2(QByteArray,int)),&Port2_T,SLOT(sendPort(QByteArray,int)));

   QObject::connect(&Port2_T,SIGNAL(connected(bool)),&window,SLOT(connectedToPort2(bool)));
   QObject::connect(&Port2_R,SIGNAL(recieved(QByteArray)),&window,SLOT(recieveDataFromPort2(QByteArray)));

   QObject::connect(&window,SIGNAL(showSettingsPort1()),&settingsPort1,SLOT(show()));
   QObject::connect(&window,SIGNAL(showSettingsPort2()),&settingsPort2,SLOT(show()));

   qRegisterMetaType<PortSettings>("PortSettings");

   QObject::connect(&settingsPort1,SIGNAL(sendSettings(PortSettings)),&Port1_T,SLOT(settingsPort(PortSettings)));
   QObject::connect(&settingsPort2,SIGNAL(sendSettings(PortSettings)),&Port2_T,SLOT(settingsPort(PortSettings)));

   Port1_T.moveToThread(&threadPort1);
   Port2_T.moveToThread(&threadPort2);
   threadPort1.start();
   threadPort2.start();

    return a.exec();
}
