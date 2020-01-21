#ifndef DLLPINCODE_H
#define DLLPINCODE_H

#include "dllpincode_global.h"
#include "dllpincodelogwindow.h"
#include "dllpincodewindow.h"
#include "dllpincodetimer.h"
#include <QObject>

class DLLPINCODESHARED_EXPORT DLLPINCode : public QObject
{

    Q_OBJECT

public:

    void createDLLPINCodeObjects();
    void deleteDLLPINCodeObjects();

    void openDLLPINCodeEnterPinWindow();
    void openDLLPINCodeLogWindow();

    void hideDLLPINCodeEnterPinWindow();
    void hideDLLPINCodeLogWindow();

    QString returnAccount();

    void updateUIWindows();

    void makeAllConnectionsInPinCodeDLL();

    bool checkIfLogWindowIsActive();

private slots:
    void SLOTHideDLLPINCodeEnterPinWindow();

public slots:
    void emitSignalToExe();
    void setTimerTimeZero();
    void emitSignalToExeToOpenLanguageMenu();

signals:
    void signalExeFromPINCODE();
    void signalExeToOpenLanguageMenu();
    void signalExeToMakeConnectToSerial();

private:
    DLLPINCodeLogWindow * objectDLLPINCodeLogWindow;
    DLLPINCodeWindow * objectDLLPINCodeWindow;
    DLLPINCodeTimer * objectDLLPINCodeTimerMain;

    QString account;
};

#endif // DLLPINCODE_H
