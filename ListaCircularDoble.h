/* 
 * File:   ListaCircularSimple.h
 * Author: sorem
 *
 * Created on 9 de junio de 2019, 01:26 AM
 */

#ifndef LISTACIRCULARDOBLE_H
#define	LISTACIRCULARDOBLE_H
#include "Nodo.h"
#include <iostream>

template <class T> class ListaCircularDoble {
public:
    bool isEmpty();
    int getLargo();
    void addLast(T dato);
    bool find(T dato);
    bool remove(T dato);
    void print();
    //AddFirst();
private:
    Nodo<T> *inicio;
    Nodo<T> *final;
    int largo = 0;
};
/**
 * 
 * @return 
 */
template <class T> bool ListaCircularDoble<T>::isEmpty(){
    return inicio == NULL;
}
/**
 * 
 * @return 
 */
template <class T> int ListaCircularDoble<T>::getLargo(){
    return largo;
}
/**
 * 
 * @param dato
 */
template <class T> void ListaCircularDoble<T>::addLast(T dato){
    Nodo<T> *nuevo = new Nodo<T>(dato);
    if (isEmpty())
    {
        nuevo->siguiente = inicio;
        nuevo->anterior = final;
        inicio = nuevo;
        final = nuevo;
        largo++;
    }
    else
    {
        final->siguiente = nuevo;
        nuevo->anterior = final;
        nuevo->siguiente = inicio;
        inicio->anterior = nuevo;
        final = nuevo;
        largo++;
    }
}
/**
 * 
 */
template <class T> void ListaCircularDoble<T>::print(){
    Nodo<T> *temp = inicio;
    do{
        std::cout<<temp->getDato()<<std::endl;
        temp = temp->siguiente;
    }while(temp!=inicio);
}

#endif	/* LISTACIRCULARSIMPLE_H */

