//
// Created by jakub on 3/13/2023.
//

#ifndef SDIZO_RBTREE_H
#define SDIZO_RBTREE_H
#include <string>

class RBTree {
public:
    struct RBTNode{
        RBTNode* up;
        RBTNode* left;
        RBTNode* right;
        int data;
        char color;
    };
    std::string cr, cl, cp;
    RBTNode straznik;
    RBTNode* root;
    RBTree();
    void dodaj(int liczba);

    void printRBT(std::__cxx11::basic_string<char> sp, std::__cxx11::basic_string<char> sn, RBTNode *p);
};


#endif //SDIZO_RBTREE_H
