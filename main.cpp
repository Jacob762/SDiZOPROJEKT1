#include <iostream>
#include "tablica.h"
#include "lista.h"
#include "kopiec.h"

using namespace std;

int main() {
    //tablica mytablica;
    //mytablica.menu();
    //lista list;
    /*list.dodajNaKoniec(new listaElement(5));
    list.dodajNaPoczatek(new listaElement(25));
    list.dodajNaKoniec(new listaElement(2));
    list.dodajNaKoniec(new listaElement(89));
    list.dodajNaPoczatek(new listaElement(42));
    list.dodajNaKoniec(new listaElement(5));
    list.usunZDowolnegoMiejsca(2);
    list.usunZPoczatku();
    list.usunZKonca();
    list.usunZKonca();
    list.usunZKonca();
    list.usunZKonca();
    list.usunZKonca();
    list.dodajNaPoczatek(new listaElement(25));
    list.dodajNaKoniec(new listaElement(2));*/
    /*list.dodajNaKoniec(new listaElement(564));
    list.dodajNaPoczatek(new listaElement(69));
    list.dodajNaKoniec(new listaElement(53264));
    list.pokaz();
    cout<<list.wyszukajElement(3)->data<<endl;*/
    //list.dodajWDowolnymMiejscu(3,new listaElement(2137));
    // cout<<list.wyszukajElement(3)->data<<endl;
    // cout<<list.wyszukajElement(4)->data<<endl;
    //
    //list.usunZKonca();
    // list.usunZPoczatku();
    //list.usunZKonca();
    //list.usunZPoczatku();
    //list.usunZPoczatku();
    /* for(int i=0;i<5;i++){
         for(int j=0;j<1000;j++){
             switch(rand()%6+1){
                 case 1:
                     list.dodajNaKoniec(new listaElement(rand()%1000));
                     cout<<"CASE 1"<<endl;
                     break;
                 case 2:
                     list.dodajNaPoczatek(new listaElement(rand()%1000));
                     cout<<"CASE 2"<<endl;
                     break;
                 case 3:
                     if(list.rozmiar!=0) list.dodajWDowolnymMiejscu(rand()%list.rozmiar,new listaElement(rand()%1000));
                     cout<<"CASE 3"<<endl;
                     break;
                 case 4:
                     list.usunZKonca();
                     cout<<"CASE 4"<<endl;
                     break;
                 case 5:
                     list.usunZPoczatku();
                     cout<<"CASE 5"<<endl;
                     break;
                 case 6:
                     if(list.rozmiar!=0) list.usunZDowolnegoMiejsca(rand()%list.rozmiar);
                     cout<<"CASE 6"<<endl;
                     break;
             }
         }
         list.pokaz();
         cout<<"TEST "<<i<<endl;
     }*/
    /*kopiec kopie1c(5);
    for(int k=0;k<kopie1c.rozmiar;k++) cout<<kopie1c.table[k]<< " ";
    cout<<endl;
    kopie1c.dodaj(300);
    for(int k=0;k<kopie1c.rozmiar;k++) cout<<kopie1c.table[k]<< " ";
    cout<<endl;
    kopie1c.dodaj(200);
    for(int k=0;k<kopie1c.rozmiar;k++) cout<<kopie1c.table[k]<< " ";
    cout<<endl;
    kopie1c.usunKorzen();
    for(int k=0;k<kopie1c.rozmiar;k++) cout<<kopie1c.table[k]<< " ";
    cout<<endl;
    kopie1c.pokaz("", "", 0);*/
    srand(time(NULL));
    kopiec kopie1c(5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 1000; j++) {
            switch (rand() % 2 + 1) {
                case 1:
                    kopie1c.dodaj(rand() % 1000);
                    cout << "CASE 1" << endl;
                    break;
                case 2:
                    kopie1c.usunKorzen();
                    cout << "CASE 2" << endl;
                    break;
            }
        }
        kopie1c.pokaz("", "", 0);
        cout << "TEST " << i << endl;
        for(int k=0;k<kopie1c.rozmiar;k++)cout<<kopie1c.table[k]<<" ";
        if(kopie1c.rozmiar!=0) for(int k=0;k<kopie1c.rozmiar;k++) kopie1c.usunKorzen();
    }
    return 0;
}
