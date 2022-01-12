#include "portsettings.h"

PortSettings::PortSettings()
{
dataBits=QSerialPort::Data8;
stopBits=QSerialPort::OneStop;
parity=QSerialPort::NoParity;
flowControl=QSerialPort::NoFlowControl;
}
