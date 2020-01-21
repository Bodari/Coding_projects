#ifndef DLLSERIALPORTFUNCTIONS_H
#define DLLSERIALPORTFUNCTIONS_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QByteArray>
#include <QDebug>
#include <QTextCodec>

class DLLSerialPortFunctions : public QObject
{
    Q_OBJECT

public:
    void initDLLSerialPort();
    QString returnString();
    void closeSerialPort();

private slots:
    void openSerialPort();
    void readData();

private:
    QSerialPort *serial;
    QString cardID;

signals:
    void serialReadSignal();

};

#endif // DLLSERIALPORTFUNCTIONS_H
