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
    void pokaz();
};


#endif //SDIZO_LISTA_H
