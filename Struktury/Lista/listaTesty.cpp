//
// Created by jakub on 3/19/2023.
//

#include <fstream>
#include "listaTesty.h"

using namespace std;

listaTesty::listaTesty(int wielkoscZestawu,int iloscOperacji,int iloscWynikow) {
    list = lista();
    test(wielkoscZestawu,iloscOperacji,iloscWynikow);
    cout<<"TESTY NA LISCIE ZAKONCZONE SUKCESEM"<<endl;
}

void listaTesty::test(int wielkoscZestawu,int iloscOperacji,int iloscWynikow) {
    chrono::high_resolution_clock::time_point t1;
    chrono::high_resolution_clock::time_point t2;
    ofstream listaFile ("wynikiPomiarowListy.txt",ios::out|ios::app); //zrobic zabezpiczeenie zeby za kazdym razem generowal sie nowy plik
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
            for(int k=0;k<wielkoscZestawu;k++) list.dodajNaKoniec(new listaElement(rand()%1000+1));
            int numb = rand()%1000+1;
            listaElement* element = new listaElement(numb);
            t1 = chrono::high_resolution_clock::now();
            list.dodajNaKoniec(element);
            t2 = chrono::high_resolution_clock::now();
            chrono::duration<double> time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow[i] = std::chrono::duration<double>(time_span).count();
            srednia+=tablicaCzasow[i];
            t1 = chrono::high_resolution_clock::now();
            list.usunZKonca();
            t2 = chrono::high_resolution_clock::now();
            time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow1[i] = std::chrono::duration<double>(time_span).count();
            srednia2+=tablicaCzasow1[i];
            for(int k=0;k<wielkoscZestawu;k++) list.usunZKonca();
        }
        tablicaSrednich1[j] = srednia/1000;
        tablicaSrednich2[j] = srednia2/1000;
    }
    if(listaFile.is_open()){
        listaFile<<"WLASCIWOSCI: WIELKOSC ZESTAWU: "<< wielkoscZestawu<<" ILOSC OPERACJI: "<<iloscOperacji<<endl;
        listaFile<<"WYNIKI DODAWANIA NA KONIEC: ";
        for(int i=0;i<iloscWynikow;i++) listaFile<<tablicaSrednich1[i]<<" ";
        listaFile<<endl;
        listaFile<<"WYNIKI USUWANIA Z KONCA: ";
        for(int i=0;i<iloscWynikow;i++) listaFile<<tablicaSrednich1[i]<<" ";
        listaFile<<endl;
    }
    //badanie dodawania na poczatrke i odjemwonai az koncu
    for(int j=0;j<iloscWynikow;j++){
        srednia=0;
        srednia2=0;
        for(int i=0;i<iloscOperacji;i++){
            for(int k=0;k<wielkoscZestawu;k++) list.dodajNaKoniec(new listaElement(rand()%1000+1));
            int numb = rand()%1000+1;
            listaElement* element = new listaElement(numb);
            t1 = chrono::high_resolution_clock::now();
            list.dodajNaPoczatek(element);
            t2 = chrono::high_resolution_clock::now();
            chrono::duration<double> time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow[i] = std::chrono::duration<double>(time_span).count();
            srednia+=tablicaCzasow[i];
            t1 = chrono::high_resolution_clock::now();
            list.usunZPoczatku();
            t2 = chrono::high_resolution_clock::now();
            time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow1[i] = std::chrono::duration<double>(time_span).count();
            srednia2+=tablicaCzasow1[i];
            for(int k=0;k<wielkoscZestawu;k++) list.usunZKonca();
        }
        tablicaSrednich1[j] = srednia/1000;
        tablicaSrednich2[j] = srednia2/1000;
    }
    if(listaFile.is_open()){
        listaFile<<"WYNIKI DODAWANIA NA POCZATEK: ";
        for(int i=0;i<iloscWynikow;i++) listaFile<<tablicaSrednich1[i]<<" ";
        listaFile<<endl;
        listaFile<<"WYNIKI USUWANIA Z POCZATKU: ";
        for(int i=0;i<iloscWynikow;i++) listaFile<<tablicaSrednich1[i]<<" ";
        listaFile<<endl;
    }
    //badanie dodawania i odejmowania z dowolnego miejsca w polowie
    for(int j=0;j<iloscWynikow;j++){
        srednia=0;
        srednia2=0;
        for(int i=0;i<iloscOperacji;i++){
            for(int k=0;k<wielkoscZestawu;k++) list.dodajNaKoniec(new listaElement(rand()%1000+1));
            int numb = rand()%1000+1;
            int indeks = rand()%(wielkoscZestawu/2+(wielkoscZestawu/2 -50));
            listaElement* element = new listaElement(numb);
            t1 = chrono::high_resolution_clock::now();
            list.dodajWDowolnymMiejscu(indeks,element);
            t2 = chrono::high_resolution_clock::now();
            chrono::duration<double> time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow[i] = std::chrono::duration<double>(time_span).count();
            srednia+=tablicaCzasow[i];
            t1 = chrono::high_resolution_clock::now();
            list.usunZDowolnegoMiejsca(indeks);
            t2 = chrono::high_resolution_clock::now();
            time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow1[i] = std::chrono::duration<double>(time_span).count();
            srednia2+=tablicaCzasow1[i];
            for(int k=0;k<wielkoscZestawu;k++) list.usunZKonca();
        }
        tablicaSrednich1[j] = srednia/1000;
        tablicaSrednich2[j] = srednia2/1000;
    }
    if(listaFile.is_open()){
        listaFile<<"WYNIKI DODAWANIA NA DOWOLNE MIEJSCE: ";
        for(int i=0;i<iloscWynikow;i++) listaFile<<tablicaSrednich1[i]<<" ";
        listaFile<<endl;
        listaFile<<"WYNIKI USUWANIA Z DOWOLNEGO MIEJSCA: ";
        for(int i=0;i<iloscWynikow;i++) listaFile<<tablicaSrednich1[i]<<" ";
        listaFile<<endl;
    }
    for(int j=0;j<iloscWynikow;j++){
        srednia=0;
        for(int i=0;i<iloscOperacji;i++){
            for(int k=0;k<wielkoscZestawu;k++) list.dodajNaKoniec(new listaElement(rand()%1000+1));
            int indeks = rand()%(wielkoscZestawu/2+(wielkoscZestawu/2 -50));
            t1 = chrono::high_resolution_clock::now();
            list.wyszukajElement(indeks);
            t2 = chrono::high_resolution_clock::now();
            chrono::duration<double> time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow[i] = std::chrono::duration<double>(time_span).count();
            srednia+=tablicaCzasow[i];
            for(int k=0;k<wielkoscZestawu;k++) list.usunZKonca();
        }
        tablicaSrednich1[j] = srednia/1000;
    }
    if(listaFile.is_open()){
        listaFile<<"WYNIKI WYSZUKIWANIA Z DOWOLNEGO MIEJSCA W POLOWIE ZESTAWU: ";
        for(int i=0;i<iloscWynikow;i++) listaFile<<tablicaSrednich1[i]<<" ";
        listaFile<<endl;
        listaFile<<endl<<endl;
    }
}