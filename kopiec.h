//
// Created by jakub on 3/12/2023.
//

#ifndef SDIZO_KOPIEC_H
#define SDIZO_KOPIEC_H
#include <string>

class kopiec {
public:
    kopiec();
    int * temp;
    int rozmiar = 0;
    int* table;
    int wezly;
    kopiec(int liczba);
    void dodaj(int liczba);
    void usunKorzen();
    void pokaz(std::string sp, std::string sn, int v);
    void relocate();
    void sort();
};


#endif //SDIZO_KOPIEC_H
