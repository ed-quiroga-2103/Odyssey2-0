//
// Created by eduardo on 10/06/18.
//

#include <sstream>
#include <iostream>
#include "UserManager.h"

bool UserManager::createUser(string username, string name, string password, int age, string favGen, string email) {


    QSqlDatabase db = connector->getDB();

    QSqlQuery query(db);


    string a = "INSERT INTO users VALUES(\"";
    string comma = "\",\"";
    string end = "\");";

    string command = a+username+comma+name+comma+hasher.hash(password)+comma+std::to_string(age)+comma+favGen+comma+email+end;

    query.exec(command.c_str());

    return true;
}

bool UserManager::logUser(string username, string password) {

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

bool UserManager::userExists(string username) {

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
