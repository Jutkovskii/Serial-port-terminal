#include "qportcommunications.h"

QPortTransmitter::QPortTransmitter( QSerialPort *getPort, bool *getStatus,QMutex *getMutex,QObject *parent) : QObject(parent)
{
port=getPort;
status=getStatus;
portMutex=getMutex;

}

void QPortTransmitter::connectPort(QString port_name,int baud)
{
    port->setPortName(port_name);
    port->setBaudRate(baud);
    port->setDataBits(settings.dataBits);
    port->setStopBits(settings.stopBits);
    if (port->open(QIODevice::ReadWrite))
        emit connected(1);
    else
        emit connected(0);

}

void QPortTransmitter::disconnectPort()
{
    port->close();
    emit connected(0);
}

void QPortTransmitter::settingsPort(PortSettings get_settings)
{
settings=get_settings;
}

void QPortTransmitter::sendPort(QByteArray command, int interval)
{

    do
    {
        portMutex->lock();
        port->write(command);
        port->waitForBytesWritten(1);
        usleep(interval);
        portMutex->unlock();
    }
    while(*status);


}


//------------------------------------------------------
QPortReciever::QPortReciever( QSerialPort *getport, QMutex *getmutex,QObject *parent) : QObject(parent)
{
port=getport;
portMutex=getmutex;
QObject::connect(port,SIGNAL(readyRead()),this,SLOT(recievePort()));
}

void QPortReciever::recievePort()
{
    portMutex->lock();
    QByteArray recieve=port->readAll();
    emit recieved(recieve);
    portMutex->unlock();

}
