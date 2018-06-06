#include <iostream>
#include <QtCore/QCoreApplication>
#include <QtSql/qsqldatabase.h>
#include <QApplication>
#include <QDebug>
#include <QDomDocument>
#include "XMLParts.h"

int main() {


    XMLDoc doc("root");

    XMLDoc child("user");

    child.newChild("username","USERNAME");
    child.newChild("pass","PASS");

    doc.newChild("User","USERXML");
    doc.newChild("Songs","SONGSXML");

    doc.newChild("Notifications",doc.remove_extra_whitespaces(child.toString()).c_str());

    std::cout << doc.toString();

    return 0;
}
