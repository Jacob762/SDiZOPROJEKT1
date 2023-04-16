//
// Created by Jakub Klawon on 05/04/2023.
//

#include "RBTreeTesty.h"
#include <fstream>
#include <cmath>

namespace std {
    RBTreeTesty::RBTreeTesty(){
        tree = new RBTree();
    }

    void RBTreeTesty::rbtTesty(int wielkoscZestawu, int iloscOperacji, int iloscWynikow) {
        chrono::high_resolution_clock::time_point t1;
        chrono::high_resolution_clock::time_point t2;
        ofstream drzewoFile ("wynikiPomiarowRBTree.txt",ios::out|ios::app); //zrobic zabezpiczeenie zeby za kazdym razem generowal sie nowy plik
        double srednia;
        double srednia2;
        double srednia3;
        double tablicaSrednich1[iloscWynikow];
        double tablicaSrednich2[iloscWynikow];
        double tablicaSrednich3[iloscWynikow];
        ::srand(time(NULL));
        double tablicaCzasow[iloscOperacji];
        double tablicaCzasow1[iloscOperacji];
        double tablicaCzasow2[iloscOperacji];
        //badanie dodawqania na koniec i odejmowania z konca
        for(int j=0;j<iloscWynikow;j++){
            srednia=0;
            srednia2=0;
            srednia3=0;
            for(int i=0;i<iloscOperacji;i++){
                for(int k=0;k<wielkoscZestawu;k++) tree->dodaj(rand()%1000+1);
                int numb = rand()%1000+1;
                tree->dodaj(numb);
                t1 = chrono::high_resolution_clock::now();
                tree->wyszukaj(numb);
                t2 = chrono::high_resolution_clock::now();
                chrono::duration<double> time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
                tablicaCzasow2[i] = std::chrono::duration<double>(time_span).count();
                srednia3+=tablicaCzasow2[i];
                for(int k=0;k<wielkoscZestawu;k++) tree->usun(tree->root);
            }

            tablicaSrednich3[j] = srednia3/iloscOperacji;
        }
        if(drzewoFile.is_open()){
            drzewoFile<<"Wyszukiwanie : ";
            for(int i=0;i<iloscWynikow;i++) drzewoFile<<tablicaSrednich3[i]*pow(10,9)<<" ";
            drzewoFile<<endl;
        }
        cout<<"FINITO"<<endl;
    }
} // std