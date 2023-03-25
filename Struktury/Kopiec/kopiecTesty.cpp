//
// Created by jakub on 3/19/2023.
//

#include "kopiecTesty.h"

using namespace std;

kopiecTesty::kopiecTesty(int wielkoscZestawu,int iloscOperacji,int iloscWynikow) {
    kopie = kopiec();
    test(wielkoscZestawu,iloscOperacji,iloscWynikow);
    cout<<"TESTY NA KOPCU ZAKONCZONE SUKCESEM"<<endl;
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
        tablicaSrednich1[j] = srednia/1000;
        tablicaSrednich2[j] = srednia2/1000;
    }
    if(tablicaFile.is_open()){
        tablicaFile<<"WLASCIWOSCI: WIELKOSC ZESTAWU: "<< wielkoscZestawu<<" ILOSC OPERACJI: "<<iloscOperacji<<endl;
        tablicaFile<<"WYNIKI DODAWANIA: ";
        for(int i=0;i<iloscWynikow;i++) tablicaFile<<tablicaSrednich1[i]<<" ";
        tablicaFile<<endl;
        tablicaFile<<"WYNIKI USUWANIA: ";
        for(int i=0;i<iloscWynikow;i++) tablicaFile<<tablicaSrednich1[i]<<" ";
        tablicaFile<<endl<<endl;
    }
    for(int j=0;j<iloscWynikow;j++){
        srednia=0;
        for(int i=0;i<iloscOperacji;i++){
            for(int k=0;k<wielkoscZestawu;k++) kopie.dodaj(rand()%1000+1);
            int indeks = kopie.table[rand()%(wielkoscZestawu/2+(wielkoscZestawu/2 -50))];
            t1 = chrono::high_resolution_clock::now();
            kopie.wyszukaj(indeks);
            t2 = chrono::high_resolution_clock::now();
            chrono::duration<double> time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow[i] = std::chrono::duration<double>(time_span).count();
            srednia+=tablicaCzasow[i];
            for(int k=0;k<wielkoscZestawu;k++) kopie.usunKorzen();
        }
        tablicaSrednich1[j] = srednia/1000;
    }
    if(tablicaFile.is_open()){
        tablicaFile<<"WYNIKI WYSZUKIWANIA Z DOWOLNEGO MIEJSCA W POLOWIE ZESTAWU: ";
        for(int i=0;i<iloscWynikow;i++) tablicaFile<<tablicaSrednich1[i]<<" ";
        tablicaFile<<endl;
        tablicaFile<<endl<<endl;
    }
}
