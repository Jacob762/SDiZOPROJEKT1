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
    }

    void kopiec::pokaz(string sp, string sn, int v) {
        string s;
        string cr, cl, cp;
        cr = cl = cp = "  ";
        cr [ 0 ] = 218; cr [ 1 ] = 196;
        cl [ 0 ] = 192; cl [ 1 ] = 196;
        cp [ 0 ] = 179;
        if( v < wezly )
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
        wezly++;
        relocate();
        sort();
    }

    void kopiec::usunKorzen() { // w tej funkcji bug
        if(rozmiar==0) return;
        swap(table[0],table[rozmiar-1]);
        temp = new int[--rozmiar];
        for(int i=0;i<rozmiar;i++) temp[i] = table[i];
        wezly--;
        relocate();
        int i=0;
        while(true){ // tu chyba bug?
            if(table[i]<table[2*i+1] && table[2*i+1]>table[2*i+2] && i<rozmiar && 2*i+1<rozmiar) {
                swap(table[i], table[2 * i + 1]);
                i=2*i+1;
            }else if(table[i]<table[2*i+2] && table[2*i+2]>table[2*i+1] && i<rozmiar && 2*i+2<rozmiar){
                swap(table[i], table[2 * i + 2]);
                i=2*i+2;
            }else break;
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
    delete [] table;
    table = new int[rozmiar];
    for(int i=0;i<rozmiar;i++) table[i] = temp[i];
    delete [] temp;
}


