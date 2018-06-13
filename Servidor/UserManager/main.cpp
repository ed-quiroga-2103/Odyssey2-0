#include <iostream>
#include <MySQLConnector.h>
#include "UserManager.h"

#include "string"

using string = std::string;

int main() {


    UserManager um;

    std::cout << um.createUser("CesarArce777", "Cesar Arce", "77", 18, "White Metal", "sample@email.com");
    std::cout << um.logUser("CesarArce777", "77");

    return 0;
}