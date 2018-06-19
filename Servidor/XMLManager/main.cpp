#include <iostream>
#include <QtCore/QCoreApplication>
#include <QtSql/qsqldatabase.h>
#include <QApplication>
#include <QDebug>
#include <QDomDocument>
#include "XMLParts.h"
#include "XMLManager.h"
#include "mainServer.h"

using Node = pugi::xml_node;

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    mainServer server(8081);

    return 0;
}
