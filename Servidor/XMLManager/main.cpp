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


    XMLDoc* doc = xml.getPaginatedSongs(0);

    std::cout << doc->toString();

    return 0;
}
