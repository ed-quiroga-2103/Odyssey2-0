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

    server.runServer();
/*
    XMLManager man;

    std::cout <<  man.logInResponse(true, "user")->toString();
/*
    DataManager mn;

    std::cout << mn.addFriend("user", "TestUser2");
*/

    return 0;
}
