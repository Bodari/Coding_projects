#ifndef DLLSERIALPORT_H
#define DLLSERIALPORT_H

#include <QObject>
#include "dllserialportfunctions.h"
#include "dllserialport_global.h"

class DLLSERIALPORTSHARED_EXPORT DLLSerialPort : public QObject
{

Q_OBJECT

public:
    void DLLSerialFunctionsON();
    void DLLSerialFunctionsOFF();

    QString returnCardID();

    void connectSignalSerialRead();

public slots:
    void emitSignalToExe();

private:
    DLLSerialPortFunctions * objectDllSerialPortFunctions;

signals:
    void signalExe();

};

#endif // DLLSERIALPORT_H
