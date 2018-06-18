//
// Created by estebandcg1999 on 12/06/18.
//

#ifndef ODYSSEY_SERVER_ESTEBAN_USERNODE_H
#define ODYSSEY_SERVER_ESTEBAN_USERNODE_H

#include <string>

class UserNode {

public:

    ///
    /// Nombre del usuario, su set() y get().
    ///

    std::string key;

    std::string getKey();
    void setKey(int key);

    ///
    /// Hijos left y right del usuario padre, sus setters() y getters().
    ///

    UserNode* left, *right;

    UserNode* getLeft();
    void setLeft(UserNode *left);

    UserNode* getRight();
    void setRight(UserNode* right);

};


#endif //ODYSSEY_SERVER_ESTEBAN_USERNODE_H
