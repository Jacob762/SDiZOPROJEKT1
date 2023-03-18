//
// Created by Jakub Klawon on 08/03/2023.
//

#ifndef SDIZO_LISTA_H
#define SDIZO_LISTA_H
#include "listaElement.h"

class lista {
private:
    listaElement * head;
    listaElement * tail;
public:
    int rozmiar;
    lista();
    void pokaz();
    void dodajNaKoniec(listaElement * element);
    void dodajNaPoczatek(listaElement *element);
    bool isEmpty();
    bool isEven();
    float mediana();
    listaElement* wyszukajElement(float index);
    void dodajWDowolnymMiejscu(int index,listaElement * element);
    void usunZPoczatku();
    void usunZKonca();
    void usunZDowolnegoMiejsca(int index);
    bool safetyFirst();
};


#endif //SDIZO_LISTA_H
