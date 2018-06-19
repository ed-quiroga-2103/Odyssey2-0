//
// Created by estebandcg1999 on 12/06/18.
//

#include "UsersTree.h"

#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <cstring>

///
/// Crea un nodo si el actual es igual a NULL
///

UserNode* UsersTree::newNode(std::string item)
{
    UserNode* temp =  (UserNode*)malloc(sizeof(UserNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    if (root == NULL){
        root = temp;
    }
    return temp;
}

///
/// Recorre y hace print del arbol
///

void UsersTree::inorder(UserNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        std::cout << root->key << "\n";
        inorder(root->right);
    }
}

///
/// Inserta un nodo en el arbol
///

UserNode* UsersTree::insert(UserNode* node, std::string key)
{

    if (node == NULL) return newNode(key);

    //Comparador de Strings
    const char* keyChars = key.c_str();
    const char* nodeKeyChars = node->key.c_str();

    if (strcmp(nodeKeyChars,keyChars) > 0)
        node->left  = insert(node->left, key);
    else if (strcmp(nodeKeyChars,keyChars) < 0)
        node->right = insert(node->right, key);
    return node;
}