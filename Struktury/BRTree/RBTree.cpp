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
        bool go = false;
        RBTNode* node;
        node = new RBTNode;
        node->up = root;
        node->right = &straznik;
        node->left = &straznik;
        node->data = liczba;
        while(true){
            if(node->data < node->up->data){
                if(node->up->left == &straznik) {
                    node->up->left = node;
                    break;
                } else node->up = node->up->left;
            } else{
                go = true;
                if(node->up->right == &straznik){
                    node->up->right = node;
                    break;
                } else node->up= node->up->right;
            }
        }
        node->color = 'R';
        if(root == &straznik) {node->color = 'B'; root = node; return;}
        if(node->up->color == 'B') return;
        if(!go){
            while(true){
                if(node->up->up->right->color == 'R'){ //wujek node jest czerwony
                    node->up->color = 'B';
                    node->up->up->right->color = 'B';
                    node->up->up->color = 'R';
                    if(node->up->up == root){node->up->up->color = 'B'; break;}
                    else node = node->up->up;
                } else {
                    if(node->up->up->right->color == 'B' && node == node->up->right) { //wujek node jest czarny, node jest prawym potomkiem
                        rotacjaWLewo(node);
                    }
                    if(node->up->up->right->color == 'B' && node == node->up->left){ // to samo ale jest lewym
                        rotacjaWPrawo(node); //tego ifa trzeba polaczyc z else if poprzednim, ale jednoczesnie uniezaleznic od ifa
                        node->up->color = 'B';
                        node->up->right->color = 'R';
                    } else return;
                }   //else break;//dotyczy tylko poprzedniego ifa
            }
        } else{ //lustrzane
            while(true){
                if(node->up->up->left->color == 'R'){ //wujek node jest czerwony
                    node->up->color = 'B';
                    node->up->up->right->color = 'B';
                    node->up->up->color = 'R';
                    if(node->up->up == root){node->up->up->color = 'B'; break;}
                    else node = node->up->up;
                } else {
                    if(node->up->up->left->color == 'B' && node == node->up->left) { //wujek node jest czarny, node jest prawym potomkiem
                        rotacjaWPrawo(node);
                    }
                    if(node->up->up->left->color == 'B' && node == node->up->right){ // to samo ale jest lewym
                        rotacjaWLewo(node); //tego ifa trzeba polaczyc z else if poprzednim, ale jednoczesnie uniezaleznic od ifa
                        node->up->color = 'B';
                        node->up->right->color = 'R';
                    } else return;
                }   //else break;//dotyczy tylko poprzedniego ifa
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

void RBTree::rotacjaWLewo(RBTNode* node){
    node->left = node->up;
    node->up = node->left->up;
    node->left->up = node;
}

void RBTree::rotacjaWPrawo(RBTNode* node){
    if(node->up->up->up->right == node->up->up) node->up->up->up->right = node->up;
    else if(node->up->up->up->left == node->up->up) node->up->up->up->left = node->up;
    node->up->up = node->up->right;
    node->up->right->up = node->up;
}
