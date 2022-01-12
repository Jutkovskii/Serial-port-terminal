#ifndef PORTSETTINGS_H
#define PORTSETTINGS_H
#include <QtSerialPort/QSerialPort>

class PortSettings
{
public:
    QSerialPort::DataBits dataBits;
    QSerialPort::StopBits stopBits;
    QSerialPort::Parity parity;
    QSerialPort::FlowControl flowControl;
    PortSettings();
};

#endif // PORTSETTINGS_H
