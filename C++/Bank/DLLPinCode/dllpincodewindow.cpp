#include "dllpincodewindow.h"
#include "ui_dllpincodewindow.h"
#include <QDebug>

DLLPINCodeWindow::DLLPINCodeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DLLPINCodeWindow)
{
    ui->setupUi(this);
}

DLLPINCodeWindow::~DLLPINCodeWindow()
{
    delete ui;
}

void DLLPINCodeWindow::on_pushButton_1_clicked()
{
    ui->lineEdit->insert("1");
    emit signalbuttonIsClicked();
}

void DLLPINCodeWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->insert("2");
    emit signalbuttonIsClicked();
}

void DLLPINCodeWindow::on_pushButton_3_clicked()
{
    ui->lineEdit->insert("3");
    emit signalbuttonIsClicked();
}

void DLLPINCodeWindow::on_pushButton_4_clicked()
{
    ui->lineEdit->insert("4");
    emit signalbuttonIsClicked();
}

void DLLPINCodeWindow::on_pushButton_5_clicked()
{
    ui->lineEdit->insert("5");
    emit signalbuttonIsClicked();
}

void DLLPINCodeWindow::on_pushButton_6_clicked()
{
    ui->lineEdit->insert("6");
    emit signalbuttonIsClicked();
}

void DLLPINCodeWindow::on_pushButton_7_clicked()
{
    ui->lineEdit->insert("7");
    emit signalbuttonIsClicked();
}

void DLLPINCodeWindow::on_pushButton_8_clicked()
{
    ui->lineEdit->insert("8");
    emit signalbuttonIsClicked();
}

void DLLPINCodeWindow::on_pushButton_9_clicked()
{
    ui->lineEdit->insert("9");
    emit signalbuttonIsClicked();
}

void DLLPINCodeWindow::on_pushButton_0_clicked()
{
    ui->lineEdit->insert("0");
    emit signalbuttonIsClicked();
}

void DLLPINCodeWindow::on_pushButtonBackSpace_clicked()
{
    ui->lineEdit->backspace();
    emit signalbuttonIsClicked();
}

void DLLPINCodeWindow::on_pushButtonAccept_clicked()
{
    account = ui->lineEdit->text();
    emit signalEnterClicked();
    emit clearLineEdit();

}

void DLLPINCodeWindow::clearLineEdit()
{
    ui->lineEdit->clear();
    qDebug() << "LineEdit clearattu";
}

QString DLLPINCodeWindow::returnString()
{
    return account;
}

void DLLPINCodeWindow::retranslatePinWindowUi()
{
    ui->retranslateUi(this);
}

void DLLPINCodeWindow::on_pushButtonLanguage_clicked()
{
    emit signalbuttonIsClicked();
    emit signalLanguageButtonIsClicked();
}
