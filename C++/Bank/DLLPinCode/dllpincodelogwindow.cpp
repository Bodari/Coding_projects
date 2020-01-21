#include "dllpincodelogwindow.h"
#include "ui_dllpincodelogwindow.h"

DLLPINCodeLogWindow::DLLPINCodeLogWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DLLPINCodeLogWindow)
{
    ui->setupUi(this);
}

DLLPINCodeLogWindow::~DLLPINCodeLogWindow()
{
    delete ui;
}

void DLLPINCodeLogWindow::retranslateLogWindowUi()
{
    ui->retranslateUi(this);
}

void DLLPINCodeLogWindow::on_pushButtonLanguage_clicked()
{
    emit signalLanguageButtonIsClicked();
}

