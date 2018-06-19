//
// Created by eduardo on 05/06/18.
//

#include <iostream>
#include <sstream>
#include "XMLManager.h"

using Node = pugi::xml_node;

// METODO PRINCIPAL //
string XMLManager::handleClientMessage(string data) {
    int operation_number = getOpNum(data);

    if(operation_number == 0 ){
        cout<<"Se quiere registrar un usuario"<<endl;
        return readSingUp(data);
    }
    else if(operation_number == 1){
        cout<<"Se quiere iniciar sesion"<<endl;
        return readSingIn(data);

    }
    else if(operation_number == 2){
        cout<<"Se quiere registrar una cancion"<<endl;
        return readRegisterSong(data);

    }
    else if(operation_number == 3){
        cout<<"Se quiere eliminar una cancion"<<endl;
        return readDeleteSong(data);

    }
    else if(operation_number == 4){
        cout<<"Se quiere actualizar la metadata de una cancion"<<endl;
        return readUpdateMetadata(data);


    }
    else if(operation_number == 5){
        cout<<"Se quiere buscar una cancion por nombre"<<endl;
        return readSearchSong(data);
    }
    else if(operation_number == 6){
        cout<<"Se quiere buscar una cancion por artista"<<endl;
        return readSearchSong(data);

    }
    else if(operation_number == 7){
        cout<<"Se quiere buscar una cancion por album"<<endl;
        return readSearchSong(data);

    }
    else if(operation_number == 8){
        cout<<"Se quiere buscar una cancion por letra"<<endl;
        //ESTA SIN IMPLEMENTAR //

    }
    else if(operation_number == 9){
        cout<<"Se quiere agregar una amigo"<<endl;
        return readAddFriend(data);

    }
    else if(operation_number == 10){
        cout<<"Se quiere recomendar una cancion"<<endl;
        //ESTA SIN IMPLEMENTAR //


    }
    else if(operation_number == 11){
        cout<<"Se quiere calificar una cancion"<<endl;
        return readRateSong(data);

    }
    else if(operation_number == 12){
        cout<<"Se quiere eliminar un amigo"<<endl;
        return readDeleteFriend(data);

    }
    else if(operation_number == 99){
        cout<<"Se quieren enviar los chunks de la cancion"<<endl;
        //readSendChunks(data);

    }
    else if(operation_number == 98){
        cout<<"Se quiere enviar paginacion de lista de canciones"<<endl;
        return readSongListPaginacion(data);
    }
}
//METODOS DE LECTURA ENTRATES//
/*
string *XMLManager::readSendChunks(string data){
    pugi::xml_document doc;

    pugi::xml_parse_result result = doc.load_string(data.c_str());

    string name = doc.child("root").child("data").child("song").child("name").text().get();

    string pagenumber = doc.child("root").child("data").child("song").child("page").text().get();

    std::cout <<"The Song name for for chunks sending is :"<< name << std::endl;

    std::cout <<"The page number for for chunks sending is :"<< pagenumber << std::endl;
}
*/
int XMLManager::getOpNum(string str) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_string(str.c_str());

    return std::stoi(doc.child("root").child("op").text().get());
}
string XMLManager::readUpdateMetadata(string data) {

    pugi::xml_document doc;

    pugi::xml_parse_result result = doc.load_string(data.c_str());

    string oldname = doc.child("root").child("song").child("oldname").text().get();

    string Songname = doc.child("root").child("song").child("name").text().get();

    string artist = doc.child("root").child("song").child("artist").text().get();

    string album = doc.child("root").child("song").child("album").text().get();

    string lyrics = doc.child("root").child("song").child("lyrics").text().get();

    string SongBytes = doc.child("root").child("song").child("file64").text().get();

    std::cout <<"The Song name for update is:"<<Songname<< std::endl;
    std::cout <<"The artist for update is:"<< artist<< std::endl;
    std::cout <<"The album for update is:"<< album << std::endl;
    std::cout <<"The lyrics for updateis:"<< lyrics << std::endl;
    std::cout <<"The Bytes for update is:"<< SongBytes << std::endl;

    bool confirmation = dataManager->editSong(oldname, Songname, artist, album, lyrics);

    if(confirmation){

        return getPaginatedSongs(0,getOpNum(data))->toString();

    }
    else{

        return getPaginatedSongs(0,getOpNum(data))->toString();

    }

} //COMPLETO
string XMLManager::readUpdateUserData(string data) {
    pugi::xml_document doc;

    pugi::xml_parse_result result = doc.load_string(data.c_str());

    string username = doc.child("root").child("user").child("username").text().get();

    string password = doc.child("root").child("user").child("password").text().get();

    string imagebytes = doc.child("root").child("user").child("image64").text().get();

    bool confirmation = dataManager->updateUser(username,password);

    if(confirmation){

        return confirmationResponse(confirmation, getOpNum(data))->toString();

    }else{

        return confirmationResponse(confirmation, getOpNum(data))->toString();

    }


} //COMPLETO

string XMLManager::readSongListPaginacion(string data){
    pugi::xml_document doc;

    pugi::xml_parse_result result = doc.load_string(data.c_str());

    string pagenumber = doc.child("root").child("page").text().get();

    std::cout <<"The page number is:"<<pagenumber<< std::endl;

    return getPaginatedSongs(stoi(pagenumber),getOpNum(data))->toString();
} //COMPLETO

string XMLManager::readSearchSong(string data){

    pugi::xml_document doc;

    pugi::xml_parse_result result = doc.load_string(data.c_str());

    string song_name = doc.child("root").child("data").child("song").child("name").text().get();

    std::cout <<"The song name is:"<<song_name<< std::endl;

    int operation_number = getOpNum(data);


    return searchSongResponse(operation_number, song_name)->toString();

} //COMPLETO

string XMLManager::readRegisterPlaylist(string data){

    pugi::xml_document doc;

    pugi::xml_parse_result result = doc.load_string(data.c_str());

    string user_name = doc.child("root").child("data").child("user").child("name").text().get();

    string playlist_name = doc.child("root").child("data").child("playlist").child("name").text().get();

    string date_name = doc.child("root").child("data").child("playlist").child("date").text().get();

    std::cout <<"The username is:"<< user_name << std::endl;

    std::cout <<"The playlist name is:"<< playlist_name << std::endl;

    std::cout <<"The date name is:"<< date_name << std::endl;
} //SIN IMPLEMENTAR

string XMLManager::readDeletePlaylist(string data){

    pugi::xml_document doc;

    pugi::xml_parse_result result = doc.load_string(data.c_str());

    string user_name = doc.child("root").child("data").child("user").child("name").text().get();

    string playlist_name = doc.child("root").child("data").child("playlist").child("name").text().get();

    std::cout <<"The username for delete playlist is:"<< user_name << std::endl;

    std::cout <<"The playlist for delete name is:"<< playlist_name << std::endl;

} //SIN IMPLEMENTAR


string XMLManager::readAddFriend(string data){
    pugi::xml_document doc;

    pugi::xml_parse_result result = doc.load_string(data.c_str());

    string username = doc.child("root").child("data").child("user").child("username").text().get();
    string friendname = doc.child("root").child("data").child("friend").child("name").text().get();


    std::cout <<"The username for add friend is:"<< username << std::endl;

    if(dataManager->addFriend(username, friendname)){

        return addFriendResponse(username, true)->toString();

    }else{

        return addFriendResponse(username, false)->toString();

    }

} //COMPLETO
string XMLManager::readDeleteSong(string data){

    pugi::xml_document doc;

    pugi::xml_parse_result result = doc.load_string(data.c_str());

    string Songname = doc.child("root").child("data").child("song").child("name").text().get();



    std::cout <<"The Song name for delete is:"<<Songname<< std::endl;

    if(dataManager->deleteSong(Songname)){

        return registerSongResponse(true)->toString();

    }
    else{

        return registerSongResponse(false)->toString();

    }

} //COMPLETO

string XMLManager::readRegisterSong(string data){

    pugi::xml_document doc;

    pugi::xml_parse_result result = doc.load_string(data.c_str());

    string Songname = doc.child("root").child("data").child("song").child("name").text().get();

    string artist = doc.child("root").child("data").child("song").child("artist").text().get();

    string album = doc.child("root").child("data").child("song").child("album").text().get();

    string lyrics = doc.child("root").child("data").child("song").child("lyrics").text().get();

    string SongBytes = doc.child("root").child("data").child("song").child("file64").text().get();

    std::cout <<"The Song name is:"<<Songname<< std::endl;
    std::cout <<"The artist is:"<< artist<< std::endl;
    std::cout <<"The album is:"<< album << std::endl;
    std::cout <<"The lyrics is:"<< lyrics << std::endl;
    std::cout <<"The Bytes is:"<< SongBytes << std::endl;

    if(dataManager->addSong(Songname, artist, album, lyrics)){

        return registerSongResponse(true)->toString();

    }
    else{

        return registerSongResponse(false)->toString();

    }
} //COMPLETO

string XMLManager::readSingUp(string data){

    pugi::xml_document doc;

    pugi::xml_parse_result result = doc.load_string(data.c_str());

    string name = doc.child("root").child("data").child("user").child("name").text().get();

    string username = doc.child("root").child("data").child("user").child("username").text().get();

    string age = doc.child("root").child("data").child("user").child("age").text().get();

    string password = doc.child("root").child("data").child("user").child("password").text().get();

    string email = doc.child("root").child("data").child("user").child("email").text().get();

    std::cout <<"The name is:"<<name<< std::endl;
    std::cout <<"The username is:"<<username<< std::endl;
    std::cout <<"The age is:"<<age<< std::endl;
    std::cout <<"The password is:"<< password << std::endl;
    std::cout <<"The email is:"<< email << std::endl;

    if(dataManager->createUser(username,name,password,stoi(age),"None",email)){

        return signIn(true)->toString();

    }
    else{

        return signIn(false)->toString();
    }
} //COMPLETO
string XMLManager::readSingIn(string data){
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_string(data.c_str());

    string username = doc.child("root").child("data").child("user").child("username").text().get();

    string password = doc.child("root").child("data").child("user").child("password").text().get();

    std::cout <<"The username is:"<<username<< std::endl;
    std::cout <<"The password is:"<<password<< std::endl;

    if(dataManager->logUser(username,password)){
        cout<<"El usuario ya esta registrado"<< endl;

        return logInResponse(true, username)->toString();

    }
    else{

        return logInResponse(false, username)->toString();

    }
} //COMPLETO
string XMLManager::readDeleteFriend(string data){
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_string(data.c_str());

    string username = doc.child("root").child("data").child("user").child("username").text().get();
    string friendname = doc.child("root").child("data").child("friend").child("name").text().get();

    std::cout <<"The username for delete friend is:"<<username<< std::endl;

    if(dataManager->deleteFriend(username, friendname)){

        return deleteFriendResponse(username, true)->toString();

    }
    else{

        return deleteFriendResponse(username, false)->toString();

    }


} //COMPLETO
string XMLManager::readRateSong(string data){
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_string(data.c_str());
    string name = doc.child("root").child("data").child("song").child("name").text().get();
    string votes = doc.child("root").child("data").child("song").child("votes").text().get();
    string sum = doc.child("root").child("data").child("song").child("sum").text().get();
    string rating = doc.child("root").child("data").child("song").child("rating").text().get();

    std::cout <<"The name for rate song is:"<<name<< std::endl;
    std::cout <<"The votes for rate song is:"<<votes<< std::endl;
    std::cout <<"The sum for rate song is:"<<sum<< std::endl;
    std::cout <<"The rating for rate song is:"<<rating<< std::endl;

    if(dataManager->rateSong(name, stoi(rating))){

        return "Done";

    }
    else{

        return "Done";

    }
} //FALTA IMPLEMENTAR RESPUESTA

// FINAL DE METODOS DE LECTURA ENTRANTES //

XMLDoc *XMLManager::logInResponse(bool confirm, string username) {
    XMLDoc *doc = new XMLDoc("root");

    if(confirm) {
        Node data = doc->newChild("data");
        doc->newChild("op", 1);

        data.append_child("confirmation").append_child(pugi::node_pcdata).set_value(std::to_string(confirm).c_str());

        Node user = data.append_child("user");


        this->getUserData(user, username);



        Node nots = data.append_child("notifications");

        this->getNotifications(nots,username);

        Node songs = data.append_child("songs");

        this->getSongs(songs,0);

        Node friends = data.append_child("friends");
        this->getFriends(friends, username);

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

    QSqlQuery qry(dataManager->getDB());

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

    QSqlQuery qry(dataManager->getDB());

    std::stringstream stream;

    stream << "SELECT * FROM users WHERE username = \"";
    stream << username;
    stream << "\"";

    qry.exec(stream.str().c_str());
    while (qry.next()) {

        string usrname = qry.value(0).toString().toStdString();
        string name = qry.value(1).toString().toStdString();
        string pass = qry.value(2).toString().toStdString();
        string email = qry.value(6).toString().toStdString();
        string age = qry.value(3).toString().toStdString();

        user.append_child("username").append_child(pugi::node_pcdata).set_value(usrname.c_str());
        user.append_child("name").append_child(pugi::node_pcdata).set_value(name.c_str());
        user.append_child("password").append_child(pugi::node_pcdata).set_value(pass.c_str());
        user.append_child("email").append_child(pugi::node_pcdata).set_value(email.c_str());
        user.append_child("age").append_child(pugi::node_pcdata).set_value(age.c_str());

    }
    cout<<"AHHHHHH:"<<user<<endl;

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

    QSqlQuery qry(dataManager->getDB());

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

    QSqlQuery qry(dataManager->getDB());

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

    QSqlQuery qry(dataManager->getDB());

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

XMLDoc* XMLManager::confirmationResponse(bool confirm, int opnum){

    XMLDoc *doc = new XMLDoc("root");

    doc->newChild("op", opnum);
    doc->newChild("confirmation", std::to_string(confirm).c_str());

    return doc;

}

XMLDoc* XMLManager::registerSongResponse(bool confirm) {
    XMLDoc *doc = new XMLDoc("root");

    if(confirm) {

        doc->newChild("op", 2);
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

        doc->newChild("op", 3);
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

pugi::xml_node XMLManager::getNotifications(pugi::xml_node node, string username) {
    QSqlQuery qry(dataManager->getDB());

    std::stringstream stream;

    stream << "SELECT * FROM `";
    stream << username;
    stream << "-nots`";
    stream << ";";


    qry.exec(stream.str().c_str());
    while (qry.next()) {

        string sender = qry.value(0).toString().toStdString();
        string msg = qry.value(1).toString().toStdString();

        Node noti = node.append_child("notification");
        noti.append_child("from").append_child(pugi::node_pcdata).set_value(sender.c_str());
        noti.append_child("message").append_child(pugi::node_pcdata).set_value(msg.c_str());


    }



    return node;
}

pugi::xml_node XMLManager::getFriends(pugi::xml_node node,string username) {

    QSqlQuery qry(dataManager->getDB());

    std::stringstream stream;

    stream << "SELECT * FROM `";
    stream << username;
    stream << "-friends`";
    stream << ";";


    qry.exec(stream.str().c_str());
    while (qry.next()) {

        string name = qry.value(0).toString().toStdString();

        node.append_child("friend").append_child("username").append_child(pugi::node_pcdata).set_value(name.c_str());


    }



    return node;
}

XMLDoc *XMLManager::addFriendResponse(string username, bool confirm) {

    XMLDoc* doc = new XMLDoc("root");

    doc->newChild("op", 9);

    Node data = doc->newChild("data");

    data.append_child("confirmation").append_child(pugi::node_pcdata).set_value(std::to_string(confirm).c_str());

    Node friends = data.append_child("friends");

    getFriends(friends,username);

    return doc;

}

XMLDoc *XMLManager::deleteFriendResponse(string username, bool confirm) {

    XMLDoc* doc = new XMLDoc("root");

    doc->newChild("op", 12);

    Node data = doc->newChild("data");

    data.append_child("confirmation").append_child(pugi::node_pcdata).set_value(std::to_string(confirm).c_str());

    Node friends = data.append_child("friends");

    getFriends(friends,username);

    return doc;

}


XMLDoc *XMLManager::getPaginatedSongs(int page, int opnum) {

    XMLDoc *doc = new XMLDoc("root");

    doc->newChild("op",98);

    Node songs = doc->newChild("songs");

    getSongs(songs, 0);

    return doc;
}
