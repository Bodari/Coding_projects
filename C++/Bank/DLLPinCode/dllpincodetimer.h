#ifndef DLLPINCODETIMER_H
#define DLLPINCODETIMER_H

#include <QObject>
#include <QTimer>

class DLLPINCodeTimer : public QObject
{
    Q_OBJECT

public:
    void DLLPINCodeTimerStart();
    void DLLPINCodeTimerStop();

public slots:
    void ifNoButtonIsClicked();
    void ifButtonIsClicked();

private:
    DLLPINCodeTimer * objectDLLPINCodeTimer;
    QTimer * timerPIN;
    int time = 0;

signals:
    void closePinCodeWindow();
};

#endif // DLLPINCODETIMER_H
