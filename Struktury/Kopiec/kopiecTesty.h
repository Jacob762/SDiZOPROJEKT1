//
// Created by jakub on 3/19/2023.
//

#ifndef SDIZO_KOPIECTESTY_H
#define SDIZO_KOPIECTESTY_H
#include <fstream>
#include <iostream>
#include <chrono>
#include "kopiec.h"

class kopiecTesty {
public:
    kopiecTesty(int wielkoscZestawu,int iloscOperacji,int iloscWynikow);
    kopiec kopie;
private:
    void test(int wielkoscZestawu, int iloscOperacji, int iloscWynikow);
};


#endif //SDIZO_KOPIECTESTY_H
