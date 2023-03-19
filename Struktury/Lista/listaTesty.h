//
// Created by jakub on 3/19/2023.
//

#ifndef SDIZO_LISTATESTY_H
#define SDIZO_LISTATESTY_H
#include "lista.h"
#include "listaElement.h"
#include <iostream>

class listaTesty {
    lista list;
private:
    void test(int wielkoscZestawu, int iloscOperacji, int iloscWynikow);

public:
    listaTesty(int wielkoscZestawu,int iloscOperacji,int iloscWynikow);
};


#endif //SDIZO_LISTATESTY_H
