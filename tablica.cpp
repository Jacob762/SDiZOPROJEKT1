//
// Created by Jakub Klawon on 07/03/2023.
//

#include "tablica.h"

namespace std {
    void tablica::init(int rozmiar) {
        table = new int[rozmiar];
        for(int i=0;i<rozmiar;i++) table[i] = i*2 +2;
    }
    void tablica::menu() {
        cout<<"Podaj wielkosc poczatkowa tablicy:"<<endl;
        int n;
        cin>>n;
        int liczba;
        rozmiar = n;
        init(n);
        pokaz();
        for(;;){
            cout<<"Podaj numer akcji ktora chcesz wykonac:"<<endl;
            cout<<"1. Dodaj na koniec"<<endl;
            cout<<"2. Pokaz"<<endl;
            cout<<"3. Wyjdz"<<endl;
            cout<<"4. Dodaj na poczatek"<<endl;
            cout<<"5. Dodaj w danym miejscu"<<endl;
            cin.sync(); cin.clear();
            cin>>n;
            switch (n) {
                case 1:
                    cin.sync(); cin.clear();
                    cout<<"Podaj liczbe"<<endl; //czyszczenie bufora
                    cin>>liczba;
                    dodajNaKoniec(liczba);
                    break;
                case 2:
                    pokaz();
                    break;
                case 4:
                    cin.sync(); cin.clear();
                    cout<<"Podaj liczbe"<<endl; //czyszczenie bufora
                    cin>>liczba;
                    dodajNaPoczatek(liczba);
                    break;
                case 5:
                    cin.sync(); cin.clear();
                    cout<<"Podaj liczbe"<<endl; //czyszczenie bufora
                    cin>>liczba;
                    cout<<"Podaj indeks"<<endl;
                    cin>>n;
                    dodajNaDowolneMiejsce(liczba,n);
                    break;
                case 6:
                    cin.sync(); cin.clear();
                    usunZKonca();
                    break;
                case 3:
                    delete [] table;
                    exit(2137);
            }
        }
    }
    void tablica::pokaz() {
        for(int i=0;i<rozmiar;i++) cout<<table[i]<<" ";
        cout<<endl;
    }
    void tablica::dodajNaKoniec(int liczba) {
        temp = new int[++rozmiar];
        for(int i=0;i<rozmiar-1;i++){
            temp[i] = table[i];
        }
        temp[rozmiar-1] = liczba;
        //delete [] table;
        table = temp;
        delete [] temp;
    }
    void tablica::dodajNaPoczatek(int liczba) {
        temp = new int[++rozmiar];
        temp[0] = liczba;
        for(int i=1;i<rozmiar;i++) temp[i] = table[i-1];
        //delete [] table;
        table = temp;
        delete [] temp;
    }
    void tablica::dodajNaDowolneMiejsce(int liczba, int index) {
        temp = new int[++rozmiar];
        temp[index] = liczba;
        for(int i=0;i<index;i++) temp[i] = table[i];
        for(int i=index+1;i<rozmiar;i++) temp[i] = table[i-1];
       // delete [] table;
        table = temp;
        delete [] temp;
    }
    void tablica::usunZKonca() {
        temp = new int[rozmiar-1];
        for(int i=0;i<rozmiar-1;i++) {
            cout<<temp[i]<<endl;
            cout<<table[i]<<endl;
            temp[i] = table[i];
            cout<<table[i]<<endl;
            cout<<temp[i]<<endl;
        }
        rozmiar--;
        //delete [] table;
        table = temp;
        delete [] temp;
    }
} // std