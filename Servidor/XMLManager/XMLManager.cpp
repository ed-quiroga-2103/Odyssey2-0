//
// Created by eduardo on 05/06/18.
//

#include <iostream>
#include <sstream>
#include "XMLManager.h"

using Node = pugi::xml_node;
//METODOS DE LECTURA ENTRATES//

int XMLManager::getOpNum(string str) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_string(str.c_str());

    return std::stoi(doc.child("op").text().get());
}


void *XMLManager::readSearchSong(string data){

    pugi::xml_document doc;

    pugi::xml_parse_result result = doc.load_string(data.c_str());

    string song_name = doc.child("data").child("song").child("name").text().get();

    std::cout <<"The song name is:"<<song_name<< std::endl;

}

void *XMLManager::readRegisterPlaylist(string data){

    pugi::xml_document doc;

    pugi::xml_parse_result result = doc.load_string(data.c_str());

    string user_name = doc.child("data").child("user").child("name").text().get();

    string playlist_name = doc.child("data").child("playlist").child("name").text().get();

    string date_name = doc.child("data").child("playlist").child("date").text().get();

    std::cout <<"The username is:"<< user_name << std::endl;

    std::cout <<"The playlist name is:"<< playlist_name << std::endl;

    std::cout <<"The date name is:"<< date_name << std::endl;
}

void *XMLManager::readDeletePlaylist(string data){

    pugi::xml_document doc;

    pugi::xml_parse_result result = doc.load_string(data.c_str());

    string user_name = doc.child("data").child("user").child("name").text().get();

    string playlist_name = doc.child("data").child("playlist").child("name").text().get();

    std::cout <<"The username for delete playlist is:"<< user_name << std::endl;

    std::cout <<"The playlist for delete name is:"<< playlist_name << std::endl;

}
void *XMLManager::readAddFriend(string data){

}
void *XMLManager::readDeleteSong(string data){

    pugi::xml_document doc;

    pugi::xml_parse_result result = doc.load_string(data.c_str());

    string Songname = doc.child("data").child("song").child("name").text().get();



    std::cout <<"The Song name for delete is:"<<Songname<< std::endl;

}

void *XMLManager::readRegisterSong(string data){

    pugi::xml_document doc;

    pugi::xml_parse_result result = doc.load_string(data.c_str());

    string Songname = doc.child("data").child("song").child("name").text().get();

    string artist = doc.child("data").child("song").child("artist").text().get();

    string album = doc.child("data").child("song").child("album").text().get();

    string lyrics = doc.child("data").child("song").child("lyrics").text().get();

    string SongBytes = doc.child("data").child("song").child("file64").text().get();

    std::cout <<"The Song name is:"<<Songname<< std::endl;
    std::cout <<"The artist is:"<< artist<< std::endl;
    std::cout <<"The album is:"<< album << std::endl;
    std::cout <<"The lyrics is:"<< lyrics << std::endl;
    std::cout <<"The Bytes is:"<< SongBytes << std::endl;
}

void *XMLManager::readSingUp(string data){

    pugi::xml_document doc;

    pugi::xml_parse_result result = doc.load_string(data.c_str());

    string name = doc.child("data").child("user").child("name").text().get();

    string username = doc.child("data").child("user").child("username").text().get();

    string age = doc.child("data").child("user").child("age").text().get();

    string password = doc.child("data").child("user").child("password").text().get();

    string email = doc.child("data").child("user").child("email").text().get();

    std::cout <<"The name is:"<<name<< std::endl;
    std::cout <<"The username is:"<<username<< std::endl;
    std::cout <<"The age is:"<<age<< std::endl;
    std::cout <<"The password is:"<< password << std::endl;
    std::cout <<"The email is:"<< email << std::endl;
}
void *XMLManager::readSingIn(string data){
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_string(data.c_str());

    string username = doc.child("data").child("user").child("username").text().get();

    string password = doc.child("data").child("user").child("password").text().get();

    std::cout <<"The username is:"<<username<< std::endl;
    std::cout <<"The password is:"<<password<< std::endl;
}
void *XMLManager::readDeleteFriend(string data){
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_string(data.c_str());

    string username = doc.child("data").child("user").child("name").text().get();

    std::cout <<"The username for delete friend is:"<<username<< std::endl;

}
void *XMLManager::readRateSong(string data){
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_string(data.c_str());
    string name = doc.child("data").child("song").child("name").text().get();
    string votes = doc.child("data").child("song").child("votes").text().get();
    string sum = doc.child("data").child("song").child("sum").text().get();
    string rating = doc.child("data").child("song").child("rating").text().get();

    std::cout <<"The name for rate song is:"<<name<< std::endl;
    std::cout <<"The votes for rate song is:"<<votes<< std::endl;
    std::cout <<"The sum for rate song is:"<<sum<< std::endl;
    std::cout <<"The rating for rate song is:"<<rating<< std::endl;
}

// FINAL DE METODOS DE LECTURA ENTRANTES //

XMLDoc *XMLManager::logInResponse(bool confirm, string username) {
    XMLDoc *doc = new XMLDoc("root");

    if(confirm) {
        Node data = doc->newChild("data");
        doc->newChild("op", 1);

        data.append_child("confirmation").append_child(pugi::node_pcdata).set_value(std::to_string(confirm).c_str());

        Node user = data.append_child("user");

        this->getUserData(user, username);

        Node songs = data.append_child("songs");

        this->getSongs(songs,0);

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

pugi::xml_node XMLManager::getSongs(pugi::xml_node songsNode, int page) {

    QSqlQuery qry(connector->getDB());

    int i = 0;

    std::stringstream command;

    command << "SELECT * FROM songs WHERE ind > ";
    command << page*10;

    qry.exec(command.str().c_str());
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
        this->getSongs(songs,0);

        data.append_child(data.type());

    }
    else{

        doc->newChild("confirmation", std::to_string(confirm).c_str());

    }
    return doc;

}

XMLDoc* XMLManager::deleteSongResponse(bool confirm) {
    XMLDoc *doc = new XMLDoc("root");

    if(confirm) {

        doc->newChild("op", 1);
        doc->newChild("confirmation", std::to_string(confirm).c_str());
        Node data = doc->newChild("data");

        Node songs = doc->newChild("songs");
        this->getSongs(songs,0);

        data.append_child(data.type());

    }
    else{

        doc->newChild("confirmation", std::to_string(confirm).c_str());

    }
    return doc;

}

