#include "dllserialport.h"


void DLLSerialPort::DLLSerialFunctionsON()
{
    objectDllSerialPortFunctions = new DLLSerialPortFunctions;
    objectDllSerialPortFunctions->initDLLSerialPort();
}

void DLLSerialPort::DLLSerialFunctionsOFF()
{
    objectDllSerialPortFunctions->closeSerialPort();
    delete objectDllSerialPortFunctions;
    objectDllSerialPortFunctions = 0;
}

QString DLLSerialPort::returnCardID()
{
    QString cardID = objectDllSerialPortFunctions->returnString();
    return cardID;
}

void DLLSerialPort::connectSignalSerialRead()
{
    connect(objectDllSerialPortFunctions, SIGNAL(serialReadSignal()), this, SLOT(emitSignalToExe()));
}

void DLLSerialPort::emitSignalToExe()
{
    emit signalExe();
}

