#include <iostream>
#include <QtSql>
#include <QtCore/QCoreApplication>
#include <QtSql/qsqldatabase.h>
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("users");
    db.setUserName("root");
    db.setPassword("85452565");
    bool ok = db.open();

    qDebug() << ok;

    QSqlQuery qry(db);

    qry.exec("SELECT * FROM users");

    while (qry.next()) {
        QString name = qry.value(0).toString();
        QString salary = qry.value(1).toString();
        qDebug() << name << salary;
    }
    return 0;
}