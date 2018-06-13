//
// Created by eduardo on 10/06/18.
//

#ifndef DataManager_DataManager_H
#define DataManager_DataManager_H

#include <HashClass.h>
#include "MySQLConnector.h"
#include "string"

using string = std::string;

class DataManager {
private:

    MySQLConnector* connector = new MySQLConnector("root", "85452565", "OdServer");
    HashClass hasher;

public:
//----------------------------------------------------------------------------------------------------------
    bool createUser(string username, string name, string password, int age, string favGen, string email);
    bool logUser(string username, string password);

//----------------------------------------------------------------------------------------------------------
    bool editSong(string name, string newName, string artist, string album, string lyrics);
    bool addSong(string name, string artist, string album, string lyrics);
//----------------------------------------------------------------------------------------------------------
    bool userExists(string username);
    bool songExists(string songname);

};


#endif //DataManager_DataManager_H
