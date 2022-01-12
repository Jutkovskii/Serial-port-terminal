#include "interface.h"
#include <QObject>
#include <QDialog>


interface::interface(bool *getstatus1, bool *getstatus2,QObject *parent) : QObject(parent)
{
    delPort();
    window.show();
getAvailablePortsList();
hexSymPort1=hexSymPort2=0;
window.ui->outputPort1->setValidator(&hexVal);
window.ui->outputPort2->setValidator(&hexVal);
window.ui->intervalPort1->setValidator(&delayPort1);
window.ui->intervalPort2->setValidator(&delayPort2);
//установка начальных значений элементов диалогового окна
window.ui->namePort1->setCurrentIndex(-1);
window.ui->namePort2->setCurrentIndex(-1);
window.ui->baudPort1->setCurrentIndex(-1);
window.ui->baudPort2->setCurrentIndex(-1);
window.ui->disconnectPort1->setDisabled(1);
window.ui->disconnectPort2->setDisabled(1);
window.ui->sendPort1->setDisabled(1);
window.ui->sendPort2->setDisabled(1);
window.ui->cyclePort1->setDisabled(1);
window.ui->cyclePort2->setDisabled(1);
window.ui->hexPort1->setDisabled(1);
window.ui->hexPort2->setDisabled(1);
window.ui->symPort1->setDisabled(1);
window.ui->symPort2->setDisabled(1);
window.ui->intervalPort1->setDisabled(1);
window.ui->intervalPort2->setDisabled(1);
window.ui->hexPort1->setChecked(1);
window.ui->hexPort2->setChecked(1);
window.ui->clearInputPort1->setDisabled(1);
window.ui->clearOutputPort1->setDisabled(1);
window.ui->clearInputPort2->setDisabled(1);
window.ui->clearOutputPort2->setDisabled(1);

QObject::connect(window.ui->connectPort1,SIGNAL(clicked()),this,SLOT(getSignalToConnectPort1()));
QObject::connect(window.ui->connectPort2,SIGNAL(clicked()),this,SLOT(getSignalToConnectPort2()));
QObject::connect(window.ui->disconnectPort1,SIGNAL(clicked()),this,SLOT(getSignalToDisconnectPort1()));
QObject::connect(window.ui->disconnectPort2,SIGNAL(clicked()),this,SLOT(getSignalToDisconnectPort2()));
QObject::connect(window.ui->sendPort1,SIGNAL(clicked()),this,SLOT(getSignalToSendPort1()));
QObject::connect(window.ui->sendPort2,SIGNAL(clicked()),this,SLOT(getSignalToSendPort2()));
QObject::connect(window.ui->hexPort1,SIGNAL(clicked()),this,SLOT(hexCheckPort1()));
QObject::connect(window.ui->hexPort2,SIGNAL(clicked()),this,SLOT(hexCheckPort2()));
QObject::connect(window.ui->symPort1,SIGNAL(clicked()),this,SLOT(symCheckPort1()));
QObject::connect(window.ui->symPort2,SIGNAL(clicked()),this,SLOT(symCheckPort2()));
QObject::connect(window.ui->settingsPort1,SIGNAL(clicked()),this,SLOT(settingsOfPort1()));
QObject::connect(window.ui->settingsPort2,SIGNAL(clicked()),this,SLOT(settingsOfPort2()));

QObject::connect(window.ui->cyclePort1,SIGNAL(clicked()),this,SLOT(cycleCheckPort1()));
QObject::connect(window.ui->cyclePort2,SIGNAL(clicked()),this,SLOT(cycleCheckPort2()));

QObject::connect(window.ui->clearInputPort1,SIGNAL(clicked()),this,SLOT(clearInputPort1()));
QObject::connect(window.ui->clearInputPort2,SIGNAL(clicked()),this,SLOT(clearInputPort2()));
QObject::connect(window.ui->clearOutputPort1,SIGNAL(clicked()),this,SLOT(clearOutputPort1()));
QObject::connect(window.ui->clearOutputPort2,SIGNAL(clicked()),this,SLOT(clearOutputPort2()));

QObject::connect(window.ui->addPort,SIGNAL(clicked()),this,SLOT(addPort()));
QObject::connect(window.ui->delPort,SIGNAL(clicked()),this,SLOT(delPort()));


window.ui->intervalPort1->setText("3000");
window.ui->intervalPort2->setText("3000");

cyclePort1=cyclePort2=1;
statusPort1=getstatus1;
statusPort2=getstatus2;

}

void interface::getAvailablePortsList()
{
     QList<QSerialPortInfo> Ports=QSerialPortInfo::availablePorts();

    for(int i=0;i<Ports.size();i++)
     {
        if(!Ports[i].isBusy())
        {
        QString Port=Ports[i].portName();
        availablePortsList.append(Port);
        window.ui->namePort1->addItem(Port);
        window.ui->namePort2->addItem(Port);
        }

    }
    baudrate={110,300,600,1200,2400,4800,9600,14400,19200,38400,56000,57600,115200,128000,256000,460800,921600};
    for(int i=0;i<baudrate.size();i++)
    {
        QString Baud=QString::number(baudrate[i]);
        window.ui->baudPort1->addItem(Baud);
        window.ui->baudPort2->addItem(Baud);
    }
}

void interface::getSignalToConnectPort1()
{
if (window.ui->namePort1->currentIndex()>=0&&window.ui->baudPort1->currentIndex()>=0)
{
  emit connectPort1(availablePortsList[window.ui->namePort1->currentIndex()],baudrate[window.ui->baudPort1->currentIndex()]) ;
}
else
    {
    QMessageBox message;
    if(window.ui->namePort1->currentIndex()<0)
    {message.setText("Не выбран порт!");message.exec();}
    if(window.ui->baudPort1->currentIndex()<0)
    {message.setText("Не выбрана скорость!");message.exec();}
    }
}

void interface::getSignalToConnectPort2()
{
    if (window.ui->namePort2->currentIndex()>=0&&window.ui->baudPort2->currentIndex()>=0)

    {
       emit connectPort2(availablePortsList[window.ui->namePort2->currentIndex()],baudrate[window.ui->baudPort2->currentIndex()]) ;

    }
    else
        {
        QMessageBox message;
        if(window.ui->namePort2->currentIndex()<0)
        {message.setText("Не выбран порт!");message.exec();}
        if(window.ui->baudPort2->currentIndex()<0)
        {message.setText("Не выбрана скорость!");message.exec();}
        }
}

void interface::connectedToPort1(bool status)
{
    if (status)
    {
        window.ui->connectPort1->setDisabled(1);
        window.ui->disconnectPort1->setEnabled(1);
        window.ui->cyclePort1->setEnabled(1);
        window.ui->sendPort1->setEnabled(1);
        window.ui->hexPort1->setEnabled(1);
        window.ui->symPort1->setEnabled(1);
        window.ui->clearInputPort1->setEnabled(1);
        window.ui->clearOutputPort1->setEnabled(1);
    }
    else
    {
   emit disconnectPort1();
    }
}

void interface::connectedToPort2(bool status)
{
   if (status)
   {
       window.ui->connectPort2->setDisabled(1);
       window.ui->disconnectPort2->setEnabled(1);
       window.ui->cyclePort2->setEnabled(1);
       window.ui->sendPort2->setEnabled(1);
       window.ui->hexPort2->setEnabled(1);
       window.ui->symPort2->setEnabled(1);
       window.ui->clearInputPort2->setEnabled(1);
       window.ui->clearOutputPort2->setEnabled(1);
   }
   else
   {
 emit disconnectPort2();
   }
}

void interface::getSignalToDisconnectPort1()
{

    window.ui->connectPort1->setDisabled(0);
    window.ui->disconnectPort1->setEnabled(0);
    window.ui->cyclePort1->setEnabled(0);
    window.ui->sendPort1->setEnabled(0);
    window.ui->hexPort1->setDisabled(1);
    window.ui->symPort1->setDisabled(1);
    window.ui->clearInputPort1->setDisabled(1);
    window.ui->clearOutputPort1->setDisabled(1);

    emit disconnectPort1();
}

void interface::getSignalToDisconnectPort2()
{
    window.ui->connectPort2->setDisabled(0);
    window.ui->disconnectPort2->setEnabled(0);
    window.ui->cyclePort2->setEnabled(0);
    window.ui->sendPort2->setEnabled(0);
    window.ui->hexPort2->setDisabled(1);
    window.ui->symPort2->setDisabled(1);
    window.ui->clearInputPort2->setDisabled(1);
    window.ui->clearOutputPort2->setDisabled(1);
    emit disconnectPort2();
}

void interface::settingsOfPort1()
{
emit showSettingsPort1();
}

void interface::settingsOfPort2()
{
emit showSettingsPort2();
}

void interface::getSignalToSendPort1()
{
        if (cyclePort1)

        {
            QByteArray send;
            if(hexSymPort1)
            {
        QString text=window.ui->outputPort1->text();
        send=text.toUtf8();

            }
            else
            {


                //создание шестнадцатеричных значений из символов
                QString text=window.ui->outputPort1->text();

                text.remove(" ");
                send.resize(text.size());
                send.clear();
                for(int i=0;i<text.size();i++)
                {

                    if(text[2*i]=='0'){send[i]=send[i]|0x00;}
                    if(text[2*i]=='1'){send[i]=send[i]|0x10;}
                    if(text[2*i]=='2'){send[i]=send[i]|0x20;}
                    if(text[2*i]=='3'){send[i]=send[i]|0x30;}
                    if(text[2*i]=='4'){send[i]=send[i]|0x40;}
                    if(text[2*i]=='5'){send[i]=send[i]|0x50;}
                    if(text[2*i]=='6'){send[i]=send[i]|0x60;}
                    if(text[2*i]=='7'){send[i]=send[i]|0x70;}
                    if(text[2*i]=='8'){send[i]=send[i]|0x80;}
                    if(text[2*i]=='9'){send[i]=send[i]|0x90;}
                    if(text[2*i]=='A'){send[i]=send[i]|0xA0;}
                    if(text[2*i]=='B'){send[i]=send[i]|0xB0;}
                    if(text[2*i]=='C'){send[i]=send[i]|0xC0;}
                    if(text[2*i]=='D'){send[i]=send[i]|0xD0;}
                    if(text[2*i]=='E'){send[i]=send[i]|0xE0;}
                    if(text[2*i]=='F'){send[i]=send[i]|0xF0;}

                    if(text[2*i+1]=='0'){send[i]=send[i]|0x0;}
                    if(text[2*i+1]=='1'){send[i]=send[i]|0x1;}
                    if(text[2*i+1]=='2'){send[i]=send[i]|0x2;}
                    if(text[2*i+1]=='3'){send[i]=send[i]|0x3;}
                    if(text[2*i+1]=='4'){send[i]=send[i]|0x4;}
                    if(text[2*i+1]=='5'){send[i]=send[i]|0x5;}
                    if(text[2*i+1]=='6'){send[i]=send[i]|0x6;}
                    if(text[2*i+1]=='7'){send[i]=send[i]|0x7;}
                    if(text[2*i+1]=='8'){send[i]=send[i]|0x8;}
                    if(text[2*i+1]=='9'){send[i]=send[i]|0x9;}
                    if(text[2*i+1]=='A'){send[i]=send[i]|0xA;}
                    if(text[2*i+1]=='B'){send[i]=send[i]|0xB;}
                    if(text[2*i+1]=='C'){send[i]=send[i]|0xC;}
                    if(text[2*i+1]=='D'){send[i]=send[i]|0xD;}
                    if(text[2*i+1]=='E'){send[i]=send[i]|0xE;}
                    if(text[2*i+1]=='F'){send[i]=send[i]|0xF;}


                }


            }
QString interval=window.ui->intervalPort1->text();
            emit sendPort1(send,interval.toInt() );

        }

        if(window.ui->cyclePort1->isChecked())
        {
if(*statusPort1)
    *statusPort1=0;
else
    *statusPort1=1;

if(cyclePort1)
    cyclePort1=0;
else
    cyclePort1=1;
        }
        else
        {*statusPort1=0;cyclePort1=1;}

}

void interface::getSignalToSendPort2()
{
    if (cyclePort2)
    {
    QByteArray send;
    if(hexSymPort2)
    {
QString text=window.ui->outputPort2->text();
send=text.toUtf8();

    }
    else
    {
            //создание шестнадцатеричных значений из символов
        QString text=window.ui->outputPort2->text();


        text.remove(" ");
        send.resize(text.size());
        send.clear();
        for(int i=0;i<text.size();i++)
        {

            if(text[2*i]=='0'){send[i]=send[i]|0x00;}
            if(text[2*i]=='1'){send[i]=send[i]|0x10;}
            if(text[2*i]=='2'){send[i]=send[i]|0x20;}
            if(text[2*i]=='3'){send[i]=send[i]|0x30;}
            if(text[2*i]=='4'){send[i]=send[i]|0x40;}
            if(text[2*i]=='5'){send[i]=send[i]|0x50;}
            if(text[2*i]=='6'){send[i]=send[i]|0x60;}
            if(text[2*i]=='7'){send[i]=send[i]|0x70;}
            if(text[2*i]=='8'){send[i]=send[i]|0x80;}
            if(text[2*i]=='9'){send[i]=send[i]|0x90;}
            if(text[2*i]=='A'){send[i]=send[i]|0xA0;}
            if(text[2*i]=='B'){send[i]=send[i]|0xB0;}
            if(text[2*i]=='C'){send[i]=send[i]|0xC0;}
            if(text[2*i]=='D'){send[i]=send[i]|0xD0;}
            if(text[2*i]=='E'){send[i]=send[i]|0xE0;}
            if(text[2*i]=='F'){send[i]=send[i]|0xF0;}

            if(text[2*i+1]=='0'){send[i]=send[i]|0x0;}
            if(text[2*i+1]=='1'){send[i]=send[i]|0x1;}
            if(text[2*i+1]=='2'){send[i]=send[i]|0x2;}
            if(text[2*i+1]=='3'){send[i]=send[i]|0x3;}
            if(text[2*i+1]=='4'){send[i]=send[i]|0x4;}
            if(text[2*i+1]=='5'){send[i]=send[i]|0x5;}
            if(text[2*i+1]=='6'){send[i]=send[i]|0x6;}
            if(text[2*i+1]=='7'){send[i]=send[i]|0x7;}
            if(text[2*i+1]=='8'){send[i]=send[i]|0x8;}
            if(text[2*i+1]=='9'){send[i]=send[i]|0x9;}
            if(text[2*i+1]=='A'){send[i]=send[i]|0xA;}
            if(text[2*i+1]=='B'){send[i]=send[i]|0xB;}
            if(text[2*i+1]=='C'){send[i]=send[i]|0xC;}
            if(text[2*i+1]=='D'){send[i]=send[i]|0xD;}
            if(text[2*i+1]=='E'){send[i]=send[i]|0xE;}
            if(text[2*i+1]=='F'){send[i]=send[i]|0xF;}


        }


    }

    QString interval=window.ui->intervalPort2->text();
    emit sendPort2(send,interval.toInt());
    }

    if(window.ui->cyclePort2->isChecked())
    {
if(*statusPort2)
*statusPort2=0;
else
*statusPort2=1;

if(cyclePort2)
cyclePort2=0;
else
cyclePort2=1;
    }
    else
    {*statusPort2=0;cyclePort2=1;}
}

void interface::recieveDataFromPort1(QByteArray data)
{

QString recieved_message;
if(!data.isEmpty())
{
    if(window.ui->symPort1->isChecked())
    {
      recieved_message=QString::fromStdString(data.toStdString())  ;
    }
    else
    {
    for(int i=0;i<data.size();i++)
    {
        recieved_message+=QString::number(((ushort )data[i]&0xFF),16).toUpper();
        recieved_message+=" ";
    }
    }
    window.ui->inputPort1->insertPlainText(recieved_message);
}
}

void interface::recieveDataFromPort2(QByteArray data)
{
    QString recieved_message;
    if(!data.isEmpty())
    {
        if(window.ui->symPort2->isChecked())
        {
          recieved_message=QString::fromStdString(data.toStdString())  ;
        }
        else
        {
        for(int i=0;i<data.size();i++)
        {
            recieved_message+=QString::number(((ushort )data[i]&0xFF),16).toUpper();
            recieved_message+=" ";
        }
        }
        window.ui->inputPort2->insertPlainText(recieved_message);
    }
}

void interface::hexCheckPort1()
{
  hexSymPort1=0;
  window.ui->outputPort1->setValidator(&hexVal);
  window.ui->outputPort1->clear();
}

void interface::hexCheckPort2()
{
    hexSymPort2=0;
    window.ui->outputPort2->setValidator(&hexVal);
    window.ui->outputPort2->clear();
}

void interface::symCheckPort1()
{
    hexSymPort1=1;
    window.ui->outputPort1->setValidator(NULL);
    window.ui->outputPort1->clear();
}

void interface::symCheckPort2()
{
    hexSymPort2=1;
    window.ui->outputPort2->setValidator(NULL);
    window.ui->outputPort2->clear();
}

void interface::cycleCheckPort1()
{
    if (window.ui->cyclePort1->isChecked())
      window.ui->intervalPort1->setDisabled(0);
    else
        window.ui->intervalPort2->setDisabled(1);
}

void interface::cycleCheckPort2()
{
    if (window.ui->cyclePort2->isChecked())
      window.ui->intervalPort2->setDisabled(0);
    else
        window.ui->intervalPort2->setDisabled(1);
}

void interface::clearInputPort1()
{
  window.ui->inputPort1->clear();
}

void interface::clearInputPort2()
{
    window.ui->inputPort2->clear();
}

void interface::clearOutputPort1()
{
    window.ui->outputPort1->clear();
}

void interface::clearOutputPort2()
{
    window.ui->outputPort2->clear();
}

void interface::addPort()
{
    window.ui->Port2->setVisible(1);
    QSize size=window.size();
    size.setWidth(size.width()*2);
    window.setMaximumSize(size);
    window.setMinimumSize(size);
    window.resize(size);
    window.ui->addPort->setVisible(0);
    window.ui->delPort->setVisible(1);
    window.ui->line->setVisible(1);
}

void interface::delPort()
{
    window.ui->Port2->setVisible(0);
    QSize size=window.size();
    size.setWidth(size.width()/2);
    window.setMaximumSize(size);
    window.setMinimumSize(size);
    window.resize(size);
    window.ui->addPort->setVisible(1);
    window.ui->delPort->setVisible(0);
    window.ui->line->setVisible(0);
    clearOutputPort2();
    clearOutputPort2();
    clearOutputPort2();
    window.ui->namePort2->setCurrentIndex(-1);
    window.ui->baudPort2->setCurrentIndex(-1);
}
