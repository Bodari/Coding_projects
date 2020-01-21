#ifndef DLLPINCODEWINDOW_H
#define DLLPINCODEWINDOW_H

#include <QWidget>

namespace Ui {
class DLLPINCodeWindow;
}

class DLLPINCodeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DLLPINCodeWindow(QWidget *parent = 0);
    ~DLLPINCodeWindow();

    void clearLineEdit();

    QString returnString();

    void retranslatePinWindowUi();

signals:
    void signalEnterClicked();
    void signalbuttonIsClicked();

    void signalLanguageButtonIsClicked();

private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_0_clicked();
    void on_pushButtonBackSpace_clicked();

    void on_pushButtonAccept_clicked();

    void on_pushButtonLanguage_clicked();

private:
    Ui::DLLPINCodeWindow *ui;

    QString account;
};

#endif // DLLPINCODEWINDOW_H
