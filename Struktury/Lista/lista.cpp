//
// Created by Jakub Klawon on 08/03/2023.
//

#include "lista.h"
#include <iostream>
#include <fstream>

using namespace std;

lista::lista(){
    head = NULL;
    tail = NULL;
    rozmiar=0;
}

void lista::dodajNaKoniec(listaElement * element) {
    if (!head) {
        head = element;
        tail = element;
    }
    else {
        tail->nextEl = element;
        element->prevEl = tail;
        tail = element;
    }
    if (head == element) element->prevEl = NULL;
    if (tail == element) element->nextEl = NULL;
    rozmiar++;
}

void lista::dodajNaPoczatek(listaElement * element){
    if (!head) {
        head = element;
        tail = element;
    }
    else {
        head->prevEl = element;
        element->nextEl = head;
        head = element;
    }
    if (head == element) element->prevEl = NULL;
    if (tail == element) element->nextEl = NULL;
    rozmiar++;
}

void lista::dodajWDowolnymMiejscu(int index,listaElement * element){
    if(index<0||index>=rozmiar&&index!=0) return;
    if (!head) {
        head = element;
        tail = element;
        rozmiar++;
    }
    else if(index==0){ //head
        dodajNaPoczatek(element);
    }
    else if(index==rozmiar-1){  //tail
        dodajNaKoniec(element);
    }
    else {
        listaElement* temp = wyszukajElement(index);
        temp->prevEl->nextEl = element;
        element->prevEl = temp->prevEl;
        element->nextEl = temp;
        temp->prevEl = element;
        rozmiar++;
    }
    if (head == element) element->prevEl = NULL;
    if (tail == element) element->nextEl = NULL;
}

void lista::pokaz() {
    if(isEmpty()) return;
    listaElement* temp;
    temp = head;
    for(int i=0;i<rozmiar;i++){
        cout<<temp->data<<" ";
        temp = temp -> nextEl;
    }
    cout<<endl;
    delete temp;
}

listaElement* lista::wyszukajElement(float index) {
    listaElement* temp;
    float m = mediana();
    if(index<m) {
        temp = head;
        for(int i=0;i<index;i++){
            temp = temp -> nextEl;
        }
    }
    else {
        temp = tail;
        for(int i=0;i<index;i++){
            temp = temp -> prevEl;
        }
    }
    return temp;
}
bool lista::isEmpty() {
    if(!head) return true;
    else return false;
}

bool lista::isEven(){
    if(rozmiar%2) return false;
    else return true;
}

float lista::mediana(){
    if(isEven()) return (((double)rozmiar)/2-0.5)+(((double)rozmiar)/2+0.5)/2;
    else return ((double)rozmiar)/2+0.5;
}

void lista::usunZPoczatku(){
    if(!safetyFirst()) return;
    head->nextEl->prevEl = NULL;
    head = head->nextEl;
    rozmiar--;
}

void lista::usunZKonca(){
    if(!safetyFirst()) return;
    tail->prevEl->nextEl = NULL;
    tail = tail->prevEl;
    rozmiar--;
}

void lista::usunZDowolnegoMiejsca(int index){
    if(!safetyFirst()) return;
    if(index<0||index>=rozmiar&&index!=0) return;
    else if(index==0){ //head
        usunZPoczatku();
    }
    else if(index==rozmiar-1){  //tail
        usunZKonca();
    }
    else {
        listaElement* temp = wyszukajElement(index);
        temp->prevEl->nextEl = temp->nextEl;
        temp->nextEl->prevEl = temp->prevEl;
        delete temp;
        rozmiar--;
    }
}

bool lista::safetyFirst(){
    if(isEmpty()) return false;
    else if(tail==head){
        head=NULL;
        tail=NULL;
        rozmiar=0;
        return false;
    }
    else return true;
}
void lista::wczytaj(string nazwa) {
    FILE* strumien;
    char tab[nazwa.length()];
    for(int i=0;i<nazwa.length();i++) tab[i] = nazwa.at(i);
    strumien = fopen(tab, "rt");
    if(strumien==NULL || head!=NULL){
        cout<<"ERROR"<<endl;
        return;
    }
    while (!feof(strumien)){
        int number;
        fscanf(strumien,"%d",&number);
        dodajNaKoniec(new listaElement(number));
    }
    fclose(strumien);
}

void lista::zapisz(string nazwa) {
    if (!safetyFirst()){
        cout<<"Brak utworzonej tablicy."<<endl;
        return;
    }
    ofstream file (nazwa);
    if (!file.is_open()) {
        cout<<"ERROR"<<endl;
        return;
    }
    listaElement* temp = head;
    for(int i=0;i<rozmiar;i++){
        file<< temp->data<< " ";
        temp = temp -> nextEl;
    }

}

void lista::menu() {
    int n;
    int liczba;
    string name;
    for(;;){
        cout<<"Podaj numer akcji ktora chcesz wykonac:"<<endl;
        cout<<"1. Dodaj na koniec"<<endl;
        cout<<"2. Pokaz"<<endl;
        cout<<"3. Wyszukaj element"<<endl;
        cout<<"4. Dodaj na poczatek"<<endl;
        cout<<"5. Dodaj w danym miejscu"<<endl;
        cout<<"6. Usum z konca"<<endl;
        cout<<"7. Usun z poczatku"<<endl;
        cout<<"8. Usun z dowolnego miejsca"<<endl;
        cout<<"9. Wyjdz"<<endl;
        cout<<"10. Wczytaj dane"<<endl;
        cout<<"11. Zapisz dane"<<endl;
        cin.sync(); cin.clear();
        cin>>n;
        switch (n) {
            case 1:
                cin.sync(); cin.clear();
                cout<<"Podaj liczbe"<<endl;
                cin>>liczba;
                dodajNaKoniec(new listaElement(liczba));
                break;
            case 2:
                pokaz();
                break;
            case 4:
                cin.sync(); cin.clear();
                cout<<"Podaj liczbe"<<endl;
                cin>>liczba;
                dodajNaPoczatek(new listaElement(liczba));
                break;
            case 5:
                cin.sync(); cin.clear();
                cout<<"Podaj liczbe"<<endl;
                cin>>liczba;
                cout<<"Podaj indeks"<<endl;
                cin>>n;
                dodajWDowolnymMiejscu(n,new listaElement(liczba));
                break;
            case 6:
                cin.sync(); cin.clear();
                usunZKonca();
                break;
            case 7:
                cin.sync(); cin.clear();
                usunZPoczatku();
                break;
            case 8:
                cin.sync(); cin.clear();
                cout<<"Podaj indeks"<<endl;
                cin>>n;
                usunZDowolnegoMiejsca(n);
                break;
            case 3:
                cin.sync(); cin.clear();
                cout<<"Podaj indeks"<<endl;
                cin>>n;
                wyszukajElement(n);
                break;
            case 9:
                for(int i=0;i<rozmiar;i++) usunZKonca();
                exit(2137);
            case 10:
                cin.sync(); cin.clear();
                cout<<"Podaj nazwe pliku"<<endl;
                cin>>name;
                wczytaj(name);
                break;
            case 11:
                cin.sync(); cin.clear();
                cout<<"Podaj nazwe pliku"<<endl;
                cin>>name;
                zapisz(name);
                break;
        }
    }
}

