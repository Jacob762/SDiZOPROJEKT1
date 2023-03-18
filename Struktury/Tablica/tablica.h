//
// Created by Jakub Klawon on 07/03/2023.
//

#ifndef SDIZO_TABLICA_H
#define SDIZO_TABLICA_H
#include <iostream>
#include <stdio.h>

namespace std {

    class tablica {
    public:
        int * table;
        int * temp;
        int rozmiar;
        void init(int rozmiar);
        void menu();
        void dodajNaPoczatek(int liczba);
        void dodajNaKoniec(int liczba);
        void dodajNaDowolneMiejsce(int liczba, int index);
        void usunZPoczatku();
        void usunZKonca();
        void usunZDowolnegoMiejsca(int index);
        void pokaz();
        void relocate();
    };

} // std

#endif //SDIZO_TABLICA_H
