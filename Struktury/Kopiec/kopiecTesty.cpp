//
// Created by jakub on 3/19/2023.
//

#include "kopiecTesty.h"
#include <cmath>

using namespace std;

kopiecTesty::kopiecTesty() {
    kopie = kopiec();
}

void kopiecTesty::test(int wielkoscZestawu,int iloscOperacji,int iloscWynikow){
    chrono::high_resolution_clock::time_point t1;
    chrono::high_resolution_clock::time_point t2;
    ofstream tablicaFile ("wynikiPomiarowKopca.txt",ios::out|ios::app); //zrobic zabezpiczeenie zeby za kazdym razem generowal sie nowy plik
    double srednia;
    double srednia2;
    double tablicaSrednich1[iloscWynikow];
    double tablicaSrednich2[iloscWynikow];
    ::srand(time(NULL));
    double tablicaCzasow[iloscOperacji];
    double tablicaCzasow1[iloscOperacji];
//badanie dodawqania na koniec i odejmowania z konca
    for(int j=0;j<iloscWynikow;j++){
        srednia=0;
        srednia2=0;
        for(int i=0;i<iloscOperacji;i++){
            for(int k=0;k<wielkoscZestawu;k++) kopie.dodaj(rand()%1000+1);
            int numb = rand()%1000+1;
            t1 = chrono::high_resolution_clock::now();
            kopie.dodaj(numb);
            t2 = chrono::high_resolution_clock::now();
            chrono::duration<double> time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow[i] = std::chrono::duration<double>(time_span).count();
            srednia+=tablicaCzasow[i];
            t1 = chrono::high_resolution_clock::now();
            kopie.usunKorzen();
            t2 = chrono::high_resolution_clock::now();
            time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow1[i] = std::chrono::duration<double>(time_span).count();
            srednia2+=tablicaCzasow1[i];
            for(int k=0;k<wielkoscZestawu;k++) kopie.usunKorzen();
        }
        tablicaSrednich1[j] = srednia/iloscOperacji;
        tablicaSrednich2[j] = srednia2/iloscOperacji;
    }
    if(tablicaFile.is_open()){
        tablicaFile<<"WLASCIWOSCI: WIELKOSC ZESTAWU: "<< wielkoscZestawu<<" ILOSC OPERACJI: "<<iloscOperacji<<endl;
        tablicaFile<<"DODAWANIE: ";
        for(int i=0;i<iloscWynikow;i++) tablicaFile<<tablicaSrednich1[i]*pow(10,9)<<" ";
        tablicaFile<<endl;
        tablicaFile<<"USUWANIE: ";
        for(int i=0;i<iloscWynikow;i++) tablicaFile<<tablicaSrednich2[i]*pow(10,9)<<" ";
        tablicaFile<<endl;
    }
    for(int j=0;j<iloscWynikow;j++){
        srednia=0;
        for(int i=0;i<iloscOperacji;i++){
            for(int k=0;k<wielkoscZestawu;k++) kopie.dodaj(rand()%1000+1);
            kopie.usunKorzen();
            int liczba = kopie.table[0]-kopie.table[0]/2;
            kopie.dodaj(liczba);
            t1 = chrono::high_resolution_clock::now();
            kopie.wyszukaj(liczba); 
            t2 = chrono::high_resolution_clock::now();
            chrono::duration<double> time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow[i] = std::chrono::duration<double>(time_span).count();
            srednia+=tablicaCzasow[i];
            for(int k=0;k<wielkoscZestawu;k++) kopie.usunKorzen();
        }
        tablicaSrednich1[j] = srednia/iloscOperacji;
    }
    if(tablicaFile.is_open()){
        tablicaFile<<"Wyszukiwanie: ";
        for(int i=0;i<iloscWynikow;i++) tablicaFile<<tablicaSrednich1[i]*pow(10,9)<<" ";
        tablicaFile<<endl;
        tablicaFile<<endl<<endl;
    }
    cout<<"TESTY NA KOPCU ZAKONCZONE SUKCESEM"<<endl;
}
