//
// Created by eduardo on 05/06/18.
//

#ifndef XMLMANAGER_XMLMANAGER_H
#define XMLMANAGER_XMLMANAGER_H

#include <DataManager.h>
#include "XMLParts.h"
#include "string"
#include "../MySQLConnector/MySQLConnector.h"

using string = std::string;
using namespace std;

class XMLManager {
private:

    MySQLConnector* connector = new MySQLConnector("root", "85452565", "OdServer");

    DataManager* dataManager = new DataManager;

//-----------------FALTA-----------------
    pugi::xml_node getNotifications();
    pugi::xml_node getFriends();
//---------------------------------------
public:

    XMLDoc* logInResponse(bool confirm, string username);
    XMLDoc* signUp(bool confirm);
    XMLDoc* searchSongResponse(int opnum, string name);
    XMLDoc* registerSongResponse(bool confirm);
    XMLDoc* deleteSongResponse(bool confirm);

    XMLDoc* getPaginatedSongs(int page);

    pugi::xml_node getUserData(pugi::xml_node user, string username);
    pugi::xml_node getSongs(pugi::xml_node songsNode, int page);
    pugi::xml_node searchSongByName(pugi::xml_node song, string data);
    pugi::xml_node searchSongByArtist(pugi::xml_node song, string data);
    pugi::xml_node searchSongByAlbum(pugi::xml_node song, string data);

    //Metodos de lectura entrantes del cliente //

    void *handleClientMessage(string data);
    int getOpNum(string str);
    void*readSingIn(string data);
    void *readSingUp(string data);
    void *readSearchSong(string data);
    void *readRegisterSong(string data);
    void *readDeleteSong(string data);
    void *readRegisterPlaylist(string data);
    void *readDeletePlaylist(string data);
    void *readAddFriend(string data);
    void *readDeleteFriend(string data);
    void *readRateSong(string data);
    void *readSendChunks(string data);
    void *readSongListPaginacion(string data);
    void *readUpdateMetadata(string data);
    void *readUpdateUserData(string data);


};


#endif //XMLMANAGER_XMLMANAGER_H
