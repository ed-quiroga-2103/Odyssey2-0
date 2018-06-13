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

        string null = "\",NULL);";

        string command = a+name+comma+artist+comma+album+comma+lyrics+null;

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
