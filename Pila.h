/* 
 * File:   Pila.h
 * Author: sorem
 *
 * Created on 10 de junio de 2019, 01:46 PM
 */

#ifndef PILA_H
#define	PILA_H
#include "Nodo.h"
#include <iostream>

template <class T> class Pila{
    public:
        bool isEmpty();
        int getLargo();
        void push(T dato);
        //bool find(T dato);
        T peek();
        T pop();
        //T removeAt(int index);
        void print();
    private:
        Nodo<T> *inicio;
        //Nodo<T> *final;
        int largo = 0;
};

template <class T> bool Pila<T>::isEmpty(){
    return inicio == NULL;
}

template <class T> int Pila<T>::getLargo(){
    return largo;
}

template <class T> void Pila<T>::push(T dato){
    Nodo<T> *nuevo = new Nodo<T>(dato);
    if(!isEmpty()){
        nuevo->siguiente = inicio;
        inicio = nuevo;
        largo++;
    } else {
        inicio = nuevo;
        largo++;
    }
}

template <class T> T Pila<T>::peek(){
    return inicio->getDato();
}

template <class T> T Pila<T>::pop(){
    T dato = inicio->getDato();
    Nodo<T> *temp = inicio;
    inicio = temp->siguiente;
    delete temp;
    largo--;
    return dato;
}

template <class T> void Pila<T>::print(){
    Nodo<T> *temp = inicio;
    while (temp!=NULL){
        std::cout<<temp->getDato()<<std::endl;
        temp = temp->siguiente;
    }
    delete temp;
}
#endif	/* PILA_H */

