#include <iostream>
#include <QtCore/QCoreApplication>
#include <QtSql/qsqldatabase.h>
#include <QApplication>
#include <QDebug>
#include <QDomDocument>
#include "XMLParts.h"
#include "XMLManager.h"

using Node = pugi::xml_node;

int main() {

/*
    XMLDoc doc("root");

    doc.newChild("User","USERXML");
    doc.newChild("Songs","SONGSXML");

    pugi::xml_node sub = doc.newChild("Notifications");

    pugi::xml_node child = sub.append_child("Notification");

    pugi::xml_node asd = child.append_child("User").append_child("Lapices");

    asd.append_child(pugi::node_pcdata).set_value("Holi");

    child.append_attribute("name") = 1;

    std::cout << doc.toString();
*/

/*
<root>
    <op>#<op>
    <confirmation>true/false</confirmation>
    <user>
        <name>somename</name>
        <username>someusername</username>
        <age>someage</age>
        <email>someemail</email>
        <image64>someimage</image64>
        <friends>friendlist</friends>
    </user>
    <notifications>
        <notification>
            <message>something</message>
        </notification>
        ...
    </notifications>
</root>
*/
    XMLManager xml;

    XMLDoc* doc = xml.logInResponse(true, "USERNAME");


    std::cout << doc->toString();

    return 0;
}
