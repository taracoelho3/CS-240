#include "Tree.h"

#include <iostream>


Tree::Tree() {
    User u;
    data = u;
    left = NULL;
    right = NULL;
}

Tree::Tree(const User& u) {
    data = u;
    left = NULL;
    right = NULL;
}

void Tree::deleteBinaryTree(Tree* root)
{
    if (root == nullptr) {
        return;
    }
    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);
    //delete root->getData();
    delete root;
    root = nullptr;
}

User& Tree::getData() {
    return data;
}

Tree* Tree::insert(const User& u, Tree* root) {
    if (root == NULL) {
        root = new Tree(u);
        return root;
        
    } else if (u < root->data) {
        root->left = insert(u, root->left);
    } else {
        root->right = insert(u, root->right);
    }
    return root;
}

User* Tree::find(std::string s, Tree* root) {
    if (root == NULL) {
        return NULL;
    } else if (s == root->data.get_id()) {
        return &root->data;
    } else if (s < root->data.get_id()) {
        return find(s, root->left);
    } else {
        return find(s, root->right);
    }
}

Tree* Tree::remove(const User& u, Tree* root) {
    if (root == NULL) {
        return root;
    } else if (u < root->data) {
        root->left = remove(u, root->left);
    } else if (u > root->data) {
        root->right = remove(u, root->right);
    } else {
        if (root->left == NULL && root->right == NULL) {
            return NULL;
        } else if (root->left == NULL) {
            Tree* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Tree* temp = root->left;
            delete root;
            return temp;
        }
        Tree* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = remove(temp->data, root->right);
    }
    return root;
}

void Tree::printInOrder(Tree* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    printInOrder(root->right);
}

