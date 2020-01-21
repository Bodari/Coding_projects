#ifndef DLLPINCODELOGWINDOW_H
#define DLLPINCODELOGWINDOW_H

#include <QWidget>

namespace Ui {
class DLLPINCodeLogWindow;
}

class DLLPINCodeLogWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DLLPINCodeLogWindow(QWidget *parent = 0);
    ~DLLPINCodeLogWindow();

    void retranslateLogWindowUi();

signals:
    void signalLanguageButtonIsClicked();

private slots:
    void on_pushButtonLanguage_clicked();

private:
    Ui::DLLPINCodeLogWindow *ui;

    QString labelTextEng = "READ THE CARD";
};

#endif // DLLPINCODELOGWINDOW_H
