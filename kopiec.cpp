//
// Created by jakub on 3/12/2023.
//

#include "kopiec.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

    kopiec::kopiec(int liczba){
        dodaj(liczba);
        start = false;
    }

    void kopiec::pokaz(string sp, string sn, int v) {
        string s;
        string cr, cl, cp;
        cr = cl = cp = "  ";
        cr [ 0 ] = 218; cr [ 1 ] = 196;
        cl [ 0 ] = 192; cl [ 1 ] = 196;
        cp [ 0 ] = 179;
        if( v < rozmiar )
        {
            s = sp;
            if( sn == cr ) s [ s.length( ) - 2 ] = ' ';
            pokaz( s + cp, cr, 2 * v + 2 );

            s = s.substr ( 0, sp.length( ) - 2 );

            cout << s << sn << table [ v ] << endl;

            s = sp;
            if( sn == cl ) s [ s.length( ) - 2 ] = ' ';
            pokaz( s + cp, cl, 2 * v + 1 );
        }
    }

    void kopiec::dodaj(int liczba) {
        temp = new int[++rozmiar];
        for(int i=0;i<rozmiar-1;i++) temp[i] = table[i];
        temp[rozmiar-1] = liczba;
        relocate();
        sort();
    }

    void kopiec::usunKorzen() {
        if(rozmiar==0) return;
        swap(table[0],table[rozmiar-1]);
        temp = new int[--rozmiar];
        for(int i=0;i<rozmiar;i++) temp[i] = table[i];
        relocate();
        int i=0;
        int j=1;
        while(j < rozmiar){ // tu chyba bug?, kod z neta dziala
            if(j+1 < rozmiar && table[j+1] > table[j]) j++;
            if(table[i] >= table[j]) break;
            swap(table[i],table[j]);
            i = j;
            j = 2*j+1;
        }
    }

    void kopiec::sort(){
        int i=rozmiar-1;
        while(true){
            if(table[i]>table[(int)floor((((double)i)-1)/2)] && i!=0 && (int)floor((((double)i)-1)/2)>=0) {
                swap(table[i],table[(int)floor((((double)i)-1)/2)]);
                i = (int)floor((((double)i)-1)/2);
            } else break;
        }
    }

    void kopiec::relocate(){
    if(!start) delete [] table;
    table = new int[rozmiar];
    for(int i=0;i<rozmiar;i++) table[i] = temp[i];
    delete [] temp;
}

    bool kopiec::isCorrect(){
        int i=0;
        while(i<rozmiar){
            if(2*i+1>=rozmiar) break;
            if(table[i]<table[2*i+1] || table[i]<table[2*i+2] && 2*i+2<rozmiar){
                cout<<"BLAD KOPCA w "<<i<<endl;
                return false;
            } else i++;
        }
        cout<<"KOPIEC POPRAWNY"<<endl;
        return true;
    }

    void kopiec::test(int iloscTestow, int wielkoscZestawu, int iloscOperacji){
        srand(time(NULL));
        for (int i = 0; i < iloscTestow; i++) {
            for(int k=0;k<wielkoscZestawu;k++) dodaj(rand() % 1000);
            cout << "TEST " << i << endl;
            for (int j = 0; j < iloscOperacji; j++) {
                switch (rand() % 2 + 1) {
                    case 1:
                        dodaj(rand() % 1000);
                        break;
                    case 2:
                        usunKorzen();
                        break;
                }
            }
            if(isCorrect()) cout<<"TEST "<<i<< " ZALICZONY"<<endl;
            if(rozmiar!=0) for(int k=0;k<rozmiar;k++) usunKorzen();
        }
    }