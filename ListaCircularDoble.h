/* 
 * File:   ListaCircularSimple.h
 * Author: sorem
 *
 * Created on 9 de junio de 2019, 01:26 AM
 */

#ifndef LISTACIRCULARDOBLE_H
#define	LISTACIRCULARDOBLE_H
#include "Nodo.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

template <class T> class ListaCircularDoble {
public:
    bool isEmpty();
    int getLargo();
    void addLast(T dato);
    bool find(T dato);
    void remove(T dato);
    T removeAt (int index);
    void print();
    string dot(const string& nombre, int contador);
private:
    //string recorrer(Nodo <T> *nodito);
    Nodo<T> *inicio;
    Nodo<T> *final;
    int largo = 0;
};

template <class T> bool ListaCircularDoble<T>::isEmpty(){
    return inicio == NULL;
}

template <class T> int ListaCircularDoble<T>::getLargo(){
    return largo;
}

template <class T> void ListaCircularDoble<T>::addLast(T dato){
    Nodo<T> *nuevo = new Nodo<T>(dato);
    //nuevo->setDato(dato);
    if (!isEmpty())
    {
        final->siguiente = nuevo;
        nuevo->anterior = final;
        nuevo->siguiente = inicio;
        inicio->anterior = nuevo;
        final = nuevo;
        largo++;
    }
    else
    {
        nuevo->siguiente = inicio;
        nuevo->anterior = final;
        inicio = nuevo;
        final = nuevo;
        largo++;
    }
}

template <class T> bool ListaCircularDoble<T>::find(T dato){
    Nodo<T> *temp = inicio;
    while(temp!=NULL){
        if(temp->getDato() == dato){
            return 1;
        }
    }
    delete temp;
    return 0;
}

template <class T> void ListaCircularDoble<T>::remove(T dato){
    Nodo<T> *temp = inicio;
    if(temp->getDato() == dato){
        if(getLargo()>1){
            inicio = temp->siguiente;
            temp->siguiente->anterior = NULL;
        } else {
            inicio=NULL;
        }
        largo--;
        delete temp;
        return;
    }
    while (temp!=NULL){
        if(temp->getDato()==dato){
            Nodo<T> *aux = temp->siguiente;
            temp->anterior->siguiente = aux;
            if(aux!=NULL)
                aux->anterior = temp->anterior;
            break;
        }
        temp = temp->siguiente;
    }
    largo--;
    delete temp;
    return;
}

template <class T> T ListaCircularDoble<T>::removeAt(int index){
    Nodo<T> *temp = inicio;
    T dato;
    if(index==0){
        dato = inicio->getDato();
        if(getLargo() > 1){
            inicio = temp->siguiente;
            temp->siguiente->anterior = NULL;
        } else {
            inicio =NULL;
        }
        largo--;
        delete temp;
        return dato;
    }
    int contador = 0;
    while(contador!=index){
        temp = temp->siguiente;
        contador++;
    }
    Nodo<T> *aux = temp->siguiente;
    temp->anterior->siguiente = aux;
    if(aux!=NULL)
        aux->anterior = temp->anterior;
    largo--;
    dato = temp->getDato();
    delete temp;
    return dato;
}

template <class T> void ListaCircularDoble<T>::print(){
    Nodo<T> *temp = inicio;
    do{
        cout<<temp->getDato()<<endl;
        temp = temp->siguiente;
    }while(temp!=inicio);
    delete temp;
}

template <class T> string ListaCircularDoble<T>::dot(const string& nombre, int contador){
    stringstream retorno;
    Nodo<T> *temp = inicio;
    retorno << "subgraph cluster" << contador << "{" << endl << "label = \"" << nombre << "\"" << endl;
    do{
        retorno << "p" << temp << "[label= \"" << temp->getDato() << "\"];" << endl;
        
        if (temp->siguiente!=NULL)
            retorno << "p" << temp->siguiente << "-> p" << temp << endl;
        if (temp->anterior!=NULL)
            retorno << "p" << temp->anterior << "-> p" << temp << endl;
        temp = temp->siguiente;
    } while (temp!=inicio);  
    retorno << "}" << endl;
    return retorno.str();
}
#endif	/* LISTACIRCULARSIMPLE_H */

