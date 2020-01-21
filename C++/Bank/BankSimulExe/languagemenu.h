#ifndef LANGUAGEMENU_H
#define LANGUAGEMENU_H

#include <QWidget>
#include <QTranslator>
#include <QTimer>


namespace Ui {
class languagemenu;
}

class MainWindow;

class languagemenu : public QWidget
{
    Q_OBJECT

public:
    explicit languagemenu(QWidget *parent = 0);
    ~languagemenu();

public slots:
    void on_pushButtonFinnish_clicked();

    void on_pushButtonEnglish_clicked();

    void on_pushButton_clicked();

signals:
    changeLanguage();

private:
    Ui::languagemenu *ui;
    QTimer * timerLanguageMenu;
};

#endif // LANGUAGEMENU_H
