//
// Created by Jakub Klawon on 08/03/2023.
//

#include <fstream>
#include "tablicaTesty.h"

using namespace std;

    tablicaTesty::tablicaTesty(int wielkoscZestawu,int iloscOperacji,int iloscWynikow) {
    tablicaTest = tablica();
        test(wielkoscZestawu,iloscOperacji,iloscWynikow);
        cout<<"TESTY NA TABLICY ZAKONCZONE SUKCESEM"<<endl;
    }

void tablicaTesty::test(int wielkoscZestawu,int iloscOperacji,int iloscWynikow){
    chrono::high_resolution_clock::time_point t1;
    chrono::high_resolution_clock::time_point t2;
    ofstream tablicaFile ("wynikiPomiarowTablicy.txt",ios::out|ios::app); //zrobic zabezpiczeenie zeby za kazdym razem generowal sie nowy plik
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
            for(int k=0;k<wielkoscZestawu;k++) tablicaTest.dodajNaKoniec(rand()%1000+1);
            int numb = rand()%1000+1;
            t1 = chrono::high_resolution_clock::now();
            tablicaTest.dodajNaKoniec(numb);
            t2 = chrono::high_resolution_clock::now();
            chrono::duration<double> time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow[i] = std::chrono::duration<double>(time_span).count();
            srednia+=tablicaCzasow[i];
            t1 = chrono::high_resolution_clock::now();
            tablicaTest.usunZKonca();
            t2 = chrono::high_resolution_clock::now();
            time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow1[i] = std::chrono::duration<double>(time_span).count();
            srednia2+=tablicaCzasow1[i];
            for(int k=0;k<wielkoscZestawu;k++) tablicaTest.usunZKonca();
        }
        tablicaSrednich1[j] = srednia/1000;
        tablicaSrednich2[j] = srednia2/1000;
    }
    if(tablicaFile.is_open()){
        tablicaFile<<"WLASCIWOSCI: WIELKOSC ZESTAWU: "<< wielkoscZestawu<<" ILOSC OPERACJI: "<<iloscOperacji<<endl;
        tablicaFile<<"WYNIKI DODAWANIA NA KONIEC: ";
        for(int i=0;i<iloscWynikow;i++) tablicaFile<<tablicaSrednich1[i]<<" ";
        tablicaFile<<endl;
        tablicaFile<<"WYNIKI USUWANIA Z KONCA: ";
        for(int i=0;i<iloscWynikow;i++) tablicaFile<<tablicaSrednich1[i]<<" ";
        tablicaFile<<endl;
    }
    //badanie dodawania na poczatrke i odjemwonai az koncu
    for(int j=0;j<iloscWynikow;j++){
        srednia=0;
        srednia2=0;
        for(int i=0;i<iloscOperacji;i++){
            for(int k=0;k<wielkoscZestawu;k++) tablicaTest.dodajNaKoniec(rand()%1000+1);
            int numb = rand()%1000+1;
            t1 = chrono::high_resolution_clock::now();
            tablicaTest.dodajNaPoczatek(numb);
            t2 = chrono::high_resolution_clock::now();
            chrono::duration<double> time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow[i] = std::chrono::duration<double>(time_span).count();
            srednia+=tablicaCzasow[i];
            t1 = chrono::high_resolution_clock::now();
            tablicaTest.usunZPoczatku();
            t2 = chrono::high_resolution_clock::now();
            time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow1[i] = std::chrono::duration<double>(time_span).count();
            srednia2+=tablicaCzasow1[i];
            for(int k=0;k<wielkoscZestawu;k++) tablicaTest.usunZKonca();
        }
        tablicaSrednich1[j] = srednia/1000;
        tablicaSrednich2[j] = srednia2/1000;
    }
    if(tablicaFile.is_open()){
        tablicaFile<<"WYNIKI DODAWANIA NA POCZATEK: ";
        for(int i=0;i<iloscWynikow;i++) tablicaFile<<tablicaSrednich1[i]<<" ";
        tablicaFile<<endl;
        tablicaFile<<"WYNIKI USUWANIA Z POCZATKU: ";
        for(int i=0;i<iloscWynikow;i++) tablicaFile<<tablicaSrednich1[i]<<" ";
        tablicaFile<<endl;
    }
    //badanie dodawania i odejmowania z dowolnego miejsca w polowie
    for(int j=0;j<iloscWynikow;j++){
        srednia=0;
        srednia2=0;
        for(int i=0;i<iloscOperacji;i++){
            for(int k=0;k<wielkoscZestawu;k++) tablicaTest.dodajNaKoniec(rand()%1000+1);
            int numb = rand()%1000+1;
            int indeks = rand()%(wielkoscZestawu/2+(wielkoscZestawu/2 -50));
            t1 = chrono::high_resolution_clock::now();
            tablicaTest.dodajNaDowolneMiejsce(indeks,numb);
            t2 = chrono::high_resolution_clock::now();
            chrono::duration<double> time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow[i] = std::chrono::duration<double>(time_span).count();
            srednia+=tablicaCzasow[i];
            t1 = chrono::high_resolution_clock::now();
            tablicaTest.usunZDowolnegoMiejsca(indeks);
            t2 = chrono::high_resolution_clock::now();
            time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow1[i] = std::chrono::duration<double>(time_span).count();
            srednia2+=tablicaCzasow1[i];
            for(int k=0;k<wielkoscZestawu;k++) tablicaTest.usunZKonca();
        }
        tablicaSrednich1[j] = srednia/1000;
        tablicaSrednich2[j] = srednia2/1000;
    }
    if(tablicaFile.is_open()){
        tablicaFile<<"WYNIKI DODAWANIA NA DOWOLNE MIEJSCE: ";
        for(int i=0;i<iloscWynikow;i++) tablicaFile<<tablicaSrednich1[i]<<" ";
        tablicaFile<<endl;
        tablicaFile<<"WYNIKI USUWANIA Z DOWOLNEGO MIEJSCA: ";
        for(int i=0;i<iloscWynikow;i++) tablicaFile<<tablicaSrednich1[i]<<" ";
        tablicaFile<<endl;
        tablicaFile<<endl<<endl;
    }

}