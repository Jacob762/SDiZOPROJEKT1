//
// Created by Jakub Klawon on 08/03/2023.
//

#ifndef SDIZO_LISTAELEMENT_H
#define SDIZO_LISTAELEMENT_H


class listaElement {
public:
    int data;
    listaElement * prevEl;
    listaElement * nextEl;
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


#endif //SDIZO_LISTAELEMENT_H
