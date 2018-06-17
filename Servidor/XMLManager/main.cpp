#include <iostream>
#include <QtCore/QCoreApplication>
#include <QtSql/qsqldatabase.h>
#include <QApplication>
#include <QDebug>
#include <QDomDocument>
#include "XMLParts.h"
#include "XMLManager.h"

using Node = pugi::xml_node;

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    XMLManager xml;

    XMLDoc doc("root");

    doc.newChild("op", 0);

    Node data = doc.newChild("data");

    Node user = data.append_child("user");

    user.append_child("name").append_child(pugi::node_pcdata).set_value("TestName");

    user.append_child("username").append_child(pugi::node_pcdata).set_value("TestUser2");

    user.append_child("age").append_child(pugi::node_pcdata).set_value("18");

    user.append_child("password").append_child(pugi::node_pcdata).set_value("PASSWORD");

    user.append_child("email").append_child(pugi::node_pcdata).set_value("test@mail.com");

    std::cout << doc.toString();

    xml.handleClientMessage(doc.toString());


    return 0;
}
