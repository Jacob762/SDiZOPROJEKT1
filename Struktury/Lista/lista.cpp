//
// Created by Jakub Klawon on 08/03/2023.
//

#include "lista.h"
#include <iostream>

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
        cout<<temp->data<<endl;
        temp = temp -> nextEl;
    }
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