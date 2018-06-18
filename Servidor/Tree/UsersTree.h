//
// Created by estebandcg1999 on 12/06/18.
//

#ifndef ODYSSEY_SERVER_ESTEBAN_USERSTREE_H
#define ODYSSEY_SERVER_ESTEBAN_USERSTREE_H


#include <cstdlib>
#include "UserNode.h"

class UsersTree {

public:

    UserNode* root = NULL;

    UserNode* newNode(std::string item);
    void inorder(UserNode *root);
    UserNode* insert(UserNode* node, std::string key);

};


#endif //ODYSSEY_SERVER_ESTEBAN_USERSTREE_H
