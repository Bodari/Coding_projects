#include "dllserialportfunctions.h"

void DLLSerialPortFunctions::initDLLSerialPort()
{
    serial = new QSerialPort;
    connect(serial, &QSerialPort::readyRead, this, &DLLSerialPortFunctions::readData);
    openSerialPort();
}

void DLLSerialPortFunctions::openSerialPort()
{
    Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts())
    {
        serial->setPortName(port.portName());
    }
    //serial->setPortName("COM4");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if(serial->open(QIODevice::ReadWrite))
    {
        qDebug() << ("SerialPort Connected");
    }
    else
    {
        qDebug() << ("SerialPort Failed to connect");
    }
}

void DLLSerialPortFunctions::closeSerialPort()
{
    if (serial->isOpen())
        serial->close();
    qDebug() << ("Disconnected");
    disconnect(serial, &QSerialPort::readyRead, this, &DLLSerialPortFunctions::readData);
}

void DLLSerialPortFunctions::readData()
{
    QByteArray data = serial->readAll();
    QString string = QTextCodec::codecForMib(106)->toUnicode(data);
        string.remove("-");
        string.remove("\r");
        string.remove("\n");
        string.remove(">");
    qDebug() << string;
    cardID = string;
    emit serialReadSignal();
}

QString DLLSerialPortFunctions::returnString()
{
    return cardID;
}
