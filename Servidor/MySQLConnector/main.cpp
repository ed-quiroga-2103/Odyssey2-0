#include <iostream>
#include <QtSql>
#include <QtCore/QCoreApplication>
#include <QtSql/qsqldatabase.h>
#include <QApplication>
#include <QDebug>
#include "MySQLConnector.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    MySQLConnector connector("root", "85452565", "users");

    connector.print();

    return 0;
}