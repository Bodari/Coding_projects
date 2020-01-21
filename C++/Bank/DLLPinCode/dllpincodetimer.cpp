#include "dllpincodetimer.h"
#include <QDebug>

void DLLPINCodeTimer::DLLPINCodeTimerStart()
{
    time = 0;
    timerPIN = new QTimer;
    timerPIN->start(1000);
    connect(timerPIN, SIGNAL(timeout()), this, SLOT(ifNoButtonIsClicked()));
}

void DLLPINCodeTimer::DLLPINCodeTimerStop()
{
    timerPIN->stop();
    disconnect(timerPIN, SIGNAL(timeout()), this, SLOT(ifNoButtonIsClicked()));
    delete timerPIN;
}

void DLLPINCodeTimer::ifNoButtonIsClicked()
{
    time++;

    if (time == 10)
    {
        emit closePinCodeWindow();
    }
}

void DLLPINCodeTimer::ifButtonIsClicked()
{
    time = 0;
}

