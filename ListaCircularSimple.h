/* 
 * File:   ListaCircularSimple.h
 * Author: sorem
 *
 * Created on 9 de junio de 2019, 01:26 AM
 */

#ifndef LISTACIRCULARSIMPLE_H
#define	LISTACIRCULARSIMPLE_H
#include "Nodo.h"
#include <iostream>

template <class T> class ListaCircularSimple {
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
template <class T> bool ListaCircularSimple<T>::isEmpty(){
    return inicio == NULL;
}
/**
 * 
 * @return 
 */
template <class T> int ListaCircularSimple<T>::getLargo(){
    return largo;
}
/**
 * 
 * @param dato
 */
template <class T> void ListaCircularSimple<T>::addLast(T dato){
    Nodo<T> *nuevo = new Nodo<T>(dato);
    if (isEmpty())
    {
        inicio = nuevo;
        inicio->siguiente = inicio;
        final = inicio;
        largo++;
    }
    else
    {
        final->siguiente = nuevo;
        nuevo->siguiente = inicio;
        final = nuevo;
        largo++;
    }
}
/**
 * 
 */
template <class T> void ListaCircularSimple<T>::print(){
    Nodo<T> *temp = inicio;
    do{
        std::cout<<temp->getDato()<<std::endl;
        temp = temp->siguiente;
    }while(temp!=inicio);
}

#endif	/* LISTACIRCULARSIMPLE_H */

