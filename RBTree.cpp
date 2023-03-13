//
// Created by jakub on 3/13/2023.
//

#include "RBTree.h"
#include <iostream>

using namespace std;

RBTree::RBTree() {
        cr = cl = cp = "  ";
        cr [ 0 ] = 218; cr [ 1 ] = 196;
        cl [ 0 ] = 192; cl [ 1 ] = 196;
        cp [ 0 ] = 179;
        straznik.up = &straznik;
        straznik.right = &straznik;
        straznik.left = &straznik;
        straznik.color = 'B';
        root = &straznik;
    }

    void RBTree::dodaj(int liczba){
        RBTNode* node;
        node = new RBTNode;
        node->up = root;
        node->right = &straznik;
        node->left = &straznik;
        node->data = liczba;
        if(root == &straznik) root = node;
        while(true){
            if(node->data < node->up->data){
                if(node->up->left == &straznik) {
                    node->up->left = node;
                    break;
                } else node->up = node->up->left;
            } else{
                if(node->up->right == &straznik){
                    node->up->right = node;
                    break;
                } else node->up = node->up->right;
            }
        }

    }

void RBTree::printRBT ( string sp, string sn, RBTNode * p )
{
    string t;

    if( p != &straznik )
    {
        t = sp;
        if( sn == cr ) t [ t.length( ) - 2 ] = ' ';
        printRBT ( t+cp, cr, p->right );

        t = t.substr ( 0, sp.length( ) - 2 );
        cout << t << sn << p->color << ":" << p->data << endl;

        t = sp;
        if( sn == cl ) t [ t.length( ) - 2 ] = ' ';
        printRBT ( t+cp, cl, p->left );
    }
}
