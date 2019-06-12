/* 
 * File:   ListaCircular.h
 * Author: sorem
 *
 * Created on 10 de junio de 2019, 01:45 PM
 */

#ifndef LISTADOBLE_H
#define	LISTADOBLE_H
#include "Nodo.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

template <class T> class ListaDoble{
    public:
        bool isEmpty();
        int getLargo();
        void addLast(T dato);
        bool find (T dato);
        void remove (T dato);
        T removeAt (int index);
        void print();
        string dot(const string& nombre, int contador);
    private:
        string recorrer(Nodo<T> *nodito);//, const string& nodo_anterior);
        Nodo<T> *inicio;
        Nodo<T> *final;
        int largo = 0;
};

template <class T> bool ListaDoble<T>::isEmpty(){
    return inicio==NULL;
}

template <class T> int ListaDoble<T>::getLargo(){
    return largo;
}

template <class T> void ListaDoble<T>::addLast(T dato){
    Nodo<T> *nuevo = new Nodo<T>(dato);
    //nuevo->setDato(dato);
    if(!isEmpty())
    {
        final->siguiente = nuevo;
        nuevo->anterior = final;
        final = nuevo;
        largo++;
    }
    else
    {
        inicio = nuevo;
        final = inicio;
        largo++;
    }
}

template <class T> bool ListaDoble<T>::find(T dato){
    Nodo<T> *temp = inicio;
    while(temp!=NULL){
        if(temp->getDato() == dato){
            return 1;
        }
        temp = temp->siguiente;
    }
    delete temp;
    return 0;
}

template <class T> void ListaDoble<T>::remove(T dato){
    Nodo<T> *temp = inicio;
    //Verifica si el primer nodo coincide con el dato dado
    if(temp->getDato() == dato){
        if(getLargo() > 1){
            inicio = temp->siguiente;
            temp->siguiente->anterior = NULL;
        } else {
            inicio = NULL;
        }
        largo--;
        delete temp;
        return;
    } 
    //El primer nodo no contiene el valor buscado
    while(temp!=NULL){
        if(temp->getDato() == dato){
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

template <class T> T ListaDoble<T>::removeAt(int index){
    Nodo<T> *temp = inicio;
    T dato;
    if(index == 0){
        dato = inicio->getDato();
        if(getLargo() > 1){
            inicio = temp->siguiente;
            temp->siguiente->anterior = NULL;
        } else {
            inicio = NULL;
        }
        largo--;
        delete temp;
        return dato;
    } 
    int contador = 0;
    while(contador != index){
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

template <class T> void ListaDoble<T>::print(){
    Nodo<T> *temp = inicio;
    while(temp!=NULL){
        std::cout<<temp->getDato()<<std::endl;
        temp = temp->siguiente;
    }
    delete temp;
}

template <class T> string ListaDoble<T>::dot(const string& nombre, int contador){
    stringstream retorno;
    retorno << "subgraph cluster" << contador << "{" << endl;
    retorno << "label = \"" << nombre << "\"" << endl;
    retorno << recorrer(inicio);
    retorno << "}" << endl;
    return retorno.str();
} 

template <class T> string ListaDoble<T>::recorrer(Nodo<T>* nodito){//, const string& nodo_anterior){
    stringstream retorno;
    if(nodito!=NULL){
        retorno << "p" << nodito << "[label=\"" << nodito->getDato() << "\"];" << endl;
        if (nodito->anterior!=NULL)
            retorno << "p" << nodito->anterior << "-> p" << nodito << endl;
        if (nodito->siguiente!=NULL)
            retorno << "p" << nodito->siguiente << "-> p" << nodito << endl;
        retorno << recorrer(nodito->siguiente);
    }
    return retorno.str();
}
#endif	/* LISTACIRCULAR_H */

