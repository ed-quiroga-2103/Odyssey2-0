//
// Created by eduardo on 06/06/18.
//

#ifndef MYSQLCONNECTOR_MYSQLCONNECTOR_H
#define MYSQLCONNECTOR_MYSQLCONNECTOR_H

#include "string"
#include <QtSql>
#include <QtCore/QCoreApplication>
#include <QtSql/qsqldatabase.h>
#include <QApplication>
#include <QDebug>

using string = std::string;

class MySQLConnector {
private:
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

public:
    MySQLConnector(string username, string password, string database);

    QSqlDatabase getDB(){

        return (this->db);

    };

};


#endif //MYSQLCONNECTOR_MYSQLCONNECTOR_H
