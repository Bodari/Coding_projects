#include "languagemenu.h"
#include "ui_languagemenu.h"
#include <QDebug>

languagemenu::languagemenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::languagemenu)
{
    setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
}

languagemenu::~languagemenu()
{
    delete ui;
}

void languagemenu::on_pushButtonFinnish_clicked()
{
    QTranslator translator;
    translator.load("");    // Empty space parameter loads default language
    qApp->installTranslator(&translator);
    emit changeLanguage();

    this->close();
}

void languagemenu::on_pushButtonEnglish_clicked()
{
    QTranslator translator;
    translator.load(":/languages/Exe_english.qm");
    qApp->installTranslator(&translator);
    emit changeLanguage();

    QTranslator translatordll;
    translatordll.load(":/languages/PinCode_english.qm");
    qApp->installTranslator(&translatordll);
    emit changeLanguage();

    this->close();
}


void languagemenu::on_pushButton_clicked()
{
    this->close();
}
