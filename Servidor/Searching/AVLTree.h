//
// Created by estebandcg1999 on 12/06/18.
//

#include <cstdlib>
#include <iostream>

#ifndef ODYSSEY_SERVER_ESTEBAN_AVLTREE_H
#define ODYSSEY_SERVER_ESTEBAN_AVLTREE_H


class AVLTree {
public:

    struct Node
    {
        std::string key;
        struct Node *left;
        struct Node *right;
        int height;
    };

    int max(int a, int b);
    int height(struct Node *N);
    struct Node* newNode(std::string key);
    struct Node *rightRotate(struct Node *y);
    struct Node *leftRotate(struct Node *x);
    int getBalance(struct Node *N);
    struct Node* insert(struct Node* node, std::string key);
    void preOrder(struct Node *root);
    struct Node * minValueNode(struct Node* node);
    struct Node* deleteNode(struct Node* root, std::string key);
    struct Node* search(struct Node* root, std::string key);
};


#endif //ODYSSEY_SERVER_ESTEBAN_AVLTREE_H
