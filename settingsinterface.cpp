#include "settingsinterface.h"

SettingsInterface::SettingsInterface(QObject *parent) : QObject(parent)
{
    QString dataBits[3]={"6","7","8"};
    for(int i=0;i<3;i++)
    {
        window.ui->dataBits->addItem(dataBits[i]);
    }

    QString stopBits[3]={"1","1.5","2"};
    for(int i=0;i<3;i++)
    {
        window.ui->stopBits->addItem(stopBits[i]);
    }

    QString parity[5]={"NONE","ODD","EVEN","MARK","SPACE"};
    for(int i=0;i<5;i++)
    {
        window.ui->parity->addItem(parity[i]);
    }

  QObject::connect(window.ui->dataBits,SIGNAL(currentIndexChanged(int)),this,SLOT(getDataBits(int)));
  QObject::connect(window.ui->stopBits,SIGNAL(currentIndexChanged(int)),this,SLOT(getStopBits(int)));
  QObject::connect(window.ui->parity,SIGNAL(currentIndexChanged(int)),this,SLOT(getParity(int)));
  QObject::connect(window.ui->OK,SIGNAL(clicked()),this,SLOT(send()));

}

void SettingsInterface::getDataBits(int option)
{
    switch (option)
    {
    case 0:settings.dataBits=QSerialPort::Data6;break;
    case 1:settings.dataBits=QSerialPort::Data7;break;
    case 2:settings.dataBits=QSerialPort::Data8;break;
    }

}

void SettingsInterface::getStopBits(int option)
{

    switch (option)
    {
    case 0:settings.stopBits=QSerialPort::OneStop;break;
    case 1:settings.stopBits=QSerialPort::OneAndHalfStop;break;
    case 2:settings.stopBits=QSerialPort::TwoStop;break;
    }
}

void SettingsInterface::getParity(int option)
{
    switch (option)
    {
    case 0:settings.parity=QSerialPort::NoParity;break;
    case 1:settings.parity=QSerialPort::EvenParity;break;
    case 2:settings.parity=QSerialPort::OddParity;break;
    case 3:settings.parity=QSerialPort::MarkParity;break;
    case 4:settings.parity=QSerialPort::SpaceParity;break;
    }

}

void SettingsInterface::send()
{
    emit sendSettings(settings);
    hide();
}

void SettingsInterface::show()
{
    window.show();
}

void SettingsInterface::hide()
{
    window.hide();
}
