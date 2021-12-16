#include "homescreen.h"
#include "ui_homescreen.h"
#include <QMessageBox>

HomeScreen::HomeScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HomeScreen)
{
    ui->setupUi(this);
    createConnection();
}

HomeScreen::~HomeScreen()
{
    delete ui;
}

void HomeScreen::on_validateBtn_clicked()
{
    QString username = ui->usernameField->text();
    QString password = ui->passwordField->text();
    checkConnectionUser(username, password);

}



bool HomeScreen::createConnection()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("qt_database");
    db.setUserName("");
    db.setPassword("");
    if (!db.open()) {
        QMessageBox::critical(this, "Connexion", "Attention: probleme de connexion");
    }
    return true;

}

void HomeScreen::checkConnectionUser(QString username, QString password)
{
    if (db.open()){
        QSqlQuery query;
        query.exec("SELECT * FROM USER WHERE username =\"" + username + "\" AND password =\"" + password + "\";");

        if(query.next()){
            QMessageBox::critical(this, "Connexion", "User found");
        }else{
             QMessageBox::critical(this, "Connexion", "User not found");
        }
    }

}


