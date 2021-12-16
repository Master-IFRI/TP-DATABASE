#ifndef HOMESCREEN_H
#define HOMESCREEN_H

#include <QDialog>
// this two includes to use database
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class HomeScreen;
}

class HomeScreen : public QDialog
{
    Q_OBJECT


public:
    explicit HomeScreen(QWidget *parent = 0);
    bool createConnection();
    void checkConnectionUser(QString, QString);
    ~HomeScreen();

private slots:
    void on_validateBtn_clicked();

private:
    Ui::HomeScreen *ui;
    QSqlDatabase db;
};

#endif // HOMESCREEN_H
