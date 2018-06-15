#include <iostream>
#include <MySQLConnector.h>
#include "DataManager.h"

#include "string"
using string = std::string;

int main() {
/*
    MySQLConnector sql("root", "85452565", "OdServer");

    QSqlQuery qr(sql.getDB());

    qr.exec("CREATE TABLE `Racso-nots` (name VARCHAR(30) NOT NULL);");
*/

    DataManager dm;

    std::cout << dm.rateSong("Suspect", 0);

    return 0;
}



