#include "dllpincode.h"
#include <QObject>
#include <QDebug>

void DLLPINCode::createDLLPINCodeObjects()
{
    objectDLLPINCodeLogWindow = new DLLPINCodeLogWindow;
    objectDLLPINCodeWindow = new DLLPINCodeWindow;
    objectDLLPINCodeTimerMain = new DLLPINCodeTimer;
}

void DLLPINCode::deleteDLLPINCodeObjects()
{
    delete objectDLLPINCodeLogWindow;
    objectDLLPINCodeLogWindow = 0;

    delete objectDLLPINCodeWindow;
    objectDLLPINCodeWindow = 0;

    delete objectDLLPINCodeTimerMain;
    objectDLLPINCodeTimerMain = 0;
}

void DLLPINCode::openDLLPINCodeEnterPinWindow()
{
    objectDLLPINCodeWindow->showFullScreen();
    objectDLLPINCodeTimerMain->DLLPINCodeTimerStart();
}

void DLLPINCode::hideDLLPINCodeEnterPinWindow()
{
    objectDLLPINCodeWindow->hide();
    objectDLLPINCodeWindow->clearLineEdit();
    objectDLLPINCodeTimerMain->DLLPINCodeTimerStop();
}

void DLLPINCode::SLOTHideDLLPINCodeEnterPinWindow()
{
    objectDLLPINCodeWindow->hide();
    objectDLLPINCodeWindow->clearLineEdit();
    objectDLLPINCodeTimerMain->DLLPINCodeTimerStop();
    emit signalExeToMakeConnectToSerial();
}

void DLLPINCode::openDLLPINCodeLogWindow()
{
    objectDLLPINCodeLogWindow->showFullScreen();
}

void DLLPINCode::hideDLLPINCodeLogWindow()
{
    objectDLLPINCodeLogWindow->hide();
}

void DLLPINCode::makeAllConnectionsInPinCodeDLL()
{
    connect (objectDLLPINCodeWindow, SIGNAL(signalbuttonIsClicked()), this, SLOT(setTimerTimeZero())); // Set timer time to zero, if button is clicked in pincode window

    connect (objectDLLPINCodeWindow, SIGNAL(signalEnterClicked()), this, SLOT(emitSignalToExe())); // If enter is clicked, check account from exe

    // Open language menu when "Kieli" button is clicked
    connect (objectDLLPINCodeLogWindow, SIGNAL(signalLanguageButtonIsClicked()), this, SLOT(emitSignalToExeToOpenLanguageMenu()));
    connect (objectDLLPINCodeWindow, SIGNAL(signalLanguageButtonIsClicked()), this, SLOT(emitSignalToExeToOpenLanguageMenu()));

    connect (objectDLLPINCodeTimerMain, SIGNAL(closePinCodeWindow()), this, SLOT(SLOTHideDLLPINCodeEnterPinWindow())); // Close PinCode window on time
}

void DLLPINCode::emitSignalToExeToOpenLanguageMenu()
{
    emit signalExeToOpenLanguageMenu();
}

void DLLPINCode::emitSignalToExe()
{
    emit signalExeFromPINCODE();
}

void DLLPINCode::setTimerTimeZero()
{
    objectDLLPINCodeTimerMain->ifButtonIsClicked();
}

QString DLLPINCode::returnAccount()
{
    QString account = objectDLLPINCodeWindow->returnString();

    return account;
}

void DLLPINCode::updateUIWindows()
{
    objectDLLPINCodeLogWindow->retranslateLogWindowUi();
    objectDLLPINCodeWindow->retranslatePinWindowUi();
}

bool DLLPINCode::checkIfLogWindowIsActive()
{
    if (objectDLLPINCodeLogWindow->isActiveWindow())
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
