#include <iostream>
#include <MySQLConnector.h>
#include "DataManager.h"

#include "string"

using string = std::string;

int main() {


    DataManager um;

    std::cout << um.createUser("CesarArce777", "Cesar Arce", "77", 18, "White Metal", "sample@email.com");
    std::cout << um.logUser("CesarArce777", "77");

    return 0;
}