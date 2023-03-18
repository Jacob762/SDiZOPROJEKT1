//
// Created by Jakub Klawon on 08/03/2023.
//

#include "tablicaTesty.h"

using namespace std;

void tablicaTesty::init(){
    srand(time(NULL));
    tablicaTest.rozmiar = rand()%10+1;
    tablicaTest.init(tablicaTest.rozmiar);
    for(int i=0;i<tablicaTest.rozmiar;i++) tablicaTest.table[i] = rand()%100+1;
    tablicaTest.pokaz();
}

void tablicaTesty::test(){
    init();
    for(int i=0;i<50;i++){
        tablicaTest.dodajNaPoczatek(rand()%100+1);
        tablicaTest.dodajNaKoniec(rand()%100+1);
        tablicaTest.dodajNaDowolneMiejsce(rand()%100+1, rand()%tablicaTest.rozmiar+1);
    }
    tablicaTest.pokaz();
    for(int i=0;i<50;i++){
        tablicaTest.usunZKonca();
        tablicaTest.usunZPoczatku();
        tablicaTest.usunZDowolnegoMiejsca(rand()%tablicaTest.rozmiar+1);
    }
    tablicaTest.pokaz();
}