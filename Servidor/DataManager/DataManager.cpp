//
// Created by eduardo on 10/06/18.
//

#include <sstream>
#include <iostream>
#include "DataManager.h"

bool DataManager::createUser(string username, string name, string password, int age, string favGen, string email) {
    if(!userExists(username)){

        QSqlDatabase db = connector->getDB();

        QSqlQuery query(db);


        string a = "INSERT INTO users VALUES(\"";
        string comma = "\",\"";
        string end = "\");";

        string command = a+username+comma+name+comma+hasher.hash(password)+comma+std::to_string(age)+comma+favGen+comma+email+end;

        query.exec(command.c_str());

        std::cout << createFriendsTable(username);
        std::cout << createNotsTable(username);

        return true;
    }

    else return false;
}

bool DataManager::logUser(string username, string password) {

    if(this->userExists(username)){

        QSqlDatabase db = connector->getDB();

        QSqlQuery qr(db);

        string a = "SELECT * FROM users WHERE username = \"";
        string b = "\";";

        string command = a+username+b;

        qr.exec(command.c_str());

        string pass = "NONE";

        while(qr.next()){

            pass = qr.value(2).toString().toStdString();

        }

        if(hasher.hash(password) == pass){

            return true;

        }else{

            return false;

        }
    }
    else{
        return false;
    }
}

bool DataManager::userExists(string username) {

    QSqlDatabase db = connector->getDB();

    QSqlQuery qr(db);

    string a = "SELECT * FROM users WHERE username = \"";
    string b = "\";";

    string command = a+username+b;

    qr.exec(command.c_str());

    string user = "null";

    while(qr.next()){

        user = qr.value(0).toString().toStdString();
    }
    string null = "null";

    if(user == null){

        return false;

    }else{

        return true;

    }

}

bool DataManager::addSong(string name, string artist, string album, string lyrics) {
    if(!songExists(name)){

        QSqlDatabase db = connector->getDB();

        QSqlQuery query(db);


        string a = "INSERT INTO songs VALUES(\"";
        string comma = "\",\"";
        string end = "\");";

        string null = "\",NULL,0);";

        string command = a+name+comma+artist+comma+album+comma+lyrics+null;

        std::cout << command << endl;

        query.exec(command.c_str());

        return true;
    }

    else return false;
}

bool DataManager::editSong(string name, string newName, string artist, string album, string lyrics) {
    if(songExists(name)){

        QSqlDatabase db = connector->getDB();

        QSqlQuery query(db);


        string a = "UPDATE songs set name = \"";
        string b = "\", artist = \"";
        string c = "\", album = \"";
        string d = "\", lyrics = \"";
        string e = "\" WHERE name = \"";
        string end = "\";";

        string null = "\",NULL);";

        string command = a+newName+b+artist+c+album+d+lyrics+e+name+end;

        query.exec(command.c_str());

        return true;
    }

    else return false;
}

bool DataManager::rateSong(string name, int rating) {
    if(songExists(name)){

        QSqlDatabase db = connector->getDB();

        QSqlQuery query(db);


        string a = "UPDATE songs set rating = ";
        string rate = std::to_string(rating);
        string b = " WHERE name = \"";
        string end = "\";";

        string null = "\",NULL);";

        string command = a+rate+b+name+end;

        query.exec(command.c_str());

        return true;
    }

    else return false;
}

bool DataManager::songExists(string songname) {

    QSqlDatabase db = connector->getDB();

    QSqlQuery qr(db);

    string a = "SELECT * FROM songs WHERE name = \"";
    string b = "\";";

    string command = a+songname+b;

    qr.exec(command.c_str());

    string user = "null";

    while(qr.next()){

        user = qr.value(0).toString().toStdString();
    }
    string null = "null";

    if(user == null){

        return false;

    }else{

        return true;

    }

}

bool DataManager::createFriendsTable(string username) {

    if(userExists(username)){

        QSqlQuery qr(connector->getDB());

        string a = "CREATE TABLE `";
        string b = "-friends` (name VARCHAR(30) NOT NULL);";

        string command = a+username+b;

        //std::cout << command;

        qr.exec(command.c_str());


        return true;

    }

    return false;
}

bool DataManager::createNotsTable(string username) {

    if(userExists(username)){

        QSqlQuery qr(connector->getDB());

        string a = "CREATE TABLE `";
        string b = "-nots` (sender VARCHAR(30) NOT NULL, msg VARCHAR(30) NOT NULL, song VARCHAR(30) NOT NULL);";

        string command = a+username+b;

        qr.exec(command.c_str());

        //std::cout << command;

        return true;

    }

    return false;
}

bool DataManager::addFriend(string username, string friendUsername) {

    if(userExists(username)){

        if(userExists(friendUsername) && username != friendUsername){

            string a = "INSERT INTO `";
            string b = "-friends` VALUES(\"";
            string c = "\");";

            string command = a+username+b+friendUsername+c;

            QSqlQuery qr(connector->getDB());

            qr.exec(command.c_str());

            return true;
        }

        return false;

    }

    return false;
}

bool DataManager::deleteFriend(string username, string friendUsername){

    if (userExists(username)){

        if(userExists(friendUsername) && username != friendUsername){

            string a = "DELETE FROM `";
            string b = "-friends` WHERE name = \"";
            string c = "\"";

            string command = a+username+b+friendUsername+c;

            QSqlQuery qr(connector->getDB());

            qr.exec(command.c_str());

            return true;
        }

        return false;

    }

    return false;

}

bool DataManager::deleteSong(string name) {

    if (songExists(name)){

        string a = "DELETE FROM songs WHERE name = \"";

        string b = "\";";

        string command = a+name+b;

        QSqlQuery qr(connector->getDB());

        qr.exec(command.c_str());

        return true;
    }


    return false;
}

