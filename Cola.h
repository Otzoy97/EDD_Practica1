/* 
 * File:   Cola.h
 * Author: sorem
 *
 * Created on 10 de junio de 2019, 01:46 PM
 */

#ifndef COLA_H
#define	COLA_H
#include "Nodo.h"
#include <iostream>

template <class T> class Cola{
    public:
        bool isEmpty();
        int getLargo();
        void encolar(T dato);
        T desencolar();
        void print();
    private:
        Nodo<T> *inicio;
        Nodo<T> *final;
        int largo = 0;
};

template <class T> bool Cola<T>::isEmpty(){
    return inicio==NULL;
}

template <class T> int Cola<T>::getLargo(){
    return largo;
}

template <class T> void Cola<T>::encolar(T dato){
    Nodo<T> *nuevo = new Nodo<T>(dato);
    if(!isEmpty()){
        final->siguiente = nuevo;
        final = nuevo;
        largo++;
    } else {
        inicio = nuevo;
        final = inicio;
        largo++;
    }
}

template <class T> T Cola<T>::desencolar(){
    T dato = inicio->getDato();
    Nodo<T> *temp = inicio;
    inicio = temp->siguiente;
    delete temp;
    largo--;
    return dato;
}

template <class T> void Cola<T>::print(){
    Nodo<T> *temp = inicio;
    while(temp!=NULL){
        std::cout<<temp->getDato()<<std::endl;
        temp = temp->siguiente;
    }
    delete temp;
}

#endif	/* COLA_H */

