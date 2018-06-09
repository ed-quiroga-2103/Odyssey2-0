//
// Created by eduardo on 06/06/18.
//

#include "MySQLConnector.h"
#include <QtSql>
#include <QtCore/QCoreApplication>
#include <QtSql/qsqldatabase.h>
#include <QApplication>
#include <QDebug>


MySQLConnector::MySQLConnector(string username, string password, string database) {

    db.setHostName("localhost");
    db.setDatabaseName(database.c_str());
    db.setUserName(username.c_str());
    db.setPassword(password.c_str());
    db.open();
}

void MySQLConnector::print() {

    QSqlDatabase db = this->getDB();

    QSqlQuery qry(db);

    qry.exec("SELECT * FROM songs");

    while (qry.next()) {
        QString name = qry.value(0).toString();
        QString salary = qry.value(1).toString();
        qDebug() << name << salary;
    }


}
