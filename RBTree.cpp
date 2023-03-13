//
// Created by jakub on 3/13/2023.
//

#include "RBTree.h"
#include <iostream>

using namespace std;

RBTree::RBTree() {
        straznik.up = &straznik;
        straznik.right = &straznik;
        straznik.left = &straznik;
        straznik.color = 'B';
        root = &straznik;
    }

    void RBTree::dodaj(int liczba){
        RBTNode* node;
        if(!root){

        }

    }
