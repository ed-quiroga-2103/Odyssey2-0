//
// Created by eduardo on 06/06/18.
//

#include "MySQLConnector.h"
#include <QtSql>
#include <QtCore/QCoreApplication>
#include <QtSql/qsqldatabase.h>
#include <QApplication>
#include <QDebug>


MySQLConnector::MySQLConnector(string username, string password, string database, QCoreApplication app) {

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName(database.c_str());
    db.setUserName(username.c_str());
    db.setPassword(password.c_str());

}

