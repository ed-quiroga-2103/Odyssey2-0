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
    QSqlDatabase db;

public:
    MySQLConnector(string username, string password, string database, QCoreApplication ap);

    void print();

};


#endif //MYSQLCONNECTOR_MYSQLCONNECTOR_H
