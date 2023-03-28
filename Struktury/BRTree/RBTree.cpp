//
// Created by jakub on 3/13/2023.
//

#include "RBTree.h"
#include <iostream>
#include <fstream>
#define COUNT 3

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
        //straznik.data = NULL;
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
        if(root==&straznik) {
            node->color = 'B';
            root = node;
            return;
        }
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
        if(root==node) return;
        if(node->up->color=='B') return;
        while(node!=root && node->up->color=='R'){
            if(node->up->up->left == node->up){
                if(node->up->up->right->color=='R'){ //wuja wstawianego jest czerwony - 1.przyupadke
                    node->up->color = 'B';
                    node->up->up->right->color='B';
                    if(root==node->up->up) {
                        node->up->up->color = 'B';
                        return;
                    }else node->up->up->color = 'R';
                    node = node->up->up;
                    continue;
                } if(node->up->up->right->color=='B' && node == node->up->right){//wuja wstawianego czarny a wstawiany prawym synem - 2.przyaped,
                    rotacjaWLewo(node->up);
                    node = node->left;
                } if(node->up->up->right->color=='B' && node == node->up->left ){//wuja wstawianego czarny a wstawiany lewym synem - 3.przyaped,
                    rotacjaWPrawo(node->up->up);
                    node->up->color = 'B';
                    node->up->right->color = 'R';
                    break;
                }
            } else{ // przypadki kiedy idziemy w prawo
                if(node->up->up->left->color=='R'){ //wuja wstawianego jest czerwony - 1.przyupadke
                    node->up->color = 'B';
                    node->up->up->left->color='B';
                    if(root==node->up->up) {
                        node->up->up->color = 'B';
                        return;
                    }else node->up->up->color = 'R';
                    node = node->up->up;
                    continue;
                } if(node->up->up->left->color=='B' && node == node->up->left){//wuja wstawianego czarny a wstawiany lewym synem - 2.przyaped,
                    rotacjaWPrawo(node->up);
                    node = node->right;
                } if(node->up->up->left->color=='B' && node == node->up->right ){//wuja wstawianego czarny a wstawiany prawym synem - 3.przyaped,
                    rotacjaWLewo(node->up->up);
                    node->up->color = 'B';
                    node->up->left->color = 'R';
                    break;
                }
            }
        }
    }

    RBTree::RBTNode* RBTree::wyszukaj(int liczba){
    RBTNode* node = root;
    int pietro = 0;
    while(node!=&straznik){
        if(node->data<liczba) {
            pietro++;
            node = node->right;
        }
        else if(node->data>liczba){
            pietro++;
            node = node->left;
        } else if(node->data==liczba)return node;
        else break;
    }
    return node;
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
    RBTNode* A,*B;
    A = node -> right;
    if(A!=&straznik){
        B = node->up;
        node -> right = A -> left;
        if(node->right!=&straznik) node->right->up = node;
        A->left = node;
        node -> up = A;
        A -> up = B;
        if(B!=&straznik){
            if(B->left==node) B->left = A;
            else B->right = A;
        } else root=A;
    }

}

void RBTree::rotacjaWPrawo(RBTNode* node){
    RBTNode* A,*B;
    A = node->left;
    if(A!=&straznik){
        B = node->up;
        node->left = A->right;
        if(node->left != &straznik) node->left->up = node;
        A -> right = node;
        node -> up = A;
        A -> up = B;
        if(B!=&straznik){
            if(B->left==node) B->left = A;
            else B->right = A;
        } else root=A;
    }
}

void RBTree::wczytaj(string nazwa) {
    fstream file (nazwa,std::ios_base::in);
    if (!file.is_open()) {
        cout<<"ERROR"<<endl;
        return;
    }
    int number;
    while (file >> number){
        dodaj(number);
    }
}

void RBTree::print2DUtil(RBTree::RBTNode* rote, int space)
{
    // Base case
    if (rote == &straznik)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(rote->right, space);

    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << rote->data <<":"<<rote->color<< "\n";

    // Process left child
    print2DUtil(rote->left, space);
}

// Wrapper over print2DUtil()
void RBTree::print2D(RBTree::RBTNode* rote)
{
    // Pass initial space count as 0
    print2DUtil(rote, 0);
}

void RBTree::printData(RBTree::RBTNode* rote){
    if (rote == &straznik)
        return;
    printData(rote->right);
    cout << rote->data << " ";
    printData(rote->left);
}

void RBTree::usun(RBTree::RBTNode* node){
    bool strona = NULL;
    if(node==node->up->right) {
        strona = true;
    }
    else {
        strona = false;
    }
    bool problem = false;
    if(node->color=='B' && node->left->color=='B'&&node->right->color=='B') problem = true;
    //if(node==&straznik) return;
    RBTNode *syn = nullptr,*ojciec,*naznaczony= nullptr;
    ojciec = node->up;
    if(node->left==&straznik) {//przypadek lewy syn nie istnieje
        syn = node->right;
        if(syn==&straznik){ //psuje bo straznik wskazuje na zlego brata
            if(node==node->up->left) node->up->left = &straznik;
            else node->up->right = &straznik;
        }
        node->data = syn->data;
        if(syn!=&straznik) usun(syn);
    }
    else if(node->right==&straznik) {//przypadek prawy syn nie istnieje
        syn = node->left;
        node->data = syn->data;
        usun(syn);
    }else{ //dwaj synowie
        syn = nastepnik(node);
        if(syn==node->right){// prawy syn to nastepnik
            node -> data = syn -> data;
            usun(syn);
        } else{ //nastepnik to nie prawy syn, tylko jego lewy syn
            node -> data = syn -> data;
            usun(syn);
        }
    }
    if(ojciec==&straznik) root = node;
    if(problem){ //fixup drzewa, node czerwony, case1
        RBTNode *brat;
        while(node!=root && node->color=='B'){ //root jest podowjnie czarny, case2
            brat = wskazBrata(node);
            if(brat->color=='B' && brat->right->color=='B' && brat->left->color=='B'){ //brat usuwanego jest czarny i jego dzieci sa tez czarne, case3
                brat->color = 'R';
                if(node->up->color=='R'){
                    node->up->color = 'B';
                    //dodatkowy = false;
                    break;
                }
                node = node->up;
                continue;
            }
            if(brat->color=='R'){ //brat usuwanego czerwon, cas4
                brat->color = 'B';
                brat->up->color = 'R';
                if(strona){
                    rotacjaWPrawo(brat->up);
                } else rotacjaWLewo(brat->up);
                continue;
            }
            if(strona && brat->color=='B' && brat->left->color=='B' && brat->right->color=='R'){ //brat usuwaengo czarny, blizszy syn czewrony
                    brat->right->color = 'B';
                    brat -> color = 'R';
                    rotacjaWLewo(brat);
            } else if(!strona && brat->color=='B' && brat->left->color=='R' && brat->right->color=='B'){ //przypadek lustrzany
                brat->left->color = 'B';
                brat -> color = 'R';
                rotacjaWPrawo(brat);
            }
            brat = wskazBrata(node);
            if(strona && brat->color=='B' && brat->left->color=='R' && brat->right->color=='B'){//brat usuwaengo czarny, dalszy syn czewrony
                if(brat->up->color=='R') {
                    brat->color = 'R';
                    brat->up->color = 'B';
                }
                rotacjaWPrawo(brat->up);
                brat->left->color = 'B';
                break;
            }else if(!strona&&brat->color=='B' && brat->left->color=='B' && brat->right->color=='R'){
                if(brat->up->color=='R') {
                    brat->color = 'R';
                    brat->up->color = 'B';
                }
                rotacjaWLewo(brat->up);
                brat->right->color = 'B';
                break;
            }
        }
    }
    //if(syn!=&straznik) delete syn;
}

RBTree::RBTNode* RBTree::nastepnik(RBTree::RBTNode* node){
    if(node->right!=&straznik){
        if(node->right->left!=&straznik) return node->right->left;
        else return node->right;
    }else return &straznik;
}

RBTree::RBTNode* RBTree::wskazBrata(RBTree::RBTNode* node){
    RBTNode* brat;
    if(node->data==straznik.data){
        if(node->up->right==&straznik) brat = node->up->left;
        else brat = node->up->right;
        return brat;
    }
    if(node==node->up->right) {
        brat = node->up->left;
    }
    else {
        brat = node->up->right;
    }
    return brat;
}