//
// Created by eduardo on 10/06/18.
//

#ifndef USERMANAGER_USERMANAGER_H
#define USERMANAGER_USERMANAGER_H

#include <HashClass.h>
#include "MySQLConnector.h"
#include "string"

using string = std::string;

class UserManager {
private:

    MySQLConnector* connector = new MySQLConnector("root", "85452565", "OdServer");
    HashClass hasher;

public:
//----------------------------------------------------------------------------------------------------------
    bool createUser(string username, string name, string password, int age, string favGen, string email);
    bool logUser(string username, string password);
//----------------------------------------------------------------------------------------------------------
    bool userExists(string username);
};


#endif //USERMANAGER_USERMANAGER_H
