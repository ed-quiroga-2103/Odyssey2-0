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

    DataManager* dataManager = new DataManager;

    pugi::xml_node getNotifications(pugi::xml_node node,string username );
    pugi::xml_node getFriends(pugi::xml_node node,string username);



public:

    XMLDoc* logInResponse(bool confirm, string username);
    XMLDoc* signIn(bool confirm);
    XMLDoc* searchSongResponse(int opnum, string name);
    XMLDoc* registerSongResponse(bool confirm);
    XMLDoc* deleteSongResponse(bool confirm);
    XMLDoc* confirmationResponse(bool confirm, int opnum);

    XMLDoc* getPaginatedSongs(int page, int opnum);
    XMLDoc* addFriendResponse(string username, bool confirm);
    XMLDoc* deleteFriendResponse(string username, bool confirm);


    pugi::xml_node getUserData(pugi::xml_node user, string username);
    pugi::xml_node getSongs(pugi::xml_node songsNode, int page);
    pugi::xml_node searchSongByName(pugi::xml_node song, string data);
    pugi::xml_node searchSongByArtist(pugi::xml_node song, string data);
    pugi::xml_node searchSongByAlbum(pugi::xml_node song, string data);

    //Metodos de lectura entrantes del cliente //

    string handleClientMessage(string data);
    int getOpNum(string str);
    string readSingIn(string data);
    string readSingUp(string data);
    string readSearchSong(string data);
    string readRegisterSong(string data);
    string readDeleteSong(string data);
    string readRegisterPlaylist(string data);
    string readDeletePlaylist(string data);
    string readAddFriend(string data);
    string readDeleteFriend(string data);
    string readRateSong(string data);
    //string readSendChunks(string data);
    string readSongListPaginacion(string data);
    string readUpdateMetadata(string data);
    string readUpdateUserData(string data);


};


#endif //XMLMANAGER_XMLMANAGER_H
