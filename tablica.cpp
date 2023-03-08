//
// Created by Jakub Klawon on 07/03/2023.
//

#include "tablica.h"

namespace std {
    void tablica::init(int rozmiar) {
        table = new int[rozmiar];
        for(int i=0;i<rozmiar;i++) table[i] = rand()%100+1;
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
            cout<<"6. Usum z konca"<<endl;
            cout<<"7. Usun z poczatku"<<endl;
            cout<<"8. Usun z dowolnego miejsca"<<endl;
            cout<<"9. Wyszukaj element"<<endl;
            cin.sync(); cin.clear();
            cin>>n;
            switch (n) {
                case 1:
                    cin.sync(); cin.clear();
                    cout<<"Podaj liczbe"<<endl;
                    cin>>liczba;
                    dodajNaKoniec(liczba);
                    break;
                case 2:
                    pokaz();
                    break;
                case 4:
                    cin.sync(); cin.clear();
                    cout<<"Podaj liczbe"<<endl;
                    cin>>liczba;
                    dodajNaPoczatek(liczba);
                    break;
                case 5:
                    cin.sync(); cin.clear();
                    cout<<"Podaj liczbe"<<endl;
                    cin>>liczba;
                    cout<<"Podaj indeks"<<endl;
                    cin>>n;
                    dodajNaDowolneMiejsce(liczba,n);
                    break;
                case 6:
                    cin.sync(); cin.clear();
                    usunZKonca();
                    break;
                case 7:
                    cin.sync(); cin.clear();
                    usunZPoczatku();
                    break;
                case 8:
                    cin.sync(); cin.clear();
                    cout<<"Podaj indeks"<<endl;
                    cin>>n;
                    usunZDowolnegoMiejsca(n);
                    break;
                case 9:
                    cin.sync(); cin.clear();
                    cout<<"Podaj indeks"<<endl;
                    cin>>n;
                    table[n];
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
        relocate();
    }
    void tablica::dodajNaPoczatek(int liczba) {
        temp = new int[++rozmiar];
        temp[0] = liczba;
        for(int i=1;i<rozmiar;i++) temp[i] = table[i-1];
        relocate();
    }
    void tablica::dodajNaDowolneMiejsce(int liczba, int index) {
        temp = new int[++rozmiar];
        temp[index] = liczba;
        for(int i=0;i<index;i++) temp[i] = table[i];
        for(int i=index+1;i<rozmiar;i++) temp[i] = table[i-1];
        relocate();
    }
    void tablica::usunZKonca() {
        temp = new int[--rozmiar];
        for(int i=0;i<rozmiar-1;i++) temp[i] = table[i];
        relocate();
    }
    void tablica::relocate(){
        delete [] table;
        table = new int[rozmiar];
        for(int i=0;i<rozmiar;i++) table[i] = temp[i];
        delete [] temp;
    }
    void tablica::usunZPoczatku() {
        temp = new int[--rozmiar];
        for(int i=0;i<rozmiar;i++) temp[i] = table[i+1];
        relocate();
    }
    void tablica::usunZDowolnegoMiejsca(int index) {
        temp = new int[--rozmiar];
        for(int i=0;i<index;i++) temp[i] = table[i];
        for(int i=index;i<rozmiar;i++) temp[i] = table[i+1];
        relocate();
    }
} // std