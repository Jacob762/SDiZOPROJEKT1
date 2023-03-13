//
// Created by jakub on 3/13/2023.
//

#ifndef SDIZO_RBTREE_H
#define SDIZO_RBTREE_H


class RBTree {
public:
    struct RBTNode{
        RBTNode* up;
        RBTNode* left;
        RBTNode* right;
        int data;
        char color;
    };

    RBTNode straznik;
    RBTNode* root;
    RBTree();
    void dodaj(int liczba);
};


#endif //SDIZO_RBTREE_H
