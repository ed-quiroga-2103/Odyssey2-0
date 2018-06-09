//
// Created by eduardo on 05/06/18.
//

#include <iostream>
#include <sstream>
#include "XMLManager.h"

using Node = pugi::xml_node;


XMLDoc *XMLManager::logInResponse(bool confirm, string username) {
    XMLDoc *doc = new XMLDoc("root");

    if(confirm) {
        Node data = doc->newChild("data");
        doc->newChild("op", 1);

        data.append_child("confirmation").append_child(pugi::node_pcdata).set_value(std::to_string(confirm).c_str());

        Node user = data.append_child("user");

        this->getUserData(user, username);

        Node songs = data.append_child("songs");

        this->getSongs(songs);

        Node nots = data.append_child("notifications");
        nots.append_child("notification").append_child("message").append_child(pugi::node_pcdata).set_value(
                "THIS IS A MESSAGE");
    }
    else{

        doc->newChild("confirmation", std::to_string(confirm).c_str());

    }
    return doc;

}

XMLDoc *XMLManager::signIn(bool confirm){

    XMLDoc *doc = new XMLDoc("root");

    doc->newChild("op", 0);
    doc->newChild("confirmation", std::to_string(confirm).c_str());

    return doc;
}

pugi::xml_node XMLManager::getSongs(pugi::xml_node songsNode) {

    QSqlQuery qry(connector->getDB());

    int i = 0;

    qry.exec("SELECT * FROM songs");
    while (qry.next() && i < 10) {

        pugi::xml_node currentNode = songsNode.append_child("song");

        string song = qry.value(0).toString().toStdString();
        string artist = qry.value(1).toString().toStdString();
        string album = qry.value(2).toString().toStdString();
        string lyrics = qry.value(3).toString().toStdString();

        currentNode.append_child("song").append_child(pugi::node_pcdata).set_value(song.c_str());
        currentNode.append_child("artist").append_child(pugi::node_pcdata).set_value(artist.c_str());
        currentNode.append_child("album").append_child(pugi::node_pcdata).set_value(album.c_str());
        currentNode.append_child("lyrics").append_child(pugi::node_pcdata).set_value(lyrics.c_str());

        i++;
    }

    return songsNode;



}

pugi::xml_node XMLManager::getUserData(pugi::xml_node user, string username){

    QSqlQuery qry(connector->getDB());

    std::stringstream stream;

    stream << "SELECT * FROM users WHERE username = \"";
    stream << username;
    stream << "\"";

    qry.exec(stream.str().c_str());
    while (qry.next()) {

        string usrname = qry.value(0).toString().toStdString();
        string name = qry.value(1).toString().toStdString();
        string pass = qry.value(2).toString().toStdString();
        string email = qry.value(3).toString().toStdString();

        user.append_child("username").append_child(pugi::node_pcdata).set_value(usrname.c_str());
        user.append_child("name").append_child(pugi::node_pcdata).set_value(name.c_str());
        user.append_child("password").append_child(pugi::node_pcdata).set_value(pass.c_str());
        user.append_child("email").append_child(pugi::node_pcdata).set_value(email.c_str());

    }

    return user;

}

XMLDoc *XMLManager::searchSongResponse(int opnum, string name) {

    XMLDoc* doc = new XMLDoc("root");

    doc->newChild("op",opnum);

    Node data = doc->newChild("data");

    switch (opnum){

        case 5:

            searchSongByName(data, name);
            break;

        case 6:

            searchSongByArtist(data, name);
            break;

        case 7:

            searchSongByAlbum(data, name);
            break;
    }

    return doc;

}

pugi::xml_node XMLManager::searchSongByAlbum(pugi::xml_node song, string data) {

    QSqlQuery qry(connector->getDB());

    std::stringstream stream;

    stream << "SELECT * FROM songs WHERE album = \"";
    stream << data;
    stream << "\"";

    qry.exec(stream.str().c_str());
    while (qry.next()) {

        string songName = qry.value(0).toString().toStdString();
        string artist = qry.value(1).toString().toStdString();
        string album = qry.value(2).toString().toStdString();
        string lyrics = qry.value(3).toString().toStdString();

        song.append_child("username").append_child(pugi::node_pcdata).set_value(songName.c_str());
        song.append_child("name").append_child(pugi::node_pcdata).set_value(artist.c_str());
        song.append_child("password").append_child(pugi::node_pcdata).set_value(album.c_str());
        song.append_child("email").append_child(pugi::node_pcdata).set_value(lyrics.c_str());

    }

    return song;

}

pugi::xml_node XMLManager::searchSongByArtist(pugi::xml_node song, string data) {

    QSqlQuery qry(connector->getDB());

    std::stringstream stream;

    stream << "SELECT * FROM songs WHERE artist = \"";
    stream << data;
    stream << "\"";

    qry.exec(stream.str().c_str());
    while (qry.next()) {

        string songName = qry.value(0).toString().toStdString();
        string artist = qry.value(1).toString().toStdString();
        string album = qry.value(2).toString().toStdString();
        string lyrics = qry.value(3).toString().toStdString();

        song.append_child("song").append_child(pugi::node_pcdata).set_value(songName.c_str());
        song.append_child("artist").append_child(pugi::node_pcdata).set_value(artist.c_str());
        song.append_child("album").append_child(pugi::node_pcdata).set_value(album.c_str());
        song.append_child("lyrics").append_child(pugi::node_pcdata).set_value(lyrics.c_str());

    }

    return song;

}

pugi::xml_node XMLManager::searchSongByName(pugi::xml_node song, string data) {

    QSqlQuery qry(connector->getDB());

    std::stringstream stream;

    stream << "SELECT * FROM songs WHERE name = \"";
    stream << data;
    stream << "\"";

    qry.exec(stream.str().c_str());
    while (qry.next()) {

        string songName = qry.value(0).toString().toStdString();
        string artist = qry.value(1).toString().toStdString();
        string album = qry.value(2).toString().toStdString();
        string lyrics = qry.value(3).toString().toStdString();

        song.append_child("song").append_child(pugi::node_pcdata).set_value(songName.c_str());
        song.append_child("artist").append_child(pugi::node_pcdata).set_value(artist.c_str());
        song.append_child("album").append_child(pugi::node_pcdata).set_value(album.c_str());
        song.append_child("lyrics").append_child(pugi::node_pcdata).set_value(lyrics.c_str());

    }

    return song;

}

XMLDoc* XMLManager::registerSongResponse(bool confirm) {
    XMLDoc *doc = new XMLDoc("root");

    if(confirm) {

        doc->newChild("op", 1);
        doc->newChild("confirmation", std::to_string(confirm).c_str());
        Node data = doc->newChild("data");

        Node songs = doc->newChild("songs");
        this->getSongs(songs);

        data.append_child(data.type());

    }
    else{

        doc->newChild("confirmation", std::to_string(confirm).c_str());

    }
    return doc;

}
