//
// Created by estebandcg1999 on 12/06/18.
//

#include "AVLTree.h"
#include <cstring>

// C program to insert a node in AVL tree
#include<stdio.h>
#include<stdlib.h>

int AVLTree::height(AVLTree::Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// A utility function to get maximum of two integers
int AVLTree::max(int a, int b)
{
    return (a > b)? a : b;
}

/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
AVLTree::Node* AVLTree::newNode(std::string key)
{
    AVLTree::Node* node = (AVLTree::Node*)
            malloc(sizeof(AVLTree::Node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return(node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
AVLTree::Node *AVLTree::rightRotate(AVLTree::Node *y)
{
    AVLTree::Node *x = y->left;
    AVLTree::Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
AVLTree::Node *AVLTree::leftRotate(AVLTree::Node *x)
{
    AVLTree::Node *y = x->right;
    AVLTree::Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int AVLTree::getBalance(AVLTree::Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert a key in the subtree rooted
// with node and returns the new root of the subtree.
AVLTree::Node* AVLTree::insert(AVLTree::Node* node, std::string key)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(key));

    if (strcmp(key.c_str(),node->key.c_str()) < 0)
        node->left  = insert(node->left, key);
    else if (strcmp(key.c_str(),node->key.c_str()) > 0)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                           height(node->right));

    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && strcmp(key.c_str(),node->left->key.c_str()) < 0)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && strcmp(key.c_str(),node->right->key.c_str()) > 0)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && strcmp(key.c_str(),node->left->key.c_str()) > 0)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && strcmp(key.c_str(),node->right->key.c_str()) < 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
void AVLTree::preOrder(AVLTree::Node *root)
{
    if(root != NULL)
    {
        std::cout << root->key << "\n";
        preOrder(root->left);
        preOrder(root->right);
    }
}


AVLTree::Node * AVLTree::minValueNode(AVLTree::Node* node)
{
    struct Node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

// Recursive function to delete a node with given key
// from subtree with given root. It returns root of
// the modified subtree.
AVLTree::Node* AVLTree::deleteNode(AVLTree::Node* root, std::string key)
{
    // STEP 1: PERFORM STANDARD BST DELETE

    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the
    // root's key, then it lies in left subtree
    if (strcmp(key.c_str(),root->key.c_str()) < 0)
        root->left = deleteNode(root->left, key);

        // If the key to be deleted is greater than the
        // root's key, then it lies in right subtree
    else if(strcmp(key.c_str(),root->key.c_str()) > 0)
        root->right = deleteNode(root->right, key);

        // if key is same as root's key, then This is
        // the node to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            AVLTree::Node *temp = root->left ? root->left :
                                root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
                *root = *temp; // Copy the contents of
            // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            AVLTree::Node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
        return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),
                           height(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

AVLTree::Node* AVLTree::search(AVLTree::Node* root, std::string key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
        return root;

    // Key is greater than root's key
    if (strcmp(root->key.c_str(),key.c_str()) < 0)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}