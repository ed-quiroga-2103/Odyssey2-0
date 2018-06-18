//
// Created by estebandcg1999 on 12/06/18.
//

#include "UserNode.h"

std::string UserNode::getKey() {
    return key;
}

void UserNode::setKey(int key) {
    UserNode::key = key;
}

UserNode *UserNode::getLeft() {
    return left;
}

void UserNode::setLeft(UserNode *left) {
    UserNode::left = left;
}

UserNode* UserNode::getRight() {
    return right;
}

void UserNode::setRight(UserNode* right) {
    UserNode::right = right;
}
