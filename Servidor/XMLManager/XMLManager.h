//
// Created by eduardo on 05/06/18.
//

#ifndef XMLMANAGER_XMLMANAGER_H
#define XMLMANAGER_XMLMANAGER_H

#include "XMLParts.h"
#include "string"
#include "../MySQLConnector/MySQLConnector.h"

using string = std::string;

class XMLManager {
private:

    MySQLConnector* connector = new MySQLConnector("root", "85452565", "users");

//-----------------FALTA-----------------
    pugi::xml_node getNotifications();
    pugi::xml_node getFriends();
//---------------------------------------
public:

    XMLDoc* logInResponse(bool confirm, string username);
    XMLDoc* signIn(bool confirm);
    XMLDoc* searchSongResponse(int opnum, string name);
    XMLDoc* registerSongResponse(bool confirm);
    XMLDoc* deleteSongResponse(bool confirm);


    pugi::xml_node getUserData(pugi::xml_node user, string username);
    pugi::xml_node getSongs(pugi::xml_node songsNode, int page);

    pugi::xml_node searchSongByName(pugi::xml_node song, string data);
    pugi::xml_node searchSongByArtist(pugi::xml_node song, string data);
    pugi::xml_node searchSongByAlbum(pugi::xml_node song, string data);


};


#endif //XMLMANAGER_XMLMANAGER_H
