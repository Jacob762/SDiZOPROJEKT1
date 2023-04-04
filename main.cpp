#include <iostream>
#include "Struktury/Tablica/tablica.h"
#include "Struktury/Lista/lista.h"
#include "Struktury/Kopiec/kopiec.h"
#include "Struktury/BRTree/RBTree.h"
#include "Struktury/Tablica/tablicaTesty.h"
#include "Struktury/Lista/listaTesty.h"
#include "Struktury/Kopiec/kopiecTesty.h"
#include <cstdlib>

using namespace std;

void testyMenu();

int main() {
    tablica tab = tablica();
    kopiec kopiec1 = kopiec();
    RBTree* drzewo = new RBTree();
    ::srand(time(NULL));
    listaTesty list = listaTesty();
    list.test(2000,100,5);
    //testyMenu();
    for(;;){
        cout<<"Wybierz strukture"<<endl;
        cout<<"1. tablica dynamiczna"<<endl;
        cout<<"2. lista dwukierunkowa"<<endl;
        cout<<"3. kopiec"<<endl;
        cout<<"4. drzewo czerwono-czarne"<<endl;
        cout<<"5. Wyjdz"<<endl;
        int n;
        cin>>n;
        switch (n) {
            case 1:
                tab.menu();
                break;
            case 2:
                //list.menu();
                break;
            case 3:
                kopiec1.menu();
                break;
            case 4:
                drzewo->menu();
                break;
            case 5:
                exit(2138);
        }
    }
}

void testyMenu(){
    tablicaTesty tab = tablicaTesty();
    listaTesty list = listaTesty();
    kopiecTesty kopiec = kopiecTesty();
    for(;;){
        cout<<"Wybierz strukture"<<endl;
        cout<<"1. tablica dynamiczna"<<endl;
        cout<<"2. lista dwukierunkowa"<<endl;
        cout<<"3. kopiec"<<endl;
        cout<<"4. drzewo czerwono-czarne"<<endl;
        cout<<"5. Wyjdz"<<endl;
        int n;
        cin>>n;
        switch (n) {
            case 1:
                tab.test(1000,200,5);
                break;
            case 2:
                list.test(1000,200,5);
                break;
            case 3:
                kopiec.test(1000,200,5);
                break;
            case 4:
                break;
            case 5:
                exit(2138);
        }
    }
}
