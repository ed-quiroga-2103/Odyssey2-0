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

    QSqlDatabase getDB(){

        return connector->getDB();

    }

//----------------------------------------------------------------------------------------------------------
    bool createUser(string username, string name, string password, int age, string favGen, string email);
    bool logUser(string username, string password);
    bool addFriend(string username, string friendUsername);
    bool deleteFriend(string username, string friendUsername);
    bool updateUser(string username,string password);
//----------------------------------------------------------------------------------------------------------
    bool editSong(string name, string newName, string artist, string album, string lyrics);
    bool addSong(string name, string artist, string album, string lyrics);
    bool deleteSong(string name);
    bool rateSong(string name, int rating);
//----------------------------------------------------------------------------------------------------------
    bool userExists(string username);
    bool songExists(string songname);

    bool createFriendsTable(string username);
    bool createNotsTable(string username);
};


#endif //DataManager_DataManager_H
