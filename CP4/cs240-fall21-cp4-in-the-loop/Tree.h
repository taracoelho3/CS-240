#include <string>
#include "User.h"

class Tree {
   public:
    Tree* insert(const User& u, Tree* root);
    User* find(std::string s, Tree* root);
    Tree* remove(const User& u, Tree* root);
    Tree();
    void deleteBinaryTree(Tree* root);
    User& getData();
    Tree& operator=(const Tree& other);
    void printInOrder(Tree* root);
    Tree(const User& u);
    Tree *left, *right;
    User data;

};
